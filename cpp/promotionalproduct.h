#pragma once
#include "productdecorator.h"

class PromotionalProduct : public ProductDecorator {
    Q_OBJECT
    Q_PROPERTY(QString productID READ getProductID CONSTANT)
    Q_PROPERTY(QString name READ getName CONSTANT)
    Q_PROPERTY(int quantity READ getQuantity NOTIFY quantityChanged)
    Q_PROPERTY(double unitPrice READ getUnitPrice CONSTANT)
    Q_PROPERTY(QDate expirationDate READ getExpirationDate CONSTANT)
    Q_PROPERTY(double discountPercent READ getDiscountPercent CONSTANT)
    Q_PROPERTY(double discountedPrice READ getDiscountedPrice CONSTANT)

private:
    double m_discountPercent;

public:
    PromotionalProduct(Product* product, double discountPercent, QObject* parent = nullptr);

    QString getDetails() const override;
    double getUnitPrice() const override;

    double getDiscountPercent() const { return m_discountPercent; }
    double getDiscountedPrice() const;

    QString getProductID() const override { return ProductDecorator::getProductID(); }
    QString getName() const override { return ProductDecorator::getName(); }
    int getQuantity() const override { return ProductDecorator::getQuantity(); }
    QDate getExpirationDate() const override { return ProductDecorator::getExpirationDate(); }

signals:
    void quantityChanged();
    void expirationWarning();
};
