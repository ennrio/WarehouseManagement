#pragma once
#include <QString>
#include <QDate>
#include <QObject>

class Product : public QObject {
    Q_OBJECT
public:
    Q_PROPERTY(QString productID READ getProductID CONSTANT)
    Q_PROPERTY(QString name READ getName CONSTANT)
    Q_PROPERTY(int quantity READ getQuantity NOTIFY quantityChanged)
    Q_PROPERTY(double unitPrice READ getUnitPrice CONSTANT)
    Q_PROPERTY(QDate expirationDate READ getExpirationDate CONSTANT)
    explicit Product(QObject* parent = nullptr) : QObject(parent) {}
    virtual ~Product() = default;

    // Основные методы
    virtual QString getDetails() const = 0;
    virtual bool checkExpiration() const = 0;
    virtual void updateQuantity(int amount) = 0;

    // Геттеры
    virtual QString getProductID() const = 0;
    virtual QString getName() const = 0;
    virtual int getQuantity() const = 0;
    virtual QDate getExpirationDate() const = 0;
    virtual double getUnitPrice() const = 0;
    virtual QString getCategory() const = 0;
    virtual QString getManufacturer() const = 0;

signals:
    void quantityChanged();
    void expirationWarning();
};
