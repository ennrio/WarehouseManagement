#pragma once
#include <QObject>
#include <QMap>
#include <QDate>

class Report : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString reportID READ getReportID CONSTANT)
    Q_PROPERTY(QString reportType READ getReportType CONSTANT)
    Q_PROPERTY(QDate creationDate READ getCreationDate CONSTANT)
    Q_PROPERTY(QVariantMap data READ getData NOTIFY dataChanged)

protected:
    QString m_reportID;
    QString m_reportType;
    QDate m_creationDate;
    QMap<QString, QVariant> m_data;

public:
    Report(const QString& id, const QString& type, QObject* parent = nullptr);

    virtual void generate() = 0;
    virtual void exportToFile(const QString& filePath);

    // Геттеры
    QString getReportID() const { return m_reportID; }
    QString getReportType() const { return m_reportType; }
    QDate getCreationDate() const { return m_creationDate; }
    QVariantMap getData() const { return QVariantMap(m_data); }

signals:
    void dataChanged();
};
