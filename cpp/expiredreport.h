#pragma once
#include "report.h"
#include "warehouse.h"

class ExpiredReport : public Report {
    Q_OBJECT

private:
    Warehouse* m_warehouse;

public:
    ExpiredReport(const QString& id, Warehouse* warehouse, QObject* parent = nullptr);

    void generate() override;
};
