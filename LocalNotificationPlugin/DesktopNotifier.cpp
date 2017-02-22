#include "desktopnotifier.h"
#include <QDebug>

void DesktopNotifier::createTrayIcon()
{
    systemTrayIcon = new QSystemTrayIcon();
    connect(systemTrayIcon, &QSystemTrayIcon::activated, this, &DesktopNotifier::iconActivated);
}

DesktopNotifier::~DesktopNotifier()
{
    if (systemTrayIcon != NULL)
    {
        delete systemTrayIcon;
    }
}

void DesktopNotifier::show(QVariantMap params)
{
    if (systemTrayIcon)
    {
        qDebug() << "Initialized";
    }

    QString title   = params.value("title", "").toString();
    QString caption = params.value("message", "").toString();
    bool visible = params.value("visible", true).toBool();
    int interval = params.value("interval", 0).toInt();
    int timeout = params.value("timeout", 1000).toInt();
    int iconStyle = params.value("iconstyle", 1).toInt();

    if (systemTrayIcon->isSystemTrayAvailable())
    {
        qDebug() << "QSystemTrayIcon is available";
//        QIcon icon("://icon.png");
//        QIcon icon(iconSource);

        if (systemTrayIcon->supportsMessages())
        {
            qDebug() << "QSystemTrayIcon: Supports Messages";

//            Q_ASSERT(!icon.isNull());
//            systemTrayIcon->setIcon(icon);

            systemTrayIcon->setToolTip(title);
            systemTrayIcon->setVisible(visible);
//            systemTrayIcon->show();

//            showMessage(title, caption);

            QSystemTrayIcon::MessageIcon icon =
                    QSystemTrayIcon::MessageIcon(iconStyle);

            if (visible)
            {
                systemTrayIcon->showMessage(title, caption, icon, timeout);
                emit notificationTriggered();
            }
        }
        else
        {
            qDebug() << "QSystemTrayIcon: Doesn't Support Messages";
        }
    }
    else
    {
        qDebug() << "Doesn't support QSystemTrayIcon";
    }
}

void DesktopNotifier::notify(const QVariant &params)
{

    if (systemTrayIcon)
    {
        qDebug() << "Initialized";
    }

    QVariantMap parameters = params.toMap();
    QString title   = parameters.value("title", "").toString();
    QString caption = parameters.value("message", "").toString();
    bool visible = parameters.value("visible", true).toBool();
    int interval = parameters.value("interval", 0).toInt();
    int timeout = parameters.value("timeout", 1000).toInt();
    int iconStyle = parameters.value("iconstyle", 1).toInt();

    qDebug() << "Timeout is " << timeout;
    if (systemTrayIcon->isSystemTrayAvailable())
    {
        qDebug() << "System Tray is available";
        QIcon icon("://icon.png");

        if (systemTrayIcon->supportsMessages())
        {
            qDebug() << "Supports Messages";

            Q_ASSERT(!icon.isNull());
            systemTrayIcon->setIcon(icon);
            systemTrayIcon->setToolTip(title);
            systemTrayIcon->setVisible(visible);
//            systemTrayIcon->show();

//            showMessage(title, caption);
            QSystemTrayIcon::MessageIcon icon =
                    QSystemTrayIcon::MessageIcon(iconStyle);

            if (visible)
            {
                systemTrayIcon->showMessage(title, caption, icon, timeout);
                emit notificationTriggered();
            }
            emit notificationTriggered();
        }
        else
        {
            qDebug() << "Doesn't Support Messages";
        }
    }
    else
    {
        qDebug() << "Doesn't support QSystemTrayIcon";
    }
}

void DesktopNotifier::showMessage(QString title, QString message)
{
    QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::MessageIcon::Information;
    systemTrayIcon->showMessage(title, message, icon, 1000);
}

void DesktopNotifier::notificationClicked()
{
    emit notificationOpened();
}

void DesktopNotifier::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason) {
    case QSystemTrayIcon::Trigger:
    case QSystemTrayIcon::DoubleClick:
//        iconComboBox->setCurrentIndex((iconComboBox->currentIndex() + 1) % iconComboBox->count());
//        break;
    case QSystemTrayIcon::MiddleClick:
//        showMessage();
        break;
    default:
        ;
    }
}
