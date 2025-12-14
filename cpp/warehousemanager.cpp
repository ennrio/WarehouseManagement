#include "warehousemanager.h"
#include <QDebug>
#include <QPrinter>
#include <QPainter>
#include <QTextDocument>
#include <QPageLayout>
#include <QFileInfo>
#include <QDir>



    WarehouseManager* WarehouseManager::m_instance = nullptr;

WarehouseManager::WarehouseManager(QObject* parent)
    : QObject(parent) {}

WarehouseManager* WarehouseManager::getInstance(QObject* parent) {
    if (!m_instance) {
        m_instance = new WarehouseManager(parent);
    }
    return m_instance;
}

void WarehouseManager::addWarehouse(const QString& id, const QString& address, int capacity) {
    auto warehouse = new Warehouse(id, address, capacity, this);
    m_warehouses.append(warehouse);

    connect(warehouse, &Warehouse::stockWarning, this, [this](const QString& msg) {
        emit notification(msg);
    });
    connect(warehouse, &Warehouse::expirationWarning, this, [this](const QString& msg) {
        emit notification(msg);
    });

    emit warehousesChanged();
    emit notification("✅ Склад создан: " + id);
}

Warehouse* WarehouseManager::getWarehouse(const QString& id) {
    for (auto warehouse : m_warehouses) {
        if (warehouse->getWarehouseID() == id) {
            return warehouse;
        }
    }
    return nullptr;
}

QList<QObject*> WarehouseManager::getWarehouses() {
    QList<QObject*> list;
    for (auto w : m_warehouses) list.append(w);
    return list;
}

Supplier* WarehouseManager::getSupplier(const QString& id) {
    for (auto supplier : m_suppliers) {
        if (supplier->getSupplierID() == id) {
            return supplier;
        }
    }
    return nullptr;
}

void WarehouseManager::addSupplier(const QString& id, const QString& companyName, const QString& contactInfo) {
    m_suppliers.append(new Supplier(id, companyName, contactInfo, this));
    emit suppliersChanged();
}

QList<QObject*> WarehouseManager::getSuppliers() {
    QList<QObject*> list;
    for (auto s : m_suppliers) list.append(s);
    return list;
}

void WarehouseManager::addEmployee(const QString &id, const QString &name, const QString &position, const QString &contactInfo, const QString &warehouseID)
{
    auto employee = new Employee(id, name, position, contactInfo, this);

    // Привязываем к конкретному складу, если указан
    if (!warehouseID.isEmpty()) {
        employee->setWarehouseID(warehouseID);
        Warehouse* wh = getWarehouse(warehouseID);
        if (wh) {
            wh->addObserver(employee);
        }
    } else {
        // Если склад не указан — подписываем на все (как было раньше)
        for (auto warehouse : m_warehouses) {
            warehouse->addObserver(employee);
        }
    }

    m_employees.append(employee);
    emit employeesChanged();
}



QList<QObject*> WarehouseManager::getEmployees() {
    QList<QObject*> list;
    for (auto e : m_employees) list.append(e);
    return list;
}

// Новые методы для управления поставками
void WarehouseManager::createSupply(const QString& supplyID, const QString& supplierID,
                                    const QString& date, const QVariantList& products) {
    qDebug() << "=== CREATE SUPPLY ===";
    qDebug() << "Supply ID:" << supplyID;
    qDebug() << "Supplier ID:" << supplierID;
    qDebug() << "Date:" << date;
    qDebug() << "Number of products:" << products.size();

    // Проверяем, существует ли поставка с таким ID
    for (auto supply : m_supplies) {
        if (supply->getSupplyID() == supplyID) {
            qWarning() << "Supply with ID" << supplyID << "already exists";
            emit notification("❌ Поставка с ID " + supplyID + " уже существует");
            return;
        }
    }

    // Проверяем существование поставщика
    Supplier* supplier = getSupplier(supplierID);
    if (!supplier) {
        qWarning() << "Supplier" << supplierID << "not found";
        emit notification("❌ Поставщик с ID " + supplierID + " не найден");
        return;
    }

    // Создаем список товаров
    QList<Product*> productList;
    for (const QVariant& item : products) {
        QVariantMap productData = item.toMap();

        QString productID = productData["id"].toString();
        QString name = productData["name"].toString();
        QString category = productData["category"].toString();
        QString manufacturer = productData["manufacturer"].toString();
        int quantity = productData["quantity"].toInt();
        double price = productData["price"].toDouble();
        QString expiryDate = productData["expiryDate"].toString();
        bool isPromotional = productData["isPromotional"].toBool();
        bool isPerishable = productData["isPerishable"].toBool();

        qDebug() << "Creating product:" << name << "quantity:" << quantity;

        // Создаем базовый товар
        BasicProduct* product = new BasicProduct(
            productID,
            name,
            category,
            manufacturer,
            quantity,
            price,
            QDate::fromString(expiryDate, "dd.MM.yyyy"),
            QDate::fromString(date, "dd.MM.yyyy"),
            isPromotional,
            isPerishable,
            this
            );

        productList.append(product);
    }

    // Создаем поставку
    QDate supplyDate = QDate::fromString(date, "dd.MM.yyyy");
    if (!supplyDate.isValid()) {
        supplyDate = QDate::currentDate();
        qWarning() << "Invalid date, using current date";
    }

    Supply* supply = new Supply(supplyID, supplierID, supplyDate, productList, this);
    m_supplies.append(supply);

    // Добавляем сигнал для отслеживания изменений статуса
    connect(supply, &Supply::statusChanged, this, [this]() {
        emit suppliesChanged();
    });


    emit suppliesChanged();
    emit notification("✅ Поставка создана: " + supplyID);
    qDebug() << "Supply created and added to list. Total supplies:" << m_supplies.size();
    QString message = "Поставка " + supplyID + " успешно подтверждена и размещена на складе.";

}

