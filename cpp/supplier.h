#pragma once
#include <QObject>
#include <QStringList>

class Supplier : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString supplierID READ getSupplierID CONSTANT)
    Q_PROPERTY(QString companyName READ getCompanyName CONSTANT)
    Q_PROPERTY(QString contactInfo READ getContactInfo CONSTANT)
    Q_PROPERTY(QStringList suppliedProducts READ getSuppliedProducts NOTIFY productsChanged)

private:
    QString m_supplierID;
    QString m_companyName;
    QString m_contactInfo;
    QStringList m_suppliedProducts;

public:
    Supplier(const QString& id, const QString& companyName,
             const QString& contactInfo, QObject* parent = nullptr);

    // Управление товарами
    void addProduct(const QString& productName);
    void updateContactInfo(const QString& info);

    // Геттеры
    QString getSupplierID() const { return m_supplierID; }
    QString getCompanyName() const { return m_companyName; }
    QString getContactInfo() const { return m_contactInfo; }
    QStringList getSuppliedProducts() const { return m_suppliedProducts; }

signals:
    void productsChanged();
};
