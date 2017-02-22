#ifndef LINUXNOTIFIER_H
#define LINUXNOTIFIER_H

#include "LocalNotificationInterface.h"
#include <QSystemTrayIcon>

class LinuxNotifier : public LocalNotificationInterface
{

public:
    LinuxNotifier() {}

public:
    void notify(const QVariant &notificationParameters);

private:
    QSystemTrayIcon* systemTrayIcon;
};

#endif // LINUXNOTIFIER_H
