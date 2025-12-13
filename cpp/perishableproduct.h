#pragma once
#include "productdecorator.h"

class PerishableProduct : public ProductDecorator {
    Q_OBJECT
    Q_PROPERTY(QString productID READ getProductID CONSTANT)
    Q_PROPERTY(QString name READ getName CONSTANT)
    Q_PROPERTY(int quantity READ getQuantity NOTIFY quantityChanged)
    Q_PROPERTY(double unitPrice READ getUnitPrice CONSTANT)
    Q_PROPERTY(QDate expirationDate READ getExpirationDate CONSTANT)
    Q_PROPERTY(QString storageConditions READ getStorageConditions CONSTANT)

private:
    QString m_storageConditions;

public:
    PerishableProduct(Product* product, const QString& storageConditions, QObject* parent = nullptr);

    QString getDetails() const override;
    bool checkExpiration() const override;

    QString getStorageConditions() const { return m_storageConditions; }

    // ✅ ОБЯЗАТЕЛЬНО: переопределяем все виртуальные методы
    QString getProductID() const override { return ProductDecorator::getProductID(); }
    QString getName() const override { return ProductDecorator::getName(); }
    int getQuantity() const override { return ProductDecorator::getQuantity(); }
    QDate getExpirationDate() const override { return ProductDecorator::getExpirationDate(); }
    double getUnitPrice() const override { return ProductDecorator::getUnitPrice(); }

signals:
    // ✅ НАСЛЕДУЕМ СИГНАЛЫ
    void quantityChanged();
    void expirationWarning();
};
