#include <QGuiApplication>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include "app_service.h"
#include "account.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    QQmlContext* ctx = engine.rootContext();

    AppService appService;

    ctx->setContextProperty("appService", &appService);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
