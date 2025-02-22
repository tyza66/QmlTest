import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: "New Window QML"

    Column {
        anchors.centerIn: parent

        Label {
            text: "This is the QML content of the new window!"
        }

        Button {
            text: "Close"
            onClicked: {
                Qt.quit();
            }
        }
    }
}
