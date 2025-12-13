#pragma once
#include "report.h"
#include "warehouse.h"

class StockReport : public Report {
    Q_OBJECT

private:
    Warehouse* m_warehouse;

public:
    StockReport(const QString& id, Warehouse* warehouse, QObject* parent = nullptr);

    void generate() override;
};
