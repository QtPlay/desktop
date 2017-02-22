#include "WindowsNotifier.h"

#include <QVariant>
#include <QDebug>
#include <QMenu>
#include <QAction>
#include <QIcon>

void WindowsNotifier::notify(const QVariant &params)
{
    systemTrayIcon = new QSystemTrayIcon();

    if (systemTrayIcon)
    {
        qDebug() << "Initialized";
    }

    QVariantMap parameters = params.toMap();
    QString caption = parameters.value("caption", "").toString();
    QString title   = parameters.value("title", "").toString();

    if(systemTrayIcon->isSystemTrayAvailable())
    {
        qDebug() << "System Tray is available";
        QIcon icon("://notification_icon.png");
        Q_ASSERT(!icon.isNull());
        systemTrayIcon->setIcon(icon);
        systemTrayIcon->setToolTip(title);

        QMenu * menu = new QMenu();
        menu->addAction(new QAction(caption));
        systemTrayIcon->setContextMenu(menu);
        systemTrayIcon->show();
    }
    else
    {
        qDebug() << "Doesn't support QSystemTrayIcon";
    }
}
