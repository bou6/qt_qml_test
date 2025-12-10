#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "service.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    Service passport("Passport", 10);
    Service driverLicense("DriverLicense", 25);
    
    // Expose both objects with different names
    engine.rootContext()->setContextProperty("passport", &passport);
    engine.rootContext()->setContextProperty("driverLicense", &driverLicense);
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("qmlTest3", "Main");

    return app.exec();
}
