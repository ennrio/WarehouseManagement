#include "employee.h"
#include <QDateTime>

Employee::Employee(const QString& id, const QString& name, const QString& position,
                   const QString& contactInfo, QObject* parent)
    : QObject(parent), m_employeeID(id), m_name(name),
    m_position(position), m_contactInfo(contactInfo) {}

void Employee::update(const QString& message) {
    QString timestamp = QDateTime::currentDateTime().toString("hh:mm:ss");
    m_notifications.prepend("[" + timestamp + "] " + message);
    emit notificationsChanged();
}

void Employee::performOperation(const QString& operation) {
    QString timestamp = QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss");
    m_operationsLog.append("[" + timestamp + "] " + operation);
    qDebug() << "👤" << m_name << "выполнил:" << operation;
}
