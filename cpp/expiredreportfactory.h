#pragma once
#include "reportfactory.h"
#include "warehouse.h"
#include "expiredreport.h"

class ExpiredReportFactory : public ReportFactory {
    Q_OBJECT

private:
    Warehouse* m_warehouse;

public:
    explicit ExpiredReportFactory(Warehouse* warehouse, QObject* parent = nullptr);

    Report* createReport(const QString& id, QObject* parent = nullptr) override;
};
