import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import WarehouseManagement

ColumnLayout {
    id: root
    anchors.fill: parent
    spacing: 10

    property var currentWarehouse: null

    Label {
        text: "📋 Товары на складе"
        font.pixelSize: 20
        font.bold: true
    }

    // Выбор склада
    ComboBox {
        id: warehouseCombo
        Layout.fillWidth: true
        model: warehouseManager.warehouses
        textRole: "warehouseID"
        onCurrentIndexChanged: {
            if (currentIndex >= 0) {
                root.currentWarehouse = model[currentIndex];
                console.log("Выбран склад:", root.currentWarehouse.warehouseID);
                updateProductList();
            }
        }
    }

    // Только кнопка обновления
    Button {
        text: "🔄 Обновить"
        Layout.fillWidth: true
        onClicked: updateProductList()
    }

    // Список товаров
    ListView {
        id: productListView
        Layout.fillWidth: true
        Layout.fillHeight: true
        clip: true
        spacing: 5  // Добавил отступы между элементами

        model: []  // Начинаем с пустого массива

        delegate: Rectangle {
            width: productListView.width - 5  // Уменьшил ширину для отступов
            height: 120  // Увеличил высоту для всех данных
            color: index % 2 ? "#f8f8f8" : "white"
            border.color: "#ddd"

            Column {
                anchors.fill: parent
                anchors.margins: 10
                spacing: 5

                Text {
                    text: "📦 " + (modelData.name || "Без названия")
                    font.bold: true
                    font.pixelSize: 16
                }

                Row {
                    spacing: 15
                    Text {
                        text: "ID: " + (modelData.id || "N/A")
                        color: "green"
                        font.pixelSize: 12
                    }
                    Text {
                        text: "Кол-во: " + (modelData.quantity || 0)
                        font.pixelSize: 12
                        color: modelData.quantity < 10 ? "red" : "black"
                    }
                    Text {
                        text: "Цена: " + (modelData.price || 0).toFixed(2) + "₽"
                        font.pixelSize: 12
                    }
                }

                Row {
                    spacing: 15
                    Text {
                        text: "Категория: " + (modelData.category || "Не указана")
                        font.pixelSize: 11
                        color: "#666"
                    }
                    Text {
                        text: "Производитель: " + (modelData.manufacturer || "Не указан")
                        font.pixelSize: 11
                        color: "#666"
                    }
                }

                // Добавил строку для дополнительных свойств
                Row {
                    spacing: 15
                    visible: modelData.isPromotional || modelData.isPerishable
                    Text {
                        text: modelData.isPromotional ? "🎯 Акционный" : ""
                        font.pixelSize: 11
                        color: "#E91E63"
                    }
                    Text {
                        text: modelData.isPerishable ? "🥶 Скоропортящийся" : ""
                        font.pixelSize: 11
                        color: "#2196F3"
                    }
                }

                // Добавил срок годности
                Text {
                    visible: modelData.expiryDate
                    text: "Срок годности: " + (modelData.expiryDate || "")
                    font.pixelSize: 11
                    color: "#666"
                }
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    console.log("Товар:", modelData);
                }
            }
        }

        Text {
            visible: productListView.count === 0 && root.currentWarehouse
            text: "На складе нет товаров"
            color: "#999"
            anchors.centerIn: parent
        }
    }

    // Отладочная информация
    Rectangle {
        Layout.fillWidth: true
        height: 30
        color: "#e8f5e9"
        border.color: "#4caf50"
        radius: 3

        Text {
            anchors.centerIn: parent
            text: {
                if (!root.currentWarehouse) return "👉 Выберите склад";
                return "📊 Товаров: " + productListView.count;
            }
            color: "green"
            font.pixelSize: 12
        }
    }

    // Функция обновления списка
    function updateProductList() {
        if (root.currentWarehouse) {
            console.log("Обновление списка для склада:", root.currentWarehouse.warehouseID);
            var products = root.currentWarehouse.getProductsSimple();
            console.log("Получено товаров:", products.length);

            // Проверяем, что у нас есть все необходимые поля
            if (products.length > 0) {
                console.log("Первый товар:", JSON.stringify(products[0]));
            }

            productListView.model = products;
        } else {
            productListView.model = [];
        }
    }

    // Инициализация
    Component.onCompleted: {
        console.log("ProductList загружен");

        // Автовыбор первого склада
        setTimeout(function() {
            if (warehouseManager.warehouses.length > 0) {
                warehouseCombo.currentIndex = 0;
            }
        }, 100);
    }

    // Подписываемся на сигнал об изменении товаров
    Connections {
        target: root.currentWarehouse
        enabled: root.currentWarehouse !== null
        function onProductsChanged() {
            console.log("Сигнал productsChanged получен!");
            updateProductList();
        }
    }
}
