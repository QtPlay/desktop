#include "alertbanner.h"
#include <QDebug>
#include <QIcon>
#include <QMenu>

AlertBanner::AlertBanner(QObject *parent)
    : QObject(parent)
{
    createTrayIcon();
//    createActions();
}

AlertBanner::~AlertBanner()
{
    if (banner != NULL)
    {
        delete banner;
    }
}

void AlertBanner::alert(const QVariant &params)
{
    if (banner)
    {
        qDebug() << "Initialized";
    }

    QVariantMap parameters = params.toMap();
    QString title   = parameters.value("title", "").toString();
    QString caption = parameters.value("message", "").toString();

    if (banner->isSystemTrayAvailable())
    {
        qDebug() << "System Tray is available";
        QIcon icon("://icon.png");

        if (banner->supportsMessages())
        {
            qDebug() << "Supports Messages";

            Q_ASSERT(!icon.isNull());
            banner->setIcon(icon);
            banner->setToolTip(title);

            QMenu* menu = new QMenu();
            menu->addAction(new QAction(caption));

            banner->setContextMenu(menu);
            banner->setVisible(true);
            banner->show();
        }
        else
        {
            qDebug() << "Doesn't Support Messages";
        }
        showMessage(title, caption);
    }
    else
    {
        qDebug() << "Doesn't support QSystemTrayIcon";
    }

}

void AlertBanner::createTrayIcon()
{
//    bannerMenu = new QMenu();

//    bannerMenu->addAction(minimizeAction);
//    bannerMenu->addAction(maximizeAction);
//    bannerMenu->addAction(restoreAction);
//    bannerMenu->addSeparator();
//    bannerMenu->addAction(quitAction);

    banner = new QSystemTrayIcon(this);
//    banner->setContextMenu(bannerMenu);
}

//void AlertBanner::createActions()
//{
//    minimizeAction = new QAction(tr("Mi&nimize"), this);
////    connect(minimizeAction, &QAction::triggered, this, &QWidget::hide);

//    maximizeAction = new QAction(tr("Ma&ximize"), this);
////    connect(maximizeAction, &QAction::triggered, this, &QWidget::showMaximized);

//    restoreAction = new QAction(tr("&Restore"), this);
////    connect(restoreAction, &QAction::triggered, this, &QWidget::showNormal);

//    quitAction = new QAction(tr("&Quit"), this);
////    connect(quitAction, &QAction::triggered, qApp, &QCoreApplication::quit);
//}

void AlertBanner::showMessage(QString title, QString message)
{
    QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::MessageIcon::Information;
    banner->showMessage(title, message, icon, 1000);
}

