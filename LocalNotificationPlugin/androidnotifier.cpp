#include "AndroidNotifier.h"

#include <QVariant>
#include <QtAndroid>

void AndroidNotifier::notify(const QVariant &params)
{
    QVariantMap parameters = params.toMap();
    QString caption = parameters.value("message", "").toString();
    QString title   = parameters.value("title", "").toString();
    int id          = parameters.value("id", 0).toInt();
    bool visible    = parameters.value("visible", true).toBool();
    int interval    = parameters.value("interval", 0).toInt();
    int timeout     = parameters.value("timeout", 1000).toInt();


    QAndroidJniObject jni_caption = QAndroidJniObject::fromString(caption);
    QAndroidJniObject jni_title   = QAndroidJniObject::fromString(title);

    if (visible) {

        QAndroidJniObject::callStaticMethod<void>("samples/notifications/local/QtAndroidNotifications",
                                              "show",
                                              "(Ljava/lang/String;Ljava/lang/String;I)V",
                                              jni_title.object<jstring>(),
                                              jni_caption.object<jstring>(),
                                              (jint) id);
        emit notificationTriggered();

    }

}

void AndroidNotifier::show(QVariantMap parameters)
{
    QString caption = parameters.value("message", "").toString();
    QString title   = parameters.value("title", "").toString();
    int id          = parameters.value("id", 0).toInt();
    bool visible    = parameters.value("visible", true).toBool();
    int interval    = parameters.value("interval", 0).toInt();
    int timeout     = parameters.value("timeout", 1000).toInt();


    QAndroidJniObject jni_caption = QAndroidJniObject::fromString(caption);
    QAndroidJniObject jni_title   = QAndroidJniObject::fromString(title);

    if (visible) {

        QAndroidJniObject::callStaticMethod<void>("samples/notifications/local/QtAndroidNotifications",
                                              "show",
                                              "(Ljava/lang/String;Ljava/lang/String;I)V",
                                              jni_title.object<jstring>(),
                                              jni_caption.object<jstring>(),
                                              (jint) id);
        emit notificationTriggered();

    }

}
