#include "stockreportfactory.h"

StockReportFactory::StockReportFactory(Warehouse* warehouse, QObject* parent)
: ReportFactory(parent), m_warehouse(warehouse) {}

Report* StockReportFactory::createReport(const QString& id, QObject* parent) {
    return new StockReport(id, m_warehouse, parent);
}
