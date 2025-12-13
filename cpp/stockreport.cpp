#include "stockreport.h"

StockReport::StockReport(const QString& id, Warehouse* warehouse, QObject* parent)
: Report(id, "StockReport", parent), m_warehouse(warehouse) {}

void StockReport::generate() {
    m_data.clear();
    m_data["warehouseID"] = m_warehouse->getWarehouseID();
    m_data["warehouseAddress"] = m_warehouse->getAddress();

    int totalProducts = 0;
    double totalValue = 0.0;

    for (auto product : m_warehouse->getAllProducts()) {
        totalProducts += product->getQuantity();
        totalValue += product->getQuantity() * product->getUnitPrice();
    }

    m_data["totalProducts"] = totalProducts;
    m_data["totalValue"] = QString("%1 руб.").arg(totalValue, 0, 'f', 2);
    m_data["productCount"] = m_warehouse->getProductCount();

    emit dataChanged();
}
