#pragma once
#include "product.h"

// Базовый класс для паттерна Decorator
class ProductDecorator : public Product {
protected:
    Product* m_wrappedProduct;

public:
    explicit ProductDecorator(Product* product, QObject* parent = nullptr);
    ~ProductDecorator();

    // Делегирование базовым методам
    QString getDetails() const override;
    bool checkExpiration() const override;
    void updateQuantity(int amount) override;
    double getUnitPrice() const override;

    // Геттеры (делегирование)
    QString getProductID() const override;
    QString getName() const override;
    int getQuantity() const override;
    QDate getExpirationDate() const override;
    QString getCategory() const;
    QString getManufacturer() const;
};
