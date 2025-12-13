#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QFile>
#include <QDir>
#include <iostream>

#include "cpp/warehousemanager.h"
#include "cpp/basicproduct.h"
#include "cpp/promotionalproduct.h"
#include "cpp/perishableproduct.h"
#include "cpp/warehouse.h"
#include "cpp/employee.h"
#include "cpp/supplier.h"
#include "cpp/supply.h"
#include "cpp/stockreport.h"
#include "cpp/expiredreport.h"
#include "cpp/stockreportfactory.h"
#include "cpp/expiredreportfactory.h"

// Кастомный обработчик сообщений
void customMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QByteArray localMsg = msg.toLocal8Bit();
    const char *file = context.file ? context.file : "";
    const char *function = context.function ? context.function : "";

    // Выводим в std::cout (работает всегда)
    std::cout << "[" << QDateTime::currentDateTime().toString("hh:mm:ss.zzz").toStdString() << "] ";

    switch (type) {
    case QtDebugMsg:
        std::cout << "[DEBUG] " << localMsg.constData()
                  << " (" << file << ":" << context.line << ", " << function << ")" << std::endl;
        break;
    case QtInfoMsg:
        std::cout << "[INFO] " << localMsg.constData() << std::endl;
        break;
    case QtWarningMsg:
        std::cout << "[WARNING] " << localMsg.constData() << std::endl;
        break;
    case QtCriticalMsg:
        std::cout << "[CRITICAL] " << localMsg.constData() << std::endl;
        break;
    case QtFatalMsg:
        std::cout << "[FATAL] " << localMsg.constData() << std::endl;
        abort();
    }

    // Также пишем в файл для надежности
    static QFile fileLog("debug.log");
    if (!fileLog.isOpen()) {
        fileLog.open(QIODevice::WriteOnly | QIODevice::Append);
    }
    QTextStream stream(&fileLog);
    stream << QDateTime::currentDateTime().toString("hh:mm:ss.zzz") << " " << msg << "\n";
    stream.flush();
}

int main(int argc, char *argv[]) {

    qInstallMessageHandler(customMessageHandler);
    std::cout << "Запуск приложения..." << std::endl;
    qDebug() << "Qt Debug: Приложение запущено";
    QGuiApplication app(argc, argv);

    // Регистрация типов для QML
    qmlRegisterType<WarehouseManager>("WarehouseManagement", 1, 0, "WarehouseManager");
    qmlRegisterType<BasicProduct>("WarehouseManagement", 1, 0, "BasicProduct");

    // Абстрактные декораторы — некреатируемые
    qmlRegisterUncreatableType<PromotionalProduct>("WarehouseManagement", 1, 0, "PromotionalProduct",
                                                   "Cannot create abstract decorator");
    qmlRegisterUncreatableType<PerishableProduct>("WarehouseManagement", 1, 0, "PerishableProduct",
                                                  "Cannot create abstract decorator");

    qmlRegisterType<Warehouse>("WarehouseManagement", 1, 0, "Warehouse");
    qmlRegisterType<Employee>("WarehouseManagement", 1, 0, "Employee");
    qmlRegisterType<Supplier>("WarehouseManagement", 1, 0, "Supplier");
    qmlRegisterType<Supply>("WarehouseManagement", 1, 0, "Supply");
    qmlRegisterType<StockReport>("WarehouseManagement", 1, 0, "StockReport");
    qmlRegisterType<ExpiredReport>("WarehouseManagement", 1, 0, "ExpiredReport");
    qmlRegisterType<StockReportFactory>("WarehouseManagement", 1, 0, "StockReportFactory");
    qmlRegisterType<ExpiredReportFactory>("WarehouseManagement", 1, 0, "ExpiredReportFactory");



    qmlRegisterSingletonType<WarehouseManager>("WarehouseManagement", 1, 0, "WarehouseManager",
                                               [](QQmlEngine *engine, QJSEngine *scriptEngine) -> QObject* {
                                                   Q_UNUSED(engine)
                                                   Q_UNUSED(scriptEngine)
                                                   return WarehouseManager::getInstance();
                                               }
                                               );

    QQmlApplicationEngine engine;

    // Singleton
    WarehouseManager* manager = WarehouseManager::getInstance();
    engine.rootContext()->setContextProperty("warehouseManager", manager);

    // Уведомления
    QObject::connect(manager, &WarehouseManager::notification,
                     [](const QString& msg) {
                         qDebug() << "📢 NOTIFICATION:" << msg;
                     });

    QString qmlFilePath = QCoreApplication::applicationDirPath() + "/../qml/main.qml";
    QFile qmlFile(qmlFilePath);

    qDebug() << "Current directory:" << QDir::currentPath();
    qDebug() << "Application directory:" << QCoreApplication::applicationDirPath();
    qDebug() << "Looking for QML at:" << qmlFilePath;
    qDebug() << "QML file exists:" << qmlFile.exists();

    QUrl url;
    if (qmlFile.exists()) {
        // Загружаем из файла
        url = QUrl::fromLocalFile(qmlFilePath);
        qDebug() << "Loading QML from file:" << url;
    } else {
        // Пробуем из ресурсов
        url = QUrl(QStringLiteral("qrc:/main.qml"));
        qDebug() << "Loading QML from resources:" << url;

        // Дополнительные проверки
        QStringList testPaths = {
            QDir::currentPath() + "/qml/main.qml",
            "/home/egor/all/study/5seml/OOP/WarehouseManagement/qml/main.qml",
            QCoreApplication::applicationDirPath() + "/qml/main.qml"
        };

        for (const QString& path : testPaths) {
            if (QFile::exists(path)) {
                qDebug() << "Found QML at alternative path:" << path;
                url = QUrl::fromLocalFile(path);
                break;
            }
        }
    };

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
                         if (!obj && url == objUrl)
                             QCoreApplication::exit(-1);
                     }, Qt::QueuedConnection);

    engine.addImportPath(QCoreApplication::applicationDirPath() + "/qml");
    engine.load(url);

    return app.exec();
}
