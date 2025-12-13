import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    id: datePicker
    width: 300
    height: 300

    property date selectedDate: new Date()

    signal dateSelected(date date)

    ColumnLayout {
        anchors.fill: parent

        RowLayout {
            Layout.fillWidth: true

            Button {
                text: "◀"
                onClicked: changeMonth(-1)
            }

            Label {
                text: Qt.formatDate(selectedDate, "MMMM yyyy")
                font.bold: true
                Layout.fillWidth: true
                horizontalAlignment: Text.AlignHCenter
            }

            Button {
                text: "▶"
                onClicked: changeMonth(1)
            }
        }

        GridLayout {
            columns: 7
            Layout.fillWidth: true
            Layout.fillHeight: true

            // Дни недели
            Repeater {
                model: ["Пн", "Вт", "Ср", "Чт", "Пт", "Сб", "Вс"]

                Label {
                    text: modelData
                    font.bold: true
                    horizontalAlignment: Text.AlignHCenter
                    Layout.fillWidth: true
                }
            }

            // Дни месяца
            Repeater {
                model: getDaysInMonth()

                Rectangle {
                    width: 30
                    height: 30
                    radius: 15
                    color: {
                        if (modelData.date.getDate() === selectedDate.getDate() &&
                            modelData.date.getMonth() === selectedDate.getMonth() &&
                            modelData.date.getFullYear() === selectedDate.getFullYear()) {
                            return "#2196F3"
                            } else if (modelData.isCurrentMonth) {
                                return "transparent"
                            } else {
                                return "#f0f0f0"
                            }
                    }

                    Label {
                        anchors.centerIn: parent
                        text: modelData.date.getDate()
                        color: {
                            if (modelData.date.getDate() === selectedDate.getDate() &&
                                modelData.date.getMonth() === selectedDate.getMonth() &&
                                modelData.date.getFullYear() === selectedDate.getFullYear()) {
                                return "white"
                                } else if (modelData.isCurrentMonth) {
                                    return "black"
                                } else {
                                    return "#999"
                                }
                        }
                    }

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            selectedDate = modelData.date
                            dateSelected(selectedDate)
                        }
                    }
                }
            }
        }
    }

    function changeMonth(offset) {
        var newDate = new Date(selectedDate)
        newDate.setMonth(newDate.getMonth() + offset)
        selectedDate = newDate
    }

    function getDaysInMonth() {
        var result = []
        var year = selectedDate.getFullYear()
        var month = selectedDate.getMonth()

        // Первый день месяца
        var firstDay = new Date(year, month, 1)
        // Последний день месяца
        var lastDay = new Date(year, month + 1, 0)

        // День недели первого дня (0 = воскресенье, 1 = понедельник, и т.д.)
        var firstDayOfWeek = firstDay.getDay()
        // Преобразуем к нашему формату (понедельник = 0)
        firstDayOfWeek = firstDayOfWeek === 0 ? 6 : firstDayOfWeek - 1

        // Добавляем пустые ячейки для дней предыдущего месяца
        for (var i = 0; i < firstDayOfWeek; i++) {
            var prevDate = new Date(firstDay)
            prevDate.setDate(prevDate.getDate() - (firstDayOfWeek - i))
            result.push({ date: prevDate, isCurrentMonth: false })
        }

        // Добавляем дни текущего месяца
        for (var day = 1; day <= lastDay.getDate(); day++) {
            var currentDate = new Date(year, month, day)
            result.push({ date: currentDate, isCurrentMonth: true })
        }

        // Добавляем пустые ячейки для дней следующего месяца
        var totalCells = 42 // 6 недель × 7 дней
        while (result.length < totalCells) {
            var nextDate = new Date(lastDay)
            nextDate.setDate(nextDate.getDate() + (result.length - lastDay.getDate() - firstDayOfWeek + 1))
            result.push({ date: nextDate, isCurrentMonth: false })
        }

        return result
    }
}
