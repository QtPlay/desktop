#include "PlatformDetector.h"
#include <QDebug>

#if defined (Q_OS_ANDROID)
    #include "AndroidNotifier.h"
#elif defined (Q_OS_LINUX)
    #include "DesktopNotifier.h"
#elif defined (Q_OS_IOS)
    #include "IosNotifier.h"
#elif defined (Q_OS_MACOS)
    #include "DesktopNotifier.h"
#elif defined (Q_OS_WIN)
    #include "DesktopNotifier.h
#endif

LocalNotificationInterface *PlatformDetector::getPlatform()
{

#if defined Q_OS_ANDROID
    return new AndroidNotifier();

#elif defined Q_OS_IOS
    return new IosNotifier();

#elif defined Q_OS_MACOS
    return new DesktopNotifier();

#elif defined Q_OS_LINUX
    return new DesktopNotifier();

#elif defined Q_OS_WIN64
    return new DesktopNotifier();

#endif
    qWarning("QtNotifierFactory: doesn't support your platform");
    return NULL;
}
