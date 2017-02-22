#ifndef LOCALNOTIFICATION_H
#define LOCALNOTIFICATION_H

#include <QObject>
#include <qqml.h>

#include "LocalNotificationInterface.h"

class LocalNotification : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int timeout MEMBER m_Timeout)
    Q_PROPERTY(bool visible MEMBER m_Visible)
    Q_PROPERTY(QString title MEMBER m_Title)
    Q_PROPERTY(QString message MEMBER m_Message)
    Q_PROPERTY(int interval MEMBER m_Interval)
    Q_PROPERTY(IconStyle iconStyle MEMBER m_iconStyle)

public:

    Q_ENUMS(IconStyle)

    enum class IconStyle : int {
        NoIcon,
        Information,
        Warning,
        Critical
    };

public:
    explicit LocalNotification(QObject *parent = 0);
    ~LocalNotification();

    Q_INVOKABLE void notify(const QVariant &params);
    Q_INVOKABLE void show();

    static void registerQMLType();

private:
    LocalNotificationInterface* notificationInterface;

    IconStyle iconStyle() const {
        return m_iconStyle;
    }

private:
    int m_Timeout;
    bool m_Visible;
    QString m_Title;
    QString m_Message;
    int m_Interval;
    IconStyle m_iconStyle;

signals:
    void notificationTriggered();
    void notificationOpened();
    void timeoutCompleted();
};

#endif // LOCALNOTIFICATION_H
