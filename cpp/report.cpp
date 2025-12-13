#include "report.h"
#include <QFile>
#include <QTextStream>

Report::Report(const QString& id, const QString& type, QObject* parent)
: QObject(parent), m_reportID(id), m_reportType(type),
m_creationDate(QDate::currentDate()) {}

void Report::exportToFile(const QString &filePath)
{
    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream stream(&file);
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
        stream.setEncoding(QStringConverter::Utf8);
#else
        stream.setCodec("UTF-8");
#endif

        stream << "Отчет: " << m_reportType << "\n";
        stream << "ID: " << m_reportID << "\n";
        stream << "Дата создания: " << m_creationDate.toString("dd.MM.yyyy") << "\n";
        stream << "================================\n\n";

        for (auto it = m_data.begin(); it != m_data.end(); ++it) {
            stream << it.key() << ": " << it.value().toString() << "\n";
        }

        file.close();
    }
}


