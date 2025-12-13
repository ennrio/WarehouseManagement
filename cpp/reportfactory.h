#pragma once
#include <QObject>
#include "report.h"

// Паттерн Factory Method
class ReportFactory : public QObject {
    Q_OBJECT

public:
    explicit ReportFactory(QObject* parent = nullptr) : QObject(parent) {}
    virtual ~ReportFactory() = default;

    virtual Report* createReport(const QString& id, QObject* parent = nullptr) = 0;
};
