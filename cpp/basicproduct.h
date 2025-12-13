#pragma once
#include "product.h"

class BasicProduct : public Product {
    Q_OBJECT
    Q_PROPERTY(QString productID READ getProductID CONSTANT)
    Q_PROPERTY(QString name READ getName CONSTANT)
    Q_PROPERTY(QString category READ getCategory CONSTANT)  // ✅ Добавлено
    Q_PROPERTY(QString manufacturer READ getManufacturer CONSTANT)  // ✅ Добавлено
    Q_PROPERTY(int quantity READ getQuantity NOTIFY quantityChanged)
    Q_PROPERTY(double unitPrice READ getUnitPrice CONSTANT)  // ✅ Добавлено
    Q_PROPERTY(QDate expirationDate READ getExpirationDate CONSTANT)
    Q_PROPERTY(QDate arrivalDate READ getArrivalDate CONSTANT)  // ✅ Добавлено
    Q_PROPERTY(bool promotional READ isPromational CONSTANT)
    Q_PROPERTY(bool perishable READ isPerishable CONSTANT)

private:
    QString m_productID;
    QString m_name;
    QString m_category;
    QString m_manufacturer;
    int m_quantity;
    double m_unitPrice;
    QDate m_expirationDate;
    QDate m_arrivalDate;
    bool m_promational;
    bool m_perishable;

public:
    BasicProduct(const QString& id, const QString& name, const QString& category,
                 const QString& manufacturer, int quantity, double price,
                 const QDate& expiration, const QDate& arrival, bool promational, bool perishable,
                 QObject* parent = nullptr);

    QString getDetails() const override;
    bool checkExpiration() const override;
    void updateQuantity(int amount) override;

    // Геттеры
    QString getProductID() const override { return m_productID; }
    QString getName() const override { return m_name; }
    int getQuantity() const override { return m_quantity; }
    QDate getExpirationDate() const override { return m_expirationDate; }
    double getUnitPrice() const override { return m_unitPrice; }
    QString getCategory() const override { return m_category; }
    QString getManufacturer() const override { return m_manufacturer; }
    QDate getArrivalDate() const { return m_arrivalDate; }

    bool isPromational() const {return m_promational;}
    bool isPerishable() const {return m_perishable;}
signals:
    void quantityChanged();
    void expirationWarning();
};
