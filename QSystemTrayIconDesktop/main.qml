import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 1.2

import AlertBanner 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Button {
        id: button
        text: "Tap button"

        onClicked: {
            banner.alert({
                             message: "Hi Melbounre",
                             title  : "notification",
                         });

//            banner.alert({
//                                    caption: "Hi Melbounre",
//                                    title  : "notification",
//                                });
        }
    }

    AlertBanner {
        id: banner
    }
}
