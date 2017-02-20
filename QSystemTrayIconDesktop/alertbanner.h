#ifndef ALERTBANNER_H
#define ALERTBANNER_H

#include <QObject>
#include <QSystemTrayIcon>

QT_BEGIN_NAMESPACE
class QAction;
class QMenu;

QT_END_NAMESPACE

class AlertBanner : public QObject
{
    Q_OBJECT
public:
    explicit AlertBanner(QObject *parent = 0);
    ~AlertBanner();
    Q_INVOKABLE void alert(const QVariant &params);

private:
    void createTrayIcon();
//    void createActions();
    void showMessage(QString title, QString message);

private:

    QSystemTrayIcon* banner;
    QMenu* bannerMenu;
//    QAction *minimizeAction;
//    QAction *maximizeAction;
//    QAction *restoreAction;
//    QAction *quitAction;


};

#endif // ALERTBANNER_H
