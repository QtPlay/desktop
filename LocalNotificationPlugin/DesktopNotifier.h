#ifndef MACOSNOTIFIER_H
#define MACOSNOTIFIER_H

#include <QObject>
#include <QSystemTrayIcon>
#include "LocalNotificationInterface.h"

class DesktopNotifier : public LocalNotificationInterface
{
public:
    DesktopNotifier() { createTrayIcon(); }
    ~DesktopNotifier();

public:
    void notify(const QVariant &params);
    void show(QVariantMap params);

private slots:
    void iconActivated(QSystemTrayIcon::ActivationReason reason);

private:
    void createTrayIcon();
    void showMessage(QString title, QString message);
    void notificationClicked();

private:
    QSystemTrayIcon* systemTrayIcon;
};

#endif // MACOSNOTIFIER_H
