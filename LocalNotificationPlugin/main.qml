import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.2

import LocalNotification 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Button {
        id: button
        text: "Tap button"

        onClicked: {
//            notification.show()

            notification.notify({
                                    message: "Hello Melbourne!!",
                                    title  : "Local Notification test",
                                    visible    : true,
                                    timeout : 10000,
                                    interval : 1,
                                    iconStyle: Notification.Information
                                });
        }
    }

    Notification {
        id: notification
        title: "Test Title"
        message: "Test message"
        timeout: 5000
        visible: true
        interval: 5
        iconStyle: Notification.Warning

        onNotificationTriggered: {
            console.log("Notification Triggred")
        }

//        onNotificationOpened: {
//            console.log("notification clicked")
//        }

        // message clicked is not supported on macOS

        // action on notification
        // Set Open or visible after setting all params on notification

        // hide notification

        // silent notification (visible property)

        // set timer - property
        // get onTimeout signals

        // time interval property for background service

    }
}
