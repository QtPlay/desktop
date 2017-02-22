#include "MacOsNotifier.h"
#include <QVariant>
#include <QDebug>

#import <Foundation/Foundation.h>
#import <Foundation/NSUserNotification.h>


@interface NotificationDelegate : NSObject <NSUserNotificationCenterDelegate>
@end

@implementation NotificationDelegate

- (BOOL)userNotificationCenter:(NSUserNotificationCenter*)center shouldPresentNotification:(NSUserNotification*)notification;
{
   return YES;
}

- (void)showNotification:(NSString*)title
                          message:(NSString*)msg;
{
  NSUserNotification *notif = [[[NSUserNotification alloc] init] autorelease];
  notif.title = title;
  notif.informativeText = msg;
//  notif.soundName = NSUserNotificationDefaultSoundName;
  NSUserNotificationCenter *center = [NSUserNotificationCenter defaultUserNotificationCenter];
  center.delegate = self;
  [center deliverNotification:notif];
}

@end


//-----------------------------------------------------------------------------
MacOsNotifier::MacOsNotifier()
{

}

//-----------------------------------------------------------------------------
void MacOsNotifier::notify(const QVariant &params)
{
    NotificationDelegate *mn = [[[NotificationDelegate alloc] init] autorelease];
    QVariantMap parameters = params.toMap();
    QString caption = parameters.value("caption", "").toString();
    QString title   = parameters.value("title", "").toString();
    [mn showNotification:title.toNSString() message:caption.toNSString()];
    qDebug() << "Notification triggered";
}
