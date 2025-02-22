import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import My.Backend 1.0 // 单例那个的引用形式

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Button {
        x:10
        y:10
        width: 100
        height: 50
        text: qsTr("backend")
        onClicked: {
            Backend.receive("Button 1 msg")   // 点击按钮1的时候调用单例那个的接收函数
        }
    }
    Button {
        x:120
        y:10
        width: 100
        height: 50
        text: qsTr("backend2")
        onClicked: {
            Backend2.receive("Button 2 msg") // 点击按钮的时候调用设置成QML的属性中那个的
        }
    }

    TextArea {
        id: textArea
        x: 10
        y: 70
        font.pointSize: 20
        placeholderText: qsTr("Msg Area")
    }

    Connections {
        target: Backend
        onMessage: {            // 监听单例那个的信号
            textArea.text = msg
        }
    }

    Connections {
        target: Backend2
        onMessage: {            // 监听引入那个的信号
            textArea.text = msg
        }
    }
}
