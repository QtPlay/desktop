#include <QApplication>
#include <QQmlApplicationEngine>
#include "alertbanner.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qmlRegisterType<AlertBanner>("AlertBanner", 1, 0, "AlertBanner");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
