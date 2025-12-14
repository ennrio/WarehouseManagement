#include "warehouse.h"
#include "basicproduct.h"
#include "promotionalproduct.h"
#include "perishableproduct.h"
#include <QDebug>

Warehouse::Warehouse(const QString& id, const QString& address, int capacity, QObject* parent)
    : QObject(parent), m_warehouseID(id), m_address(address), m_maxCapacity(capacity) {

    qDebug() << "[C++] Создан склад:" << id;
}

Warehouse::~Warehouse() {
    qDeleteAll(m_products);
}

void Warehouse::addProduct(Product* product) {
    if (m_products.size() >= m_maxCapacity) {
        qWarning() << "⚠️ Склад" << m_warehouseID << "заполнен! Не удалось добавить:" << product->getName();
        notifyObservers("⚠️ Склад заполнен! Не удалось добавить: " + product->getName());
        return;
    }

    // ✅ ДОБАВЛЯЕМ В МАССИВ
    m_products.append(product);

    qDebug().noquote() << "\n[C++] Товар добавлен на склад" << m_warehouseID;
    qDebug() << "  ID:" << product->getProductID();
    qDebug() << "  Название:" << product->getName();
    qDebug() << "  Тип:" << product->metaObject()->className();
    qDebug() << "  Всего товаров в m_products:" << m_products.size();

    // ✅ ПОДКЛЮЧАЕМ СИГНАЛЫ
    connect(product, &Product::quantityChanged, this, [this, product]() {
        qDebug() << "[C++] Сигнал quantityChanged для товара:" << product->getName();
        emit productsChanged();
    });

    connect(product, &Product::expirationWarning, this, [this, product]() {
        emit expirationWarning("⚠️ Товар скоро испортится: " + product->getName());
    });

    // Проверка просрочки
    if (product->getExpirationDate().isValid() && product->getExpirationDate() < QDate::currentDate()) {
        notifyObservers("просрочка: Товар '" + product->getName() + "' просрочен (истёк " + product->getExpirationDate().toString("dd.MM.yyyy") + ")");
        emit expirationWarning("Просрочен товар: " + product->getName());
    }
    // ✅ ИСПУСКАЕМ СИГНАЛ ОБ ИЗМЕНЕНИИ ТОВАРОВ
    qDebug() << "[C++] Испускаем сигнал productsChanged()";
    emit productsChanged();

    notifyObservers("✅ Товар добавлен: " + product->getName());
    checkStockLevel();
}

void Warehouse::addProductFromQML(const QString &id, const QString &name, const QString &category, const QString &manufacturer, int quantity, double price, const QString &expiryDate, bool isPromotional, bool isPerishable)
{
    qDebug() << "[C++] addProductFromQML вызван для склада" << m_warehouseID;
    qDebug() << "  Параметры:";
    qDebug() << "  ID:" << id;
    qDebug() << "  Название:" << name;
    qDebug() << "  Количество:" << quantity;

    // Создаем базовый товар
    BasicProduct* product = new BasicProduct(id, name, category, manufacturer, quantity, price,
                                             QDate::fromString(expiryDate, "dd.MM.yyyy"),
                                             QDate::currentDate(),isPromotional, isPerishable);

    // Применяем декораторы
    // Product* finalProduct = product;
    // if (isPromotional) {
    //     qDebug() << "  Применен декоратор: PromotionalProduct";
    //     finalProduct = new PromotionalProduct(finalProduct, 20.0); // 20% скидка
    // }
    // if (isPerishable) {
    //     qDebug() << "  Применен декоратор: PerishableProduct";
    //     finalProduct = new PerishableProduct(finalProduct, "0-5°C");
    // }

    // Добавляем на склад
    //addProduct(finalProduct);
    addProduct(product);
}

void Warehouse::removeProduct(const QString& productID) {
    for (int i = 0; i < m_products.size(); ++i) {
        if (m_products[i]->getProductID() == productID) {
            Product* product = m_products.takeAt(i);
            emit productsChanged();
            notifyObservers("🗑️ Товар удален: " + product->getName());
            delete product;
            return;
        }
    }
}

Product* Warehouse::searchProduct(const QString& productID) {
    for (auto product : m_products) {
        if (product->getProductID() == productID) {
            return product;
        }
    }
    return nullptr;
}

QList<Product*> Warehouse::searchProducts(const QString& keyword) {
    QList<Product*> results;
    for (auto product : m_products) {
        if (product->getName().contains(keyword, Qt::CaseInsensitive) ||
            product->getProductID().contains(keyword, Qt::CaseInsensitive)) {
            results.append(product);
        }
    }
    return results;
}

void Warehouse::addObserver(IObserver* observer) {
    if (!m_observers.contains(observer)) {
        m_observers.append(observer);
    }
}

void Warehouse::removeObserver(IObserver* observer) {
    m_observers.removeAll(observer);
}

void Warehouse::notifyObservers(const QString& message) {
    qDebug() << "📢 Уведомление склада" << m_warehouseID << ":" << message;
    for (auto observer : m_observers) {
        observer->update(message);
    }
}

void Warehouse::checkStockLevel() {
    for (auto product : m_products) {
        // Приведение к BasicProduct для доступа к getUnitPrice()
        BasicProduct* basicProduct = qobject_cast<BasicProduct*>(product);
        if (basicProduct && product->getQuantity() < 10) {
            emit stockWarning("📉 Низкий запас: " + product->getName() +
                              " (осталось: " + QString::number(product->getQuantity()) + ")");
        }
        product->checkExpiration();
        if (product->getExpirationDate().isValid() && product->getExpirationDate() < QDate::currentDate()) {
            notifyObservers("просрочка: Товар '" + product->getName() + "' просрочен (истёк " +
                            product->getExpirationDate().toString("dd.MM.yyyy") + ")");
        }
    }
}

void Warehouse::attachObserver(IObserver *observer, const QString &warehouseID)
{
    m_warehouseObservers[warehouseID].append(observer);
}

void Warehouse::notifyObservers(const QString &message, const QString &warehouseID, const QString &prefix)
{
    QString fullMessage = prefix.isEmpty() ? message : (prefix + ": " + message);
    auto it = m_warehouseObservers.find(warehouseID);
    if (it != m_warehouseObservers.end()) {
        for (IObserver* obs : *it) {
            obs->update(fullMessage);
        }
    }
}