void WarehouseManager::confirmSupply(const QString& supplyID, const QString& warehouseID) {
    Supply* supply = getSupply(supplyID);
    if (!supply) {
        emit notification("❌ Поставка с ID " + supplyID + " не найдена");
        return;
    }

    Warehouse* warehouse = getWarehouse(warehouseID);
    if (!warehouse) {
        emit notification("❌ Склад с ID " + warehouseID + " не найден");
        return;
    }

    // Подтверждаем поставку
    supply->confirmSupply();

    // Добавляем товары на склад
    supply->addToWarehouse(warehouse);
    warehouse->notifyObservers("поставка: Поставка " + supplyID + " успешно подтверждена и размещена на складе " + warehouseID);
    emit suppliesChanged();
    emit notification("✅ Поставка " + supplyID + " подтверждена и добавлена на склад " + warehouseID);
}

QList<QObject*> WarehouseManager::getSupplies() {
    QList<QObject*> list;
    for (auto s : m_supplies) list.append(s);
    return list;
}

Supply* WarehouseManager::getSupply(const QString& supplyID) {
    for (auto supply : m_supplies) {
        if (supply->getSupplyID() == supplyID) {
            return supply;
        }
    }
    return nullptr;
}

void WarehouseManager::processSupply(const QString& supplyID, const QString& warehouseID) {
    // Просто вызываем подтверждение поставки
    confirmSupply(supplyID, warehouseID);
}

Report* WarehouseManager::generateReport(ReportFactory* factory, const QString& reportID) {
    Report* report = factory->createReport(reportID);
    report->generate();
    emit notification("📊 Отчет сгенерирован: " + reportID);
    return report;
}

StockReport *WarehouseManager::generateStockReport(Warehouse *warehouse, const QString &reportId)
{
    if (!warehouse) return nullptr;
    StockReportFactory factory(warehouse);
    Report* report = generateReport(&factory, reportId);
    return static_cast<StockReport*>(report);
}

ExpiredReport *WarehouseManager::generateExpiredReport(Warehouse *warehouse, const QString &reportId)
{
    if (!warehouse) return nullptr;
    ExpiredReportFactory factory(warehouse);
    Report* report = generateReport(&factory, reportId);

    return static_cast<ExpiredReport*>(report);
}

QString WarehouseManager::saveReportAsPdf(const QString &content, const QString &filePath)
{
    qDebug() << "Сохранение PDF:";
    qDebug() << "  Путь:" << filePath;
    qDebug() << "  Длина текста:" << content.length();
    qDebug() << "  Первые 100 символов:" << content.left(100);

    if (content.isEmpty() || filePath.isEmpty()) {
        return "Ошибка: пустой отчёт или путь.";
    }

    QFileInfo fileInfo(filePath);
    QDir dir = fileInfo.dir();
    qDebug() << "  Папка существует:" << dir.exists();
    if (dir.exists()) {
        // Проверка записи через создание временного файла
        QFile testFile(dir.filePath("__test_write__.tmp"));
        bool canWrite = testFile.open(QIODevice::WriteOnly);
        if (canWrite) testFile.remove();
        qDebug() << "  Папка доступна на запись:" << canWrite;
    }

    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filePath);
    printer.setPageMargins(QMarginsF(15, 15, 15, 15), QPageLayout::Millimeter);

    QTextDocument document;
    document.setPlainText(content);
    document.setDefaultFont(QFont("Courier", 10));


    document.print(&printer);

    if (QFile::exists(filePath)) {
        qDebug() << "✅ Файл PDF успешно создан!";
        return "Отчёт сохранён: " + filePath;
    } else {
        qDebug() << "❌ Файл НЕ создан. Возможные причины: недопустимый путь, спецсимволы, отсутствие PrintSupport.";
        return "Не удалось сохранить PDF: " + filePath;
    }
}

void WarehouseManager::destroyInstance() {
    delete m_instance;
    m_instance = nullptr;
}
