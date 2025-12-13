#include "basicproduct.h"
#include <QDebug>

BasicProduct::BasicProduct(const QString& id, const QString& name, const QString& category,
                           const QString& manufacturer, int quantity, double price,
                           const QDate& expiration, const QDate& arrival, bool promational, bool perishable,
                           QObject* parent)
: Product(parent), m_productID(id), m_name(name), m_category(category),
m_manufacturer(manufacturer), m_quantity(quantity), m_unitPrice(price),
    m_expirationDate(expiration), m_arrivalDate(arrival), m_promational(promational), m_perishable(perishable) {}

QString BasicProduct::getDetails() const {
    return QString("ID: %1 | %2 (%3) | Кол-во: %4 | Цена: %5₽ | Срок: %6")
    .arg(m_productID, m_name, m_category)
    .arg(m_quantity).arg(m_unitPrice)
    .arg(m_expirationDate.toString("dd.MM.yyyy"));
}

bool BasicProduct::checkExpiration() const {
    QDate currentDate = QDate::currentDate();
    bool isExpired = m_expirationDate < currentDate;
    bool isNearExpiry = m_expirationDate <= currentDate.addDays(3);

    if (isNearExpiry && !isExpired) {
        qDebug() << "⚠️ Предупреждение о сроке годности:" << m_name;
        const_cast<BasicProduct*>(this)->emit expirationWarning();
    }

    return !isExpired;
}

void BasicProduct::updateQuantity(int amount) {
    m_quantity += amount;
    emit quantityChanged();
    qDebug() << "📦 Количество товара" << m_name << "изменено:" << amount;
}
