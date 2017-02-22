#include "LinuxNotifier.h"

#include <QDebug>
#include <QMenu>

void LinuxNotifier::notify(const QVariant &params)
{
    systemTrayIcon = new QSystemTrayIcon();

    if (systemTrayIcon)
    {
        qDebug() << "Initialized System Tray Icon";
    }

    QVariantMap parameters = params.toMap();
    QString caption = parameters.value("caption", "").toString();
    QString title   = parameters.value("title", "").toString();

    if(systemTrayIcon->supportsMessages())
    {
        qDebug() << "Supports Notification";

        // @TODO: icon path in linux doesn't accept qrc path
        // need to provide absolute path
        QIcon icon("://notification_icon.png");
        Q_ASSERT(!icon.isNull());
        systemTrayIcon->setIcon(icon);

        // @TODO: linux doesnt set tooltip
        systemTrayIcon->setToolTip(title);

        QMenu* menu = new QMenu();
        menu->addAction(new QAction(caption));
        systemTrayIcon->setContextMenu(menu);
        systemTrayIcon->show();
    }

    else
    {
        qDebug() << "Doesn't support QSystemTrayIcon";
    }
}
