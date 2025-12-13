#pragma once
#include <QObject>
#include <QList>
#include "product.h"

class Supply : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString supplyID READ getSupplyID CONSTANT)
    Q_PROPERTY(QString supplierID READ getSupplierID CONSTANT)
    Q_PROPERTY(QDate supplyDate READ getSupplyDate CONSTANT)
    Q_PROPERTY(QString status READ getStatus NOTIFY statusChanged)
    Q_PROPERTY(int productCount READ getProductCount CONSTANT)

private:
    QString m_supplyID;
    QString m_supplierID;
    QDate m_supplyDate;
    QList<Product*> m_products;
    QString m_status; // "pending", "confirmed", "cancelled"

public:
    Supply(const QString& id, const QString& supplierID, const QDate& date,
           QList<Product*> products, QObject* parent = nullptr);
    ~Supply();

    // Управление
    void confirmSupply();
    void addToWarehouse(class Warehouse* warehouse);

    // Геттеры
    QString getSupplyID() const { return m_supplyID; }
    QString getSupplierID() const { return m_supplierID; }
    QDate getSupplyDate() const { return m_supplyDate; }
    QString getStatus() const { return m_status; }
    QList<Product*> getProducts() const { return m_products; }
    int getProductCount() const { return m_products.size(); }

signals:
    void statusChanged();
};
