#ifndef LOCALNOTIFICATIONINTERFACE_H
#define LOCALNOTIFICATIONINTERFACE_H

#include <QVariant>
#include <QObject>

class LocalNotificationInterface : public QObject
{
    Q_OBJECT
public:
    virtual void notify(const QVariant &params) {}
    virtual void show(QVariantMap params) {}

signals:
    void notificationTriggered();
    void notificationOpened();

    void timeoutCompleted();
};

#endif // LOCALNOTIFICATIONINTERFACE_H
