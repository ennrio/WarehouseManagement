#include "perishableproduct.h"
#include <QDebug>

PerishableProduct::PerishableProduct(Product* product, const QString& storageConditions, QObject* parent)
    : ProductDecorator(product, parent), m_storageConditions(storageConditions) {
    qDebug() << "[C++] Создан PerishableProduct для товара:" << product->getName()
        << "Условия хранения:" << storageConditions;
}

QString PerishableProduct::getDetails() const {
    return ProductDecorator::getDetails() +
           QString(" | ❄️ Условия хранения: %1").arg(m_storageConditions);
}

bool PerishableProduct::checkExpiration() const {
    bool isOk = ProductDecorator::checkExpiration();
    if (!isOk) {
        qDebug() << "🚨 СРОК ГОДНОСТИ ИСТЕК:" << getName();
    }
    return isOk;
}
