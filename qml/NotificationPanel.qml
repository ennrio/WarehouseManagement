// NotificationPanel.qml
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ScrollView {
    id: root
    property var currentEmployee: null

    // Горизонтальное разделение: уведомления | добавление склада
    RowLayout {
        anchors.fill: parent
        spacing: 20

        // ==== ЛЕВАЯ ПАНЕЛЬ: Уведомления
        ColumnLayout {
            Layout.fillHeight: true
            Layout.preferredWidth: 400  // Фиксированная ширина для уведомлений
            spacing: 10

            Label {
                text: currentEmployee ? "🔔 Уведомления: " + currentEmployee.name : "🔔 Выберите сотрудника"
                font.pixelSize: 18
                font.bold: true
            }

            ComboBox {
                id: employeeSelector
                Layout.fillWidth: true
                model: warehouseManager.employees
                textRole: "name"

                delegate: ItemDelegate {
                    width: parent.width
                    text: modelData.name + " (" + modelData.position + ")" +
                          (modelData.warehouseID ? " - Склад " + modelData.warehouseID : "")
                }

                onCurrentIndexChanged: {
                    if (currentIndex >= 0) {
                        root.currentEmployee = model[currentIndex];
                        console.log("Сотрудник выбран:", root.currentEmployee.name, "уведомлений:", root.currentEmployee.notifications.length);
                    } else {
                        root.currentEmployee = null;
                    }
                }
            }

            RowLayout {
                Layout.fillWidth: true
                visible: currentEmployee !== null

                Button {
                    text: "🗑️ Очистить"
                    Layout.fillWidth: true
                    onClicked: {
                        if (currentEmployee) {
                            currentEmployee.clearNotifications();
                        }
                    }
                }

                Button {
                    text: "📋 Все уведомления"
                    Layout.fillWidth: true
                    onClicked: {
                        // Показывать все уведомления
                    }
                }
            }

            ListView {
                id: notificationsList
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.minimumHeight: 120
                model: currentEmployee ? currentEmployee.notifications : []
                spacing: 5
                clip: true

                delegate: Rectangle {
                    width: notificationsList.width - 2 * notificationsList.spacing
                    implicitHeight: notificationText.implicitHeight + 20
                    color: {
                        if (modelData.includes("поставка") || modelData.includes("supply")) return "#fff3cd";
                        if (modelData.includes("⚠️") || modelData.includes("низкий") || modelData.includes("просрочка")) return "#f8d7da";
                        if (modelData.includes("✅") || modelData.includes("успешно")) return "#d4edda";
                        return "#e3f2fd";
                    }
                    border.color: {
                        if (modelData.includes("поставка") || modelData.includes("supply")) return "#ffc107";
                        if (modelData.includes("⚠️") || modelData.includes("низкий") || modelData.includes("просрочка")) return "#dc3545";
                        if (modelData.includes("✅") || modelData.includes("успешно")) return "#28a745";
                        return "#2196f3";
                    }
                    radius: 5

                    Text {
                        id: notificationText
                        anchors {
                            left: parent.left; right: parent.right
                            verticalCenter: parent.verticalCenter
                            margins: 10
                        }
                        text: modelData
                        wrapMode: Text.Wrap
                        font.pixelSize: 14
                        width: parent.width - 20
                    }

                    MouseArea {
                        anchors.fill: parent
                        onClicked: console.log("Уведомление:", modelData);
                    }
                }

                Text {
                    anchors.centerIn: parent
                    text: "Нет уведомлений"
                    visible: notificationsList.count === 0 && currentEmployee
                    font.pixelSize: 16
                    color: "#666"
                }
            }

            Rectangle {
                Layout.fillWidth: true
                height: 30
                visible: currentEmployee && currentEmployee.warehouseID
                color: "#e8f5e9"
                border.color: "#4caf50"
                radius: 3

                Text {
                    anchors.centerIn: parent
                    text: "🏢 Склад: " + currentEmployee.warehouseID
                    color: "green"
                    font.pixelSize: 12
                }
            }
        }

        // ==== ПРАВАЯ ПАНЕЛЬ: Добавление склада ====
        ColumnLayout {
            Layout.fillHeight: true
            Layout.preferredWidth: 300
            spacing: 15

            Label {
                text: "➕ Добавить склад"
                font.pixelSize: 18
                font.bold: true
            }

            TextField {
                id: warehouseIdField
                Layout.fillWidth: true
                placeholderText: "ID склада (например, WH-003)"
            }

            TextField {
                id: addressField
                Layout.fillWidth: true
                placeholderText: "Адрес склада"
            }

            TextField {
                id: capacityField
                Layout.fillWidth: true
                placeholderText: "Вместимость (целое число)"
                inputMethodHints: Qt.ImhDigitsOnly
            }

            Button {
                text: "✅ Добавить склад"
                Layout.fillWidth: true
                onClicked: {
                    let id = warehouseIdField.text.trim();
                    let addr = addressField.text.trim();
                    let cap = parseInt(capacityField.text);

                    if (!id || !addr || isNaN(cap) || cap <= 0) {
                        console.log("Ошибка: заполните все поля корректно");
                        // Можно показать Popup с ошибкой
                        return;
                    }

                    // Вызов метода в C++
                    if (warehouseManager.addWarehouse) {
                        warehouseManager.addWarehouse(id, addr, cap);
                        console.log("Склад добавлен:", id);
                        // Очистить поля
                        warehouseIdField.text = "";
                        addressField.text = "";
                        capacityField.text = "";
                    } else {
                        console.error("Метод addWarehouse не найден в warehouseManager!");
                    }
                }
            }


        }
    }

    Component.onCompleted: {
        if (warehouseManager.employees.length > 0) {
            employeeSelector.currentIndex = 0;
        }
    }
}
