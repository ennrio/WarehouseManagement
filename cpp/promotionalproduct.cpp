#include "promotionalproduct.h"
#include <QDebug>

PromotionalProduct::PromotionalProduct(Product* product, double discountPercent, QObject* parent)
    : ProductDecorator(product, parent), m_discountPercent(discountPercent) {
    qDebug() << "[C++] Создан PromotionalProduct для товара:" << product->getName()
        << "Скидка:" << discountPercent << "%";
}

QString PromotionalProduct::getDetails() const {
    return ProductDecorator::getDetails() +
           QString(" | 🏷️ Акция: -%1% (Цена со скидкой: %2₽)")
               .arg(m_discountPercent)
               .arg(getDiscountedPrice(), 0, 'f', 2);
}

double PromotionalProduct::getUnitPrice() const {
    // Цена со скидкой
    return getDiscountedPrice();
}

double PromotionalProduct::getDiscountedPrice() const {
    double originalPrice = ProductDecorator::getUnitPrice();
    return originalPrice * (1.0 - m_discountPercent / 100.0);
}
