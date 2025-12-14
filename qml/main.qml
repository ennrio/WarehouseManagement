import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import WarehouseManagement

ApplicationWindow {
    id: root
    visible: true
    width: 1200
    height: 800
    title: "Система Управления Складом (WMS)"

    // Свойства для обмена данными между компонентами
    property var selectedWarehouse: null

    Component.onCompleted: {
        // 1. Сначала создаём склады
        warehouseManager.addWarehouse("WH-001", "Санкт-Петербург, ул. Ленина 1", 100);
        warehouseManager.addWarehouse("WH-002", "Москва, ул. Тверская 5", 150);

        // 2. СНАЧАЛА создаём сотрудников — чтобы они получили все будущие уведомления
        warehouseManager.addEmployee("EMP-001", "Иванов И.И.", "Кладовщик", "ivanov@wh.ru", "WH-001");
        warehouseManager.addEmployee("EMP-002", "Петров П.П.", "Менеджер", "petrov@wh.ru", "WH-002");

        // 3. Потом поставщиков
        warehouseManager.addSupplier("SUP-001", "ООО Продукты", "sup1@mail.ru");
        warehouseManager.addSupplier("SUP-002", "ООО Электроника", "sup2@mail.ru");

        // 4. ТЕПЕРЬ добавляем товары — уведомления дойдут до уже существующих сотрудников
        var wh1 = warehouseManager.getWarehouse("WH-001");
        if (wh1) {
            console.log("Добавляем тестовые товары на WH-001...");
            wh1.addProductFromQML(
                "P-001", "Молоко", "Молочные продукты", "Вимм-Билль-Данн",
                50, 89.99, "31.12.2024", false, true
            );
            wh1.addProductFromQML(
                "P-002", "Хлеб", "Хлебобулочные изделия", "Хлебозавод №1",
                100, 45.50, "15.12.2024", true, false
            );
        }

        var wh2 = warehouseManager.getWarehouse("WH-002");
        if (wh2) {
            console.log("Добавляем тестовые товары на WH-002...");
            wh2.addProductFromQML(
                "P-003", "Смартфон", "Электроника", "Samsung",
                20, 29999.99, "31.12.2026", false, false
            );
        }

    }

    SplitView {
        anchors.fill: parent

        // ЛЕВАЯ ПАНЕЛЬ
        Pane {
            Layout.minimumWidth: 400
            Layout.fillWidth: true

            ColumnLayout {
                anchors.fill: parent

                TabBar {
                    id: leftTabBar
                    Layout.fillWidth: true

                    TabButton { text: "📦 Склады" }
                    TabButton { text: "📋 Товары" }
                    TabButton { text: "🚚 Поставки" }
                }

                StackLayout {
                    id: leftStack
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    currentIndex: leftTabBar.currentIndex

                    // ВКЛАДКА 1: СКЛАДЫ
                    WarehouseList {
                        id: warehouseListComponent
                        anchors.fill: parent

                        // ✅ УБЕРИТЕ ЭТУ СТРОКУ - сигнала нет
                        // onWarehouseSelected: {
                        //     root.selectedWarehouse = warehouse;
                        //     console.log("Склад выбран:", warehouse.warehouseID);
                        // }
                    }

                    // ВКЛАДКА 2: ТОВАРЫ
                    ProductList {
                        id: productListComponent
                        anchors.fill: parent
                        currentWarehouse: root.selectedWarehouse
                    }

                    // ВКЛАДКА 3: ПОСТАВКИ
                    SupplyList {
                        anchors.fill: parent
                    }
                }
            }
        }

        // ПРАВАЯ ПАНЕЛЬ
        Pane {
            Layout.minimumWidth: 400
            Layout.fillWidth: true

            ColumnLayout {
                anchors.fill: parent

                TabBar {
                    id: rightTabBar
                    Layout.fillWidth: true

                    TabButton { text: "📊 Отчеты" }
                    TabButton { text: "🔔 Уведомления" }
                }

                StackLayout {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    currentIndex: rightTabBar.currentIndex

                    Item {
                        ReportView {
                            anchors.fill: parent
                            // currentWarehouse: root.selectedWarehouse
                        }
                    }
                    Item {
                        NotificationPanel {
                            anchors.fill: parent
                        }
                    }
                }
            }
        }
    }
}
