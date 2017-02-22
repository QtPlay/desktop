TEMPLATE = app

QT += qml quick
CONFIG += c++11

unix:!macx:!android:!ios {
    CONFIG += linux-appstudio
    message("linux")
}

HEADERS += \
    PlatformDetector.h \
    LocalNotification.h \
    LocalNotificationInterface.h

SOURCES += main.cpp \
    PlatformDetector.cpp \
    LocalNotification.cpp


RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32 | macx | linux-appstudio
{
    QT += widgets

    HEADERS += DesktopNotifier.h

    SOURCES += DesktopNotifier.cpp
}

android {
    QT += androidextras
    QT -= widgets

    HEADERS += \
        AndroidNotifier.h

    SOURCES += \
        AndroidNotifier.cpp

    HEADERS -= DesktopNotifier.h

    SOURCES -= DesktopNotifier.cpp

ANDROID_PACKAGE_SOURCE_DIR =$$PWD/android

DISTFILES += \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat \
    notification_icon.png
}

ios {
    LIBS += -framework Foundation
    QT -= widgets
    CONFIG -= bitcode

    HEADERS += \
        IosNotifier.h

    OBJECTIVE_SOURCES += \
        IosNotifier.mm

    HEADERS -= DesktopNotifier.h

    SOURCES -= DesktopNotifier.cpp
}

DISTFILES += \
    android/src/samples/notifications/local/QtAndroidNotifications.java \
    android/res/drawable-hdpi/icon.png \
    android/res/drawable-hdpi/splash.png \
    android/res/drawable-ldpi/icon.png \
    android/res/drawable-ldpi/splash.png \
    android/res/drawable-mdpi/icon.png \
    android/res/drawable-mdpi/splash.png \
    android/res/drawable-xhdpi/icon.png \
    android/res/drawable-xhdpi/splash.png \
    android/res/drawable-xxhdpi/icon.png \
    android/res/drawable-xxhdpi/splash.png
