#pragma once
#include <QObject>
#include <QList>
#include <QMap>
#include "warehouse.h"
#include "supplier.h"
#include "employee.h"
#include "reportfactory.h"
#include "supply.h"
#include "stockreport.h"
#include "expiredreport.h"
#include "stockreportfactory.h"
#include "expiredreportfactory.h"

// Паттерн Singleton
class WarehouseManager : public QObject {
    Q_OBJECT
    Q_PROPERTY(QList<QObject*> warehouses READ getWarehouses NOTIFY warehousesChanged)
    Q_PROPERTY(QList<QObject*> suppliers READ getSuppliers NOTIFY suppliersChanged)
    Q_PROPERTY(QList<QObject*> employees READ getEmployees NOTIFY employeesChanged)
    Q_PROPERTY(QList<QObject*> supplies READ getSupplies NOTIFY suppliesChanged)


private:
    static WarehouseManager* m_instance;
    QList<Warehouse*> m_warehouses;
    QList<Supplier*> m_suppliers;
    QList<Employee*> m_employees;
    QList<Supply*> m_supplies;

    WarehouseManager(QObject* parent = nullptr);

public:
    static WarehouseManager* getInstance(QObject* parent = nullptr);
    Supplier* getSupplier(const QString& id);

    // Управление складами
    Q_INVOKABLE void addWarehouse(const QString& id, const QString& address, int capacity);
    Q_INVOKABLE Warehouse* getWarehouse(const QString& id);
    Q_INVOKABLE QList<QObject*> getWarehouses();

    // Управление поставщиками
    Q_INVOKABLE void addSupplier(const QString& id, const QString& companyName, const QString& contactInfo);
    Q_INVOKABLE QList<QObject*> getSuppliers();

    // Управление сотрудниками
    Q_INVOKABLE void addEmployee(const QString& id, const QString& name, const QString& position, const QString& contactInfo);
    Q_INVOKABLE QList<QObject*> getEmployees();

    // Обработка поставок
    Q_INVOKABLE void processSupply(const QString& supplyID, const QString& warehouseID);

    // Управление поставками
    Q_INVOKABLE void createSupply(const QString& supplyID, const QString& supplierID,
                                  const QString& date, const QVariantList& products);
    Q_INVOKABLE void confirmSupply(const QString& supplyID, const QString& warehouseID);
    Q_INVOKABLE QList<QObject*> getSupplies();
    Q_INVOKABLE Supply* getSupply(const QString& supplyID);

    // Генерация отчетов
    Q_INVOKABLE Report* generateReport(ReportFactory* factory, const QString& reportID);

    Q_INVOKABLE StockReport* generateStockReport(Warehouse* warehouse, const QString& reportId);
    Q_INVOKABLE ExpiredReport* generateExpiredReport(Warehouse* warehouse, const QString& reportId);
    Q_INVOKABLE QString saveReportAsPdf(const QString& content, const QString& filePath);


    // Служебные методы
    static void destroyInstance();

signals:
    void warehousesChanged();
    void suppliersChanged();
    void employeesChanged();
    void suppliesChanged();
    void notification(const QString& message);
};
