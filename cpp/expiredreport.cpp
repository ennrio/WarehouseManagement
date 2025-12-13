#include "expiredreport.h"

ExpiredReport::ExpiredReport(const QString& id, Warehouse* warehouse, QObject* parent)
: Report(id, "ExpiredReport", parent), m_warehouse(warehouse) {}

void ExpiredReport::generate() {
    m_data.clear();
    m_data["warehouseID"] = m_warehouse->getWarehouseID();

    QStringList expiredList;
    QStringList nearExpiryList;
    QDate currentDate = QDate::currentDate();

    for (auto product : m_warehouse->getAllProducts()) {
        QDate expDate = product->getExpirationDate();
        if (expDate < currentDate) {
            expiredList.append(QString("%1 (истек: %2)")
            .arg(product->getName(), expDate.toString("dd.MM.yyyy")));
        } else if (expDate <= currentDate.addDays(3)) {
            nearExpiryList.append(QString("%1 (истекает: %2)")
            .arg(product->getName(), expDate.toString("dd.MM.yyyy")));
        }
    }

    m_data["expiredProducts"] = expiredList.join("; ");
    m_data["nearExpiryCount"] = nearExpiryList.size();
    m_data["nearExpiryList"] = nearExpiryList.join("; ");

    emit dataChanged();
}
