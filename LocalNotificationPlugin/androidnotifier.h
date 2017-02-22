#ifndef ANDROIDNOTIFIER_H
#define ANDROIDNOTIFIER_H

#include "LocalNotificationInterface.h"

class AndroidNotifier : public LocalNotificationInterface
{
public:
    AndroidNotifier() {}
    void notify(const QVariant &params);
    void show(QVariantMap params);
};


#endif // ANDROIDNOTIFIER_H
