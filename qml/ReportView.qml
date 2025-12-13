// ReportView.qml — с currentWarehouse по аналогии с ProductList.qml
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Dialogs

ScrollView {
    //property var warehouseManager: WarehouseManager

    ColumnLayout {
        id: root
        anchors.fill: parent
        spacing: 10

        // Аналог currentWarehouse из ProductList
        property var currentWarehouse: null

        Label {
            text: "📊 Генерация отчетов"
            font.pixelSize: 24
            font.bold: true
            Layout.alignment: Qt.AlignHCenter
        }

        // Выбор склада — ТОЧНО как в ProductList.qml
        GroupBox {
            title: "Выберите склад:"
            Layout.fillWidth: true

            ComboBox {
                id: warehouseCombo
                Layout.fillWidth: true
                model: warehouseManager.warehouses
                textRole: "warehouseID"
                onCurrentIndexChanged: {
                    if (currentIndex >= 0) {
                        root.currentWarehouse = model[currentIndex];
                        console.log("Выбран склад:", root.currentWarehouse.warehouseID);
                        updateReportButtons();
                    } else {
                        root.currentWarehouse = null;
                        updateReportButtons();
                    }
                }
            }
        }

        // Кнопки отчетов
        GroupBox {
            title: "Тип отчета:"
            Layout.fillWidth: true

            GridLayout {
                columns: 2
                width: parent.width

                Button {
                    id: stockReportBtn
                    text: "📦 Отчет по запасам"
                    Layout.fillWidth: true
                    enabled: root.currentWarehouse !== null
                    onClicked: generateStockReport()
                }

                Button {
                    id: expiredReportBtn
                    text: "⚠️ Отчет по срокам"
                    Layout.fillWidth: true
                    enabled: root.currentWarehouse !== null
                    onClicked: generateExpiredReport()
                }
            }
        }

        // Отчет
        GroupBox {
            title: "Содержимое отчета:"
            Layout.fillWidth: true
            Layout.fillHeight: true

            TextArea {
                id: reportContent
                Layout.fillWidth: true
                Layout.fillHeight: true
                text: "Выберите склад и тип отчета для генерации..."
                readOnly: true
                wrapMode: Text.Wrap
                font.family: "Courier"
            }
        }

        // Только кнопка сохранения — без печати
        Button {
            id: saveReportBtn
            text: "💾 Сохранить как..."
            enabled: reportContent.text.length > 50
            Layout.fillWidth: true
            onClicked: saveReportDialog.open()
        }
    }

    FileDialog {
        id: saveReportDialog
        title: "Сохранить отчет"
        nameFilters: ["Текстовые файлы (*.txt)", "Все файлы (*)"]
        onAccepted: {
            console.log("Сохранить в:", saveReportDialog.currentFile);
            // TODO: реализация сохранения
        }
    }

    // Обновление состояния кнопок
    function updateReportDaysButtons() {
        // Устаревшая функция — не используется
    }

    function updateReportButtons() {
        var hasWarehouse = root.currentWarehouse !== null;
        stockReportBtn.enabled = hasWarehouse;
        expiredReportBtn.enabled = hasWarehouse;
        saveReportBtn.enabled = reportContent.text.length > 50;
    }

    function generateStockReport() {
        if (!root.currentWarehouse) return;
        var report = warehouseManager.generateStockReport(root.currentWarehouse, "stock_" + Date.now());
        displayReport(report);
    }

    function generateExpiredReport() {
        if (!root.currentWarehouse) return;
        var report = warehouseManager.generateExpiredReport(root.currentWarehouse, "expired_" + Date.now());
        displayReport(report);
    }

    function displayReport(report) {
        if (!report) {
            reportContent.text = "❌ Ошибка генерации отчета.";
            return;
        }

        var content = "=== ОТЧЕТ ===\n";
        content += "ID: " + report.reportID + "\n";
        content += "Тип: " + report.reportType + "\n";
        content += "Дата: " + report.creationDate.toLocaleDateString(Qt.locale("ru_RU")) + "\n";
        content += "================================\n\n";

        var data = report.data;
        for (var key in data) {
            content += key + ": " + data[key] + "\n";
        }

        reportContent.text = content;
        updateReportButtons(); // обновить кнопку "Сохранить"
    }

    // Автовыбор первого склада — как в ProductList.qml
    Component.onCompleted: {
        if (warehouseManager.warehouses.length > 0) {
            // Небольшая задержка, если модель асинхронная
            Qt.callLater(function() {
                warehouseCombo.currentIndex = 0;
            });
        }
    }
}
