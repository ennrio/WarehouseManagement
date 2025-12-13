#pragma once
#include "reportfactory.h"
#include "warehouse.h"
#include "stockreport.h"

class StockReportFactory : public ReportFactory {
    Q_OBJECT

private:
    Warehouse* m_warehouse;

public:
    explicit StockReportFactory(Warehouse* warehouse, QObject* parent = nullptr);

    Report* createReport(const QString& id, QObject* parent = nullptr) override;
};
