import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import WarehouseManagement

ColumnLayout {
    id: warehouseListRoot
    anchors.fill: parent
    spacing: 10

    signal warehouseSelected(var warehouse)

    Label {
        text: "📦 Склады"
        font.pixelSize: 20
        font.bold: true
    }

    ListView {
        id: warehouseListView
        Layout.fillWidth: true
        Layout.fillHeight: true
        model: warehouseManager.warehouses
        clip: true

        delegate: Rectangle {
            id: warehouseDelegate
            width: parent.width
            height: 120
            color: index % 2 ? "#f5f5f5" : "white"
            border.color: "#ddd"
            border.width: warehouseListView.currentIndex === index ? 2 : 1

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    warehouseListView.currentIndex = index
                    warehouseListRoot.warehouseSelected(model)
                }
            }

            Column {
                anchors.fill: parent
                anchors.margins: 10
                spacing: 5

                Text {
                    text: "ID: " + model.warehouseID
                    font.bold: true
                    font.pixelSize: 16
                }
                Text {
                    text: "Адрес: " + model.address
                    font.pixelSize: 14
                }
                Text {
                    text: "Вместимость: " + model.productCount + " / " + model.capacity
                    font.pixelSize: 14
                    color: model.productCount >= model.capacity ? "red" : "green"
                }



                Row {
                    spacing: 10
                    Button {
                        text: "➕ Добавить товар"
                        onClicked: {
                            addProductDialog.currentWarehouseID = model.warehouseID
                            addProductDialog.open()
                        }
                    }
                    Button {
                        text: "👁️ Товары"
                        onClicked: {
                            warehouseListRoot.warehouseSelected(model)
                            leftTabBar.currentIndex = 1
                        }
                    }
                }
            }
        }

        // Сообщение, если складов нет
        Text {
            visible: warehouseListView.count === 0
            text: "Склады не найдены"
            color: "#999"
            font.pixelSize: 16
            anchors.centerIn: parent
        }
    }

    // Диалог добавления товара
    Dialog {
        id: addProductDialog
        title: "Добавить товар на склад"
        modal: true
        standardButtons: Dialog.Ok | Dialog.Cancel
        anchors.centerIn: Overlay.overlay

        property string currentWarehouseID: ""

        ColumnLayout {
            width: 400
            spacing: 10

            Label {
                text: "Склад: " + currentWarehouseID
                font.bold: true
                Layout.fillWidth: true
            }

            TextField {
                id: productID
                placeholderText: "ID товара (например, P-001)"
                Layout.fillWidth: true
            }
            TextField {
                id: productName
                placeholderText: "Название товара"
                Layout.fillWidth: true
            }
            TextField {
                id: productCategory
                placeholderText: "Категория"
                Layout.fillWidth: true
            }
            TextField {
                id: productManufacturer
                placeholderText: "Производитель"
                Layout.fillWidth: true
            }

            RowLayout {
                TextField {
                    id: productQuantity
                    placeholderText: "Количество"
                    Layout.fillWidth: true
                    validator: IntValidator { bottom: 1; top: 9999 }
                }
                TextField {
                    id: productPrice
                    placeholderText: "Цена"
                    Layout.fillWidth: true
                    validator: DoubleValidator { bottom: 0; decimals: 2 }
                }
            }

            TextField {
                id: productExpiry
                placeholderText: "Срок годности (дд.мм.гггг)"
                text: Qt.formatDate(new Date(Date.now() + 90*24*60*60*1000), "dd.MM.yyyy")
                Layout.fillWidth: true
            }

            RowLayout {
                spacing: 20
                CheckBox {
                    id: isPromotional
                    text: "Акционный"
                    Layout.fillWidth: true
                }
                CheckBox {
                    id: isPerishable
                    text: "Скоропортящийся"
                    Layout.fillWidth: true
                }
            }
        }

        onAccepted: {
            if (!currentWarehouseID) {
                console.error("❌ Не выбран склад!")
                return
            }

            if (!productID.text.trim() || !productName.text.trim()) {
                console.error("❌ Заполните ID и название товара")
                return
            }

            let warehouse = warehouseManager.getWarehouse(currentWarehouseID)
            if (warehouse) {
                console.log("✅ Добавляем товар в склад:", currentWarehouseID)

                warehouse.addProductFromQML(
                    productID.text.trim(),
                                            productName.text.trim(),
                                            productCategory.text.trim(),
                                            productManufacturer.text.trim(),
                                            parseInt(productQuantity.text) || 1,
                                            parseFloat(productPrice.text.replace(',', '.')) || 0,
                                            productExpiry.text.trim(),
                                            isPromotional.checked,
                                            isPerishable.checked
                )

                // Очищаем поля
                productID.text = ""
                productName.text = ""
                productCategory.text = ""
                productManufacturer.text = ""
                productQuantity.text = "1"
                productPrice.text = "0"
                productExpiry.text = Qt.formatDate(new Date(Date.now() + 90*24*60*60*1000), "dd.MM.yyyy")
                isPromotional.checked = false
                isPerishable.checked = false
            }
        }
    }
}
