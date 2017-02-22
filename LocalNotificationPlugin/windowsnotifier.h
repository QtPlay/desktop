#ifndef WINDOWSNOTIFIER_H
#define WINDOWSNOTIFIER_H

#include "LocalNotificationInterface.h"
#include <QSystemTrayIcon>

class WindowsNotifier : public LocalNotificationInterface
{

public:
    WindowsNotifier() {}

public:
    void notify(const QVariant &params);

private:
    QSystemTrayIcon* systemTrayIcon;
};

#endif // WINDOWSNOTIFIER_H
