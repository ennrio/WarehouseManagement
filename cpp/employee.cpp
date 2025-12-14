#include "employee.h"
#include <QDateTime>

Employee::Employee(const QString& id, const QString& name, const QString& position,
                   const QString& contactInfo, QObject* parent)
    : QObject(parent), m_employeeID(id), m_name(name),
    m_position(position), m_contactInfo(contactInfo) {}

void Employee::update(const QString& message) {
    qDebug() << "[Employee]" << name() << "получил уведомление:" << message;

    QString timestamp = QDateTime::currentDateTime().toString("hh:mm:ss");
    m_notifications.append("[" + timestamp + "] " + message);
    emit notificationsChanged();

    qDebug() << "[Employee] Уведомлений теперь:" << m_notifications.size();
}

void Employee::performOperation(const QString& operation) {
    QString timestamp = QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss");
    m_operationsLog.append("[" + timestamp + "] " + operation);
    qDebug() << "👤" << m_name << "выполнил:" << operation;
}

void Employee::setWarehouseID(const QString &id)
{
    if (m_warehouseID != id) {
        m_warehouseID = id;
        emit warehouseIDChanged();
    }
}
