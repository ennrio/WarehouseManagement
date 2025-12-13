// AddEmployeeForm.qml
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Popup {
    id: addEmployeePopup
    width: 400
    height: 500
    modal: true
    focus: true

    property var warehouseModel: []

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 20
        spacing: 15

        Label {
            text: "📝 Добавление сотрудника"
            font.pixelSize: 18
            font.bold: true
        }

        TextField {
            id: employeeIdField
            Layout.fillWidth: true
            placeholderText: "ID сотрудника (например, EMP-001)"
        }

        TextField {
            id: employeeNameField
            Layout.fillWidth: true
            placeholderText: "ФИО сотрудника"
        }

        ComboBox {
            id: positionComboBox
            Layout.fillWidth: true
            model: ["Кладовщик", "Менеджер склада", "Приемщик товара", "Бухгалтер"]
            placeholderText: "Должность"
        }

        TextField {
            id: contactField
            Layout.fillWidth: true
            placeholderText: "Контактная информация"
        }

        ComboBox {
            id: warehouseComboBox
            Layout.fillWidth: true
            model: warehouseModel
            textRole: "display"
            valueRole: "id"
            placeholderText: "Выберите склад"

            delegate: ItemDelegate {
                width: parent.width
                text: modelData ? (modelData.warehouseID + " - " + modelData.address) : ""
            }
        }

        RowLayout {
            Layout.fillWidth: true

            Button {
                text: "Добавить"
                Layout.fillWidth: true
                onClicked: {
                    if (employeeIdField.text && employeeNameField.text &&
                        positionComboBox.currentText && warehouseComboBox.currentValue) {

                        warehouseManager.addEmployee(
                            employeeIdField.text,
                            employeeNameField.text,
                            positionComboBox.currentText,
                            contactField.text,
                            warehouseComboBox.currentValue
                        );

                    addEmployeePopup.close();
                    employeeIdField.clear();
                    employeeNameField.clear();
                    contactField.clear();
                        }
                }
            }

            Button {
                text: "Отмена"
                Layout.fillWidth: true
                onClicked: addEmployeePopup.close()
            }
        }
    }
}
