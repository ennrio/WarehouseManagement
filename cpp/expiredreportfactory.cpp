#include "expiredreportfactory.h"

ExpiredReportFactory::ExpiredReportFactory(Warehouse* warehouse, QObject* parent)
: ReportFactory(parent), m_warehouse(warehouse) {}

Report* ExpiredReportFactory::createReport(const QString& id, QObject* parent) {
    return new ExpiredReport(id, m_warehouse, parent);
}
