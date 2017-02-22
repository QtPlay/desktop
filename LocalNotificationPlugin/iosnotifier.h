#ifndef IOSNOTIFIER_H
#define IOSNOTIFIER_H

#include "LocalNotificationInterface.h"

class IosNotifier : public LocalNotificationInterface
{
public:
    explicit IosNotifier();
    void notify(const QVariant &params);
    void show(QVariantMap params);
};

#endif // IOSNOTIFIER_H
