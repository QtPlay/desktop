#ifndef NOTIFICATIONDETECTOR_H
#define NOTIFICATIONDETECTOR_H

#include "LocalNotificationInterface.h"

class PlatformDetector
{
public:
    static LocalNotificationInterface *getPlatform();
};

#endif // NOTIFICATIONDETECTOR_H
