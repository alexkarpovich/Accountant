#include <QGuiApplication>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include "app.h"
#include "account.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    App ap;
    ap.init();

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("hello", 10);

    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    return app.exec();
}
