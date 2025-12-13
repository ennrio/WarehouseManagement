import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ColumnLayout {
    id: root
    anchors.fill: parent
    spacing: 10

    property bool showAddForm: false
    property var selectedSupplier: null
    property var selectedWarehouse: null
    property string supplyDate: Qt.formatDate(new Date(), "dd.MM.yyyy")
    property string selectedSupplyID: ""

    // ListModel для товаров в поставке
    ListModel {
        id: productItemsModel
    }

    Label {
        text: "🚚 Управление поставками"
        font.pixelSize: 20
        font.bold: true
        Layout.alignment: Qt.AlignHCenter
    }

    // Кнопки управления
    RowLayout {
        Layout.fillWidth: true
        spacing: 10

        Button {
            text: "➕ Новая поставка"
            Layout.fillWidth: true
            visible: !showAddForm
            onClicked: {
                showAddForm = true
                productItemsModel.clear()
                supplyIDField.text = "SUP-" + Date.now()
                dateField.text = Qt.formatDate(new Date(), "dd.MM.yyyy")

                if (supplierCombo.count > 0) {
                    supplierCombo.currentIndex = 0
                    selectedSupplier = supplierCombo.model[0]
                }
            }
        }

        Button {
            text: "🔄 Обновить"
            visible: !showAddForm
            Layout.fillWidth: true
            onClicked: updateSupplyList()
        }
    }

    // === СТЕК ДЛЯ ПЕРЕКЛЮЧЕНИЯ МЕЖДУ ФОРМОЙ И СПИСКОМ ===
    StackLayout {
        id: mainStack
        Layout.fillWidth: true
        Layout.fillHeight: true
        currentIndex: showAddForm ? 1 : 0

        // СТРАНИЦА 0: Основной список поставок
        ColumnLayout {
            Layout.fillWidth: true
            Layout.fillHeight: true
            spacing: 0

            // Основной список поставок
            ListView {
                id: suppliesList
                Layout.fillWidth: true
                Layout.fillHeight: true
                clip: true
                model: warehouseManager.supplies || []

                delegate: Rectangle {
                    width: suppliesList.width
                    height: 120
                    color: index % 2 ? "#f8f8f8" : "white"
                    border.color: "#ddd"

                    Column {
                        anchors.fill: parent
                        anchors.margins: 10
                        spacing: 5

                        Row {
                            spacing: 10
                            width: parent.width

                            Text {
                                text: "📦 " + (modelData.supplyID || "N/A")
                                font.bold: true
                                font.pixelSize: 16
                            }

                            Text {
                                text: {
                                    if (modelData.status === "confirmed") return "✅ Подтверждена"
                                    if (modelData.status === "pending") return "⏳ Ожидает"
                                    return "❌ Отменена"
                                }
                                color: {
                                    if (modelData.status === "confirmed") return "green"
                                    if (modelData.status === "pending") return "orange"
                                    return "red"
                                }
                                font.pixelSize: 12
                            }
                        }

                        Row {
                            spacing: 15
                            Text {
                                text: "Поставщик: " + (modelData.supplierID || "N/A")
                                font.pixelSize: 12
                                color: "#666"
                            }
                            Text {
                                text: "Дата: " + (modelData.supplyDate ? Qt.formatDate(modelData.supplyDate, "dd.MM.yyyy") : "N/A")
                                font.pixelSize: 12
                                color: "#666"
                            }
                        }

                        Row {
                            spacing: 15
                            width: parent.width

                            Text {
                                text: "Товаров: " + (modelData.productCount ? modelData.productCount : 0)
                                font.pixelSize: 12
                                color: "#666"
                            }

                            Button {
                                text: "Подтвердить"
                                visible: modelData.status === "pending"
                                onClicked: {
                                    selectedSupplyID = modelData.supplyID
                                    confirmDialog.open()
                                }
                            }
                        }
                    }
                }

                Text {
                    visible: suppliesList.count === 0
                    text: "Нет поставок"
                    color: "#999"
                    anchors.centerIn: parent
                }
            }

            // Отладочная информация для списка
            Rectangle {
                Layout.fillWidth: true
                height: 30
                color: "#e8f5e9"
                border.color: "#4caf50"
                radius: 3

                Text {
                    anchors.centerIn: parent
                    text: "📊 Поставок: " + suppliesList.count
                    color: "green"
                    font.pixelSize: 12
                }
            }
        }

        // СТРАНИЦА 1: Форма добавления новой поставки
        ColumnLayout {
            Layout.fillWidth: true
            Layout.fillHeight: true
            spacing: 10

            // Заголовок формы
            RowLayout {
                Layout.fillWidth: true
                spacing: 10

                Button {
                    text: "← Назад к списку"
                    onClicked: showAddForm = false
                }

                Label {
                    text: "📝 Новая поставка"
                    font.pixelSize: 18
                    font.bold: true
                    Layout.fillWidth: true
                }
            }

            // ScrollView для формы
            ScrollView {
                Layout.fillWidth: true
                Layout.fillHeight: true
                clip: true

                ColumnLayout {
                    width: parent.width
                    spacing: 15

                    // Основная информация
                    GroupBox {
                        title: "📄 Основная информация"
                        Layout.fillWidth: true

                        ColumnLayout {
                            width: parent.width
                            spacing: 10

                            TextField {
                                id: supplyIDField
                                placeholderText: "ID поставки"
                                Layout.fillWidth: true
                            }

                            // Выбор поставщика
                            ComboBox {
                                id: supplierCombo
                                Layout.fillWidth: true
                                model: warehouseManager.suppliers || []
                                textRole: "companyName"

                                // Плейсхолдер, когда нет выбора
                                Text {
                                    text: "Выберите поставщика"
                                    color: "#aaa"
                                    visible: parent.displayText === ""
                                    anchors.fill: parent
                                    anchors.leftMargin: 8
                                    verticalAlignment: Text.AlignVCenter
                                    font: parent.font
                                }

                                onCurrentIndexChanged: {
                                    if (currentIndex >= 0 && model) {
                                        selectedSupplier = model[currentIndex]
                                        console.log("Выбран поставщик:", selectedSupplier.companyName)
                                    } else {
                                        selectedSupplier = null
                                    }
                                }
                            }

                            // Дата поставки
                            RowLayout {
                                Layout.fillWidth: true

                                Label {
                                    text: "Дата:"
                                }

                                TextField {
                                    id: dateField
                                    Layout.fillWidth: true
                                    text: supplyDate
                                    placeholderText: "дд.мм.гггг"
                                }
                            }
                        }
                    }

                    // Список товаров в поставке
                    GroupBox {
                        title: "🛒 Товары в поставке (" + productItemsModel.count + ")"
                        Layout.fillWidth: true

                        ColumnLayout {
                            width: parent.width
                            spacing: 10

                            // ScrollView для списка товаров с фиксированной высотой
                            ScrollView {
                                Layout.fillWidth: true
                                Layout.preferredHeight: Math.min(200, productItemsModel.count * 40 + 40)
                                clip: true

                                ListView {
                                    id: productListView
                                    width: parent.width
                                    height: contentHeight
                                    model: productItemsModel
                                    clip: true
                                    spacing: 5

                                    delegate: Rectangle {
                                        width: productListView.width
                                        height: 35
                                        color: index % 2 ? "#f9f9f9" : "white"
                                        radius: 3
                                        border.color: "#eee"

                                        RowLayout {
                                            anchors.fill: parent
                                            anchors.margins: 5
                                            spacing: 10

                                            Text {
                                                text: name
                                                Layout.fillWidth: true
                                                elide: Text.ElideRight
                                                font.pixelSize: 12
                                            }

                                            Text {
                                                text: "× " + quantity
                                                font.pixelSize: 11
                                                color: "#666"
                                                Layout.minimumWidth: 40
                                            }

                                            Text {
                                                text: price.toFixed(2) + " ₽"
                                                font.pixelSize: 11
                                                color: "#2196F3"
                                                font.bold: true
                                                Layout.minimumWidth: 60
                                            }

                                            // Иконки свойств товара
                                            Row {
                                                spacing: 3
                                                Layout.alignment: Qt.AlignHCenter

                                                Rectangle {
                                                    width: 18
                                                    height: 18
                                                    radius: 2
                                                    color: isPromotional ? "#4CAF50" : "transparent"
                                                    border.color: "#4CAF50"
                                                    visible: isPromotional

                                                    Text {
                                                        anchors.centerIn: parent
                                                        text: "А"
                                                        color: isPromotional ? "white" : "#4CAF50"
                                                        font.bold: true
                                                        font.pixelSize: 9
                                                    }
                                                }

                                                Rectangle {
                                                    width: 18
                                                    height: 18
                                                    radius: 2
                                                    color: isPerishable ? "#FF9800" : "transparent"
                                                    border.color: "#FF9800"
                                                    visible: isPerishable

                                                    Text {
                                                        anchors.centerIn: parent
                                                        text: "С"
                                                        color: isPerishable ? "white" : "#FF9800"
                                                        font.bold: true
                                                        font.pixelSize: 9
                                                    }
                                                }
                                            }

                                            Button {
                                                text: "✕"
                                                width: 30
                                                height: 25
                                                font.pixelSize: 10
                                                onClicked: productItemsModel.remove(index)
                                            }
                                        }
                                    }

                                    // Сообщение, если нет товаров
                                    Text {
                                        visible: productItemsModel.count === 0
                                        text: "Нет товаров. Нажмите кнопку ниже, чтобы добавить"
                                        color: "#999"
                                        anchors.centerIn: parent
                                    }
                                }
                            }

                            // Кнопка добавления товара (всегда видна под списком)
                            Button {
                                text: "+ Добавить товар"
                                Layout.fillWidth: true
                                onClicked: {
                                    console.log("Открытие диалога добавления товара")
                                    addProductDialog.open()
                                }
                            }
                        }
                    }
                }
            }

            // Кнопки действий (фиксированные внизу)
            ColumnLayout {
                Layout.fillWidth: true
                spacing: 10

                // Отладочная информация для формы
                Rectangle {
                    Layout.fillWidth: true
                    height: 30
                    color: "#e8f5e9"
                    border.color: "#4caf50"
                    radius: 3

                    Text {
                        anchors.centerIn: parent
                        text: "📝 Создание новой поставки (товаров: " + productItemsModel.count + ")"
                        color: "green"
                        font.pixelSize: 12
                    }
                }

                RowLayout {
                    Layout.fillWidth: true
                    spacing: 10

                    Button {
                        text: "Отмена"
                        Layout.fillWidth: true
                        onClicked: showAddForm = false
                    }

                    Button {
                        id: createSupplyButton
                        text: "Создать поставку"
                        Layout.fillWidth: true
                        enabled: supplyIDField.text && selectedSupplier && productItemsModel.count > 0

                        ToolTip.visible: hovered && !enabled
                        ToolTip.text: {
                            if (!supplyIDField.text) return "Введите ID поставки"
                            if (!selectedSupplier) return "Выберите поставщика"
                            if (productItemsModel.count === 0) return "Добавьте хотя бы один товар"
                            return "Готово к созданию"
                        }

                        onClicked: createSupply()
                    }
                }
            }
        }
    }

    // Диалог подтверждения поставки
    Dialog {
        id: confirmDialog
        title: "Подтверждение поставки"
        modal: true
        standardButtons: Dialog.Ok | Dialog.Cancel
        anchors.centerIn: Overlay.overlay

        width: 350

        ColumnLayout {
            anchors.fill: parent
            spacing: 15
            anchors.margins: 10

            Label {
                text: "Выберите склад для размещения товаров:"
                font.pixelSize: 14
                Layout.fillWidth: true
            }

            ComboBox {
                id: warehouseCombo
                Layout.fillWidth: true
                model: warehouseManager.warehouses
                textRole: "warehouseID"

                // Плейсхолдер
                Text {
                    text: "Выберите склад"
                    color: "#aaa"
                    visible: parent.displayText === ""
                    anchors.fill: parent
                    anchors.leftMargin: 8
                    verticalAlignment: Text.AlignVCenter
                    font: parent.font
                }

                onCurrentIndexChanged: {
                    if (currentIndex >= 0) {
                        selectedWarehouse = model[currentIndex]
                    }
                }
            }
        }

        onOpened: {
            // Сбрасываем выбор при открытии
            warehouseCombo.currentIndex = -1
            selectedWarehouse = null

            if (warehouseCombo.count > 0) {
                warehouseCombo.currentIndex = 0
                selectedWarehouse = warehouseCombo.model[0]
            }
        }

        onAccepted: {
            if (selectedWarehouse && selectedSupplyID) {
                warehouseManager.confirmSupply(selectedSupplyID, selectedWarehouse.warehouseID)
                updateSupplyList()
            }
        }
    }

    // Диалог добавления товара
    Dialog {
        id: addProductDialog
        title: "Добавить товар в поставку"
        modal: true
        standardButtons: Dialog.Ok | Dialog.Cancel
        anchors.centerIn: Overlay.overlay

        // Свойства для полей формы
        property string productID: ""
        property string productName: ""
        property string productCategory: ""
        property string productManufacturer: ""
        property int productQuantity: 1
        property double productPrice: 0.0
        property string productExpiry: Qt.formatDate(new Date(Date.now() + 90*24*60*60*1000), "dd.MM.yyyy")
        property bool isPromotional: false
        property bool isPerishable: false

        onOpened: {
            productIDField.text = ""
            productNameField.text = ""
            productCategoryField.text = ""
            productManufacturerField.text = ""
            productQuantityField.text = "1"
            productPriceField.text = "0.0"
            productExpiryField.text = Qt.formatDate(new Date(Date.now() + 90*24*60*60*1000), "dd.MM.yyyy")
            isPromotionalCheckBox.checked = false
            isPerishableCheckBox.checked = false
        }

        ColumnLayout {
            width: 400
            spacing: 10

            TextField {
                id: productIDField
                placeholderText: "ID товара (например, P-001)"
                Layout.fillWidth: true
                onTextChanged: addProductDialog.productID = text
            }

            TextField {
                id: productNameField
                placeholderText: "Название товара"
                Layout.fillWidth: true
                onTextChanged: addProductDialog.productName = text
            }

            TextField {
                id: productCategoryField
                placeholderText: "Категория"
                Layout.fillWidth: true
                onTextChanged: addProductDialog.productCategory = text
            }

            TextField {
                id: productManufacturerField
                placeholderText: "Производитель"
                Layout.fillWidth: true
                onTextChanged: addProductDialog.productManufacturer = text
            }

            RowLayout {
                spacing: 10

                TextField {
                    id: productQuantityField
                    placeholderText: "Количество"
                    Layout.fillWidth: true
                    validator: IntValidator { bottom: 1; top: 9999 }
                    text: "1"
                    onTextChanged: {
                        if (text) addProductDialog.productQuantity = parseInt(text)
                    }
                }

                TextField {
                    id: productPriceField
                    placeholderText: "Цена"
                    Layout.fillWidth: true
                    validator: DoubleValidator { bottom: 0; decimals: 2 }
                    text: "0.0"
                    onTextChanged: {
                        if (text) addProductDialog.productPrice = parseFloat(text.replace(',', '.'))
                    }
                }
            }

            TextField {
                id: productExpiryField
                placeholderText: "Срок годности (дд.мм.гггг)"
                text: Qt.formatDate(new Date(Date.now() + 90*24*60*60*1000), "dd.MM.yyyy")
                Layout.fillWidth: true
                onTextChanged: addProductDialog.productExpiry = text
            }

            RowLayout {
                spacing: 20

                CheckBox {
                    id: isPromotionalCheckBox
                    text: "Акционный"
                    Layout.fillWidth: true
                    onCheckedChanged: addProductDialog.isPromotional = checked
                }

                CheckBox {
                    id: isPerishableCheckBox
                    text: "Скоропортящийся"
                    Layout.fillWidth: true
                    onCheckedChanged: addProductDialog.isPerishable = checked
                }
            }
        }

        onAccepted: {
            console.log("Добавление товара в поставку...")

            var id = productIDField.text.trim()
            if (!id) {
                id = "PROD-" + Date.now() + "-" + Math.floor(Math.random() * 1000)
            }

            var name = productNameField.text.trim() || "Товар " + id
            var quantity = parseInt(productQuantityField.text) || 1
            var price = parseFloat(productPriceField.text.replace(',', '.')) || 0.0

            productItemsModel.append({
                "id": id,
                "name": name,
                "category": productCategoryField.text.trim() || "Общая",
                "manufacturer": productManufacturerField.text.trim() || "Неизвестно",
                "quantity": quantity,
                "price": price,
                "expiryDate": productExpiryField.text.trim(),
                "isPromotional": isPromotionalCheckBox.checked,
                "isPerishable": isPerishableCheckBox.checked
            })

            console.log("Всего товаров в поставке:", productItemsModel.count)
            createSupplyButton.enabled = supplyIDField.text && selectedSupplier && productItemsModel.count > 0
        }
    }

    // Функции
    function updateSupplyList() {
        console.log("Обновление списка поставок")
        suppliesList.model = warehouseManager.supplies || []
        console.log("Количество поставок:", suppliesList.count)
    }

    function createSupply() {
        console.log("=== СОЗДАНИЕ ПОСТАВКИ ===")

        if (!supplyIDField.text) {
            console.error("ОШИБКА: Введите ID поставки!")
            return
        }

        if (!selectedSupplier) {
            console.error("ОШИБКА: Выберите поставщика!")
            return
        }

        if (productItemsModel.count === 0) {
            console.error("ОШИБКА: Добавьте хотя бы один товар!")
            return
        }

        var productsArray = []
        for (var i = 0; i < productItemsModel.count; i++) {
            var item = productItemsModel.get(i)
            productsArray.push({
                "id": item.id,
                "name": item.name,
                "category": item.category,
                "manufacturer": item.manufacturer,
                "quantity": item.quantity,
                "price": item.price,
                "expiryDate": item.expiryDate,
                "isPromotional": item.isPromotional,
                "isPerishable": item.isPerishable
            })
        }

        warehouseManager.createSupply(
            supplyIDField.text,
            selectedSupplier.supplierID,
            dateField.text || supplyDate,
            productsArray
        )

        showAddForm = false
        supplyIDField.text = ""
        selectedSupplier = null
        productItemsModel.clear()
        setTimeout(updateSupplyList, 300)
    }

    Component.onCompleted: {
        console.log("SupplyList загружен")
        updateSupplyList()
        if (warehouseManager && warehouseManager.suppliers) {
            console.log("Поставщики загружены:", warehouseManager.suppliers.length)
        }
    }

    Connections {
        target: warehouseManager

        function onSuppliesChanged() {
            console.log("Сигнал suppliesChanged получен!")
            updateSupplyList()
        }

        function onSuppliersChanged() {
            console.log("Сигнал suppliersChanged получен!")
            supplierCombo.model = warehouseManager.suppliers || []
            console.log("Обновлено количество поставщиков:", supplierCombo.count)
        }

        function onNotification(message) {
            console.log("Уведомление:", message)
        }
    }
}
