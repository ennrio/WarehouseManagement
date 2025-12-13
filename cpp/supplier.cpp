#include "supplier.h"

Supplier::Supplier(const QString& id, const QString& companyName,
                   const QString& contactInfo, QObject* parent)
: QObject(parent), m_supplierID(id), m_companyName(companyName),
m_contactInfo(contactInfo) {}

void Supplier::addProduct(const QString& productName) {
    if (!m_suppliedProducts.contains(productName)) {
        m_suppliedProducts.append(productName);
        emit productsChanged();
    }
}

void Supplier::updateContactInfo(const QString& info) {
    m_contactInfo = info;
}
