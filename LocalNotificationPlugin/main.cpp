

#include <QQmlApplicationEngine>

#if defined (Q_OS_ANDROID) || defined (Q_OS_IOS)
    #include <QGuiApplication>

#else
    #include <QApplication>
#endif

#include "localnotification.h"

int main(int argc, char *argv[])
{

    #if defined (Q_OS_ANDROID)
        QGuiApplication app(argc, argv);
    #elif defined (Q_OS_IOS)
        QGuiApplication app(argc, argv);
    #else
        QApplication app(argc, argv);
    #endif

    QQmlApplicationEngine engine;
    LocalNotification::registerQMLType();

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
