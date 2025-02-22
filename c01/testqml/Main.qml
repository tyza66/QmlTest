import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: "弹出框示例"

    Button {
        text: "Show Dialog"
        anchors.centerIn: parent
        onClicked: dialog.open()
    }

    Dialog {
        id: dialog
        title: "这是一个弹出框"
        standardButtons: Dialog.Ok | Dialog.Cancel
        onAccepted: console.log("Dialog accepted")
        onRejected: console.log("Dialog rejected")

        contentItem: Column {
            spacing: 10
            Label {
                text: "你好,世界"
            }
            TextField {
                placeholderText: "Enter some text"
            }
        }
    }
}
