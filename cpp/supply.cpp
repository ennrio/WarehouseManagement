#include "supply.h"
#include "warehouse.h"

Supply::Supply(const QString& id, const QString& supplierID, const QDate& date,
               QList<Product*> products, QObject* parent)
: QObject(parent), m_supplyID(id), m_supplierID(supplierID),
m_supplyDate(date), m_products(products), m_status("pending") {}

Supply::~Supply() {
    if (m_status != "confirmed") {
        qDeleteAll(m_products);
    }
}

void Supply::confirmSupply() {
    m_status = "confirmed";
    emit statusChanged();
}

void Supply::addToWarehouse(Warehouse* warehouse) {
    if (m_status == "confirmed") {
        for (auto product : m_products) {
            warehouse->addProduct(product);
        }
        m_products.clear(); // Передаем владение складу
    }
}
