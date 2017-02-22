#include "IosNotifier.h"
#include <QVariant>

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#include <QDebug>

@interface NotificationDelegate : UIResponder <UIApplicationDelegate>
@end

@implementation NotificationDelegate

- (void)showNotification:(NSString*)title
                          message:(NSString*)msg;
{
    NSLog(@"inside this method");
    NSLog(title);
    NSLog(msg);
    UILocalNotification* localNotification = [[UILocalNotification alloc] init];
    localNotification.fireDate = [NSDate dateWithTimeIntervalSinceNow:10];
    localNotification.alertBody = msg;
    localNotification.timeZone = [NSTimeZone defaultTimeZone];
    localNotification.applicationIconBadgeNumber = [[UIApplication sharedApplication] applicationIconBadgeNumber] + 1;
    [[UIApplication sharedApplication] scheduleLocalNotification:localNotification];
}

@end

//------------------------------------------------------------------------
IosNotifier::IosNotifier()
{
    UIUserNotificationType types = UIUserNotificationTypeBadge |
    UIUserNotificationTypeSound | UIUserNotificationTypeAlert;

    UIUserNotificationSettings *mySettings =
    [UIUserNotificationSettings settingsForTypes:types categories:nil];

    [[UIApplication sharedApplication] registerUserNotificationSettings:mySettings];
}

//------------------------------------------------------------------------
void IosNotifier::notify(const QVariant &params)
{
    NotificationDelegate *mn = [[[NotificationDelegate alloc] init] autorelease];
    QVariantMap parameters = params.toMap();
    QString caption = parameters.value("message", "").toString();
    QString title = parameters.value("title", "").toString();
    UILocalNotification* localNotification = [[UILocalNotification alloc] init];
    localNotification.alertBody = caption.toNSString();
    [[UIApplication sharedApplication] scheduleLocalNotification:localNotification];
    [mn showNotification:title.toNSString() message:caption.toNSString()];
    emit notificationTriggered();
    return;
}

//------------------------------------------------------------------------

void IosNotifier::show(QVariantMap parameters)
{
    QString caption = parameters.value("message", "").toString();
    QString title   = parameters.value("title", "").toString();
    int id          = parameters.value("id", 0).toInt();
    bool visible    = parameters.value("visible", true).toBool();
    int interval    = parameters.value("interval", 0).toInt();
    int timeout     = parameters.value("timeout", 1000).toInt();

    NotificationDelegate *mn = [[[NotificationDelegate alloc] init] autorelease];
    UILocalNotification* localNotification = [[UILocalNotification alloc] init];
    localNotification.alertBody = caption.toNSString();
    [[UIApplication sharedApplication] scheduleLocalNotification:localNotification];
    [mn showNotification:title.toNSString() message:caption.toNSString()];
    emit notificationTriggered();
    return;
}

//------------------------------------------------------------------------
