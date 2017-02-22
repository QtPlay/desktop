#include "LocalNotification.h"
#include "PlatformDetector.h"
#include <QDebug>

LocalNotification::LocalNotification(QObject *parent)
    : QObject(parent), notificationInterface(NULL)
{
    notificationInterface = PlatformDetector::getPlatform();
    connect(notificationInterface, SIGNAL(notificationTriggered()), this, SIGNAL(notificationTriggered()));
}

LocalNotification::~LocalNotification()
{
    if (notificationInterface != NULL)
    {
        delete notificationInterface;
    }
}

void LocalNotification::notify(const QVariant &params)
{
    notificationInterface->notify(params);
}

void LocalNotification::show()
{
    // Add stuff to the qvariant
    QVariantMap params; // = new QVariantMap();
    params.insert("title", this->m_Title);
    params.insert("message", this->m_Message);
    params.insert("timeout", this->m_Timeout);
    params.insert("interval", this->m_Interval);
    params.insert("visible", this->m_Visible);
    params.insert("iconstyle", (int) this->iconStyle());

    notificationInterface->show(params);
}

void LocalNotification::registerQMLType()
{
    qmlRegisterType<LocalNotification>("LocalNotification", 1, 0, "Notification");
}
