import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ScrollView {
    id: root
    property var currentEmployee: null
    property var warehouseFilter: null

    ColumnLayout {
        anchors.fill: parent
        spacing: 10

        Label {
            text: currentEmployee ? "🔔 Уведомления: " + currentEmployee.name : "🔔 Выберите сотрудника"
            font.pixelSize: 18
            font.bold: true
        }

        // Панель выбора сотрудника
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
                }
            }
        }

        RowLayout {
            Layout.fillWidth: true
            visible: currentEmployee

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

        // Список уведомлений
        ListView {
            id: notificationsList
            Layout.fillWidth: true
            Layout.fillHeight: true
            model: currentEmployee ? currentEmployee.notifications : []
            spacing: 5
            clip: true

            delegate: Rectangle {
                width: notificationsList.width - 5
                height: notificationText.height + 20
                color: {
                    if (modelData.includes("поставка") || modelData.includes("supply")) {
                        return "#fff3cd";
                    } else if (modelData.includes("⚠️") || modelData.includes("низкий")) {
                        return "#f8d7da";
                    } else if (modelData.includes("✅") || modelData.includes("успешно")) {
                        return "#d4edda";
                    } else {
                        return "#e3f2fd";
                    }
                }
                border.color: {
                    if (modelData.includes("поставка") || modelData.includes("supply")) {
                        return "#ffc107";
                    } else if (modelData.includes("⚠️") || modelData.includes("низкий")) {
                        return "#dc3545";
                    } else if (modelData.includes("✅") || modelData.includes("успешно")) {
                        return "#28a745";
                    } else {
                        return "#2196f3";
                    }
                }
                radius: 5

                Text {
                    id: notificationText
                    anchors {
                        left: parent.left
                        right: parent.right
                        verticalCenter: parent.verticalCenter
                        margins: 10
                    }
                    text: modelData
                    wrapMode: Text.Wrap
                    font.pixelSize: 14
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        console.log("Уведомление:", modelData);
                    }
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

        // Информация о складе сотрудника
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

    // Инициализация
    Component.onCompleted: {
        if (warehouseManager.employees.length > 0) {
            employeeSelector.currentIndex = 0;
        }
    }
}
