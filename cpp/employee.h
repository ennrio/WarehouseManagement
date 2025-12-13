#pragma once
#include <QObject>
#include <QStringList>
#include "iobserver.h"

class Employee : public QObject, public IObserver {
    Q_OBJECT
    Q_PROPERTY(QString employeeID READ getEmployeeID CONSTANT)
    Q_PROPERTY(QString name READ getName CONSTANT)
    Q_PROPERTY(QString position READ getPosition CONSTANT)
    Q_PROPERTY(QStringList notifications READ getNotifications NOTIFY notificationsChanged)

private:
    QString m_employeeID;
    QString m_name;
    QString m_position;
    QString m_contactInfo;
    QStringList m_operationsLog;
    QStringList m_notifications;

public:
    Employee(const QString& id, const QString& name, const QString& position,
             const QString& contactInfo, QObject* parent = nullptr);

    // Реализация IObserver
    void update(const QString& message) override;

    // Управление операциями
    void performOperation(const QString& operation);
    QStringList getOperationsLog() const { return m_operationsLog; }

    // Геттеры
    QString getEmployeeID() const { return m_employeeID; }
    QString getName() const { return m_name; }
    QString getPosition() const { return m_position; }
    QString getContactInfo() const { return m_contactInfo; }
    QStringList getNotifications() const { return m_notifications; }

signals:
    void notificationsChanged();
};
