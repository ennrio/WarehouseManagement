#pragma once
#include <QObject>
#include <QList>
#include <QMap>
#include "iobserver.h"
#include "product.h"
#include "basicproduct.h"

class Warehouse : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString warehouseID READ getWarehouseID CONSTANT)
    Q_PROPERTY(QString address READ getAddress CONSTANT)
    Q_PROPERTY(int productCount READ getProductCount NOTIFY productsChanged)
    Q_PROPERTY(int capacity READ getCapacity CONSTANT)
    Q_PROPERTY(QList<QObject*> allProducts READ getAllProductsQML NOTIFY productsChanged)

private:
    QString m_warehouseID;
    QString m_address;
    int m_maxCapacity;
    QList<Product*> m_products;
    QList<IObserver*> m_observers;
    QList<QObject*> getAllProductsQML() const {
        QList<QObject*> list;
        for (auto p : m_products) list.append(p);
        return list;
    }

public:
    Warehouse(const QString& id, const QString& address, int capacity, QObject* parent = nullptr);
    ~Warehouse();

    // Управление товарами
    void addProduct(Product* product);
    Q_INVOKABLE void addProductFromQML(const QString& id, const QString& name, const QString& category,
                                       const QString& manufacturer, int quantity, double price,
                                       const QString& expiryDate, bool isPromotional, bool isPerishable);
    void removeProduct(const QString& productID);
    Product* searchProduct(const QString& productID);
    QList<Product*> searchProducts(const QString& keyword);

    // Паттерн Observer
    void addObserver(IObserver* observer);
    void removeObserver(IObserver* observer);
    void notifyObservers(const QString& message);

    // Контроль запасов
    void checkStockLevel();

    // Геттеры
    QString getWarehouseID() const { return m_warehouseID; }
    QString getAddress() const { return m_address; }
    int getMaxCapacity() const { return m_maxCapacity; }
    int getCapacity() const { return m_maxCapacity; }
    int getProductCount() const { return m_products.size(); }
    QList<Product*> getAllProducts() const { return m_products; }

    Q_INVOKABLE Product* getProductByIndex(int index) {
        if (index >= 0 && index < m_products.size()) {
            return m_products[index];
        }
        return nullptr;
    }

    Q_INVOKABLE QStringList getAllProductNames() const {
        QStringList names;
        for (auto product : m_products) {
            names.append(product->getName());
        }
        return names;
    }

    Q_INVOKABLE QVariantList getProductsSimple() const {
        QVariantList result;
        for (auto product : m_products) {
            QVariantMap item;

            // Основные поля
            item["id"] = product->getProductID();
            item["name"] = product->getName();
            item["category"] = product->getCategory();
            item["manufacturer"] = product->getManufacturer();
            item["quantity"] = product->getQuantity();
            item["price"] = product->getUnitPrice();

            // Дата в строковом формате
            QDate expiry = product->getExpirationDate();
            if (expiry.isValid()) {
                item["expiryDate"] = expiry.toString("dd.MM.yyyy");
            } else {
                item["expiryDate"] = "";
            }

            // Проверяем тип товара
            BasicProduct* basicProduct = qobject_cast<BasicProduct*>(product);
            if (basicProduct) {
                item["isPromotional"] = basicProduct->isPromational();
                item["isPerishable"] = basicProduct->isPerishable();
            } else {
                item["isPromotional"] = false;
                item["isPerishable"] = false;
            }

            // Отладочный вывод
            qDebug() << "Товар в getProductsSimple:" << item["name"]
                     << "promo:" << item["isPromotional"]
                     << "perishable:" << item["isPerishable"];

            result.append(item);
        }
        return result;
    }


signals:
    void productsChanged();
    void stockWarning(const QString& message);
    void expirationWarning(const QString& message);
};
