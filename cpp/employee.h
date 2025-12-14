#pragma once
#include <QObject>
#include <QStringList>
#include "iobserver.h"

class Employee : public QObject, public IObserver {
    Q_OBJECT
    Q_PROPERTY(QString id READ id CONSTANT)
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QString position READ position CONSTANT)
    Q_PROPERTY(QString contactInfo READ contactInfo CONSTANT)
    Q_PROPERTY(QStringList notifications READ notifications NOTIFY notificationsChanged)
    Q_PROPERTY(QString warehouseID READ warehouseID WRITE setWarehouseID NOTIFY warehouseIDChanged)

private:
    QString m_employeeID;
    QString m_name;
    QString m_position;
    QString m_contactInfo;
    QStringList m_operationsLog;
    QStringList m_notifications;
    QString m_warehouseID;

public:
    explicit Employee(const QString& id, const QString& name, const QString& position,
                      const QString& contactInfo, QObject *parent = nullptr);

    // Реализация IObserver
    void update(const QString& message) override;

    // QString warehouseID() const;
    // void setWarehouseID(const QString& id);

    // Управление операциями
    void performOperation(const QString& operation);
    QStringList getOperationsLog() const { return m_operationsLog; }

    // Геттеры
    QString id() const { return m_employeeID; }
    QString name() const { return m_name; }
    QString position() const { return m_position; }
    QString contactInfo() const { return m_contactInfo; }
    QStringList notifications() const { return m_notifications; }
    QString warehouseID() const { return m_warehouseID; }
    void setWarehouseID(const QString& id);


    Q_INVOKABLE void clearNotifications() {
        m_notifications.clear();
        emit notificationsChanged();
    }

signals:
    void notificationsChanged();
    void warehouseIDChanged();
};
