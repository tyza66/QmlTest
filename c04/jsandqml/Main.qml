import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: "Caesar Cipher Example"

    function caesarCipher(text, shift) {
        return text.split("").map(function(char1) {
            if (char1.match(/[a-z]/)) {
                return String.fromCharCode((char1.charCodeAt(0) - 97 + shift) % 26 + 97);
            } else if (char1.match(/[A-Z]/)) {
                return String.fromCharCode((char1.charCodeAt(0) - 65 + shift) % 26 + 65);
            } else {
                return char1;
            }
        }).join("");
    }

    Button {
        text: "Encrypt Message"
        anchors.centerIn: parent
        onClicked: {
            var encryptedText = caesarCipher(inputText.text, parseInt(shiftInput.text));
            encryptedLabel.text = encryptedText;
            dialog.open();
        }
    }

    TextField {
        id: inputText
        placeholderText: "Enter text to encrypt"
        width: 200
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 20
    }

    TextField {
        id: shiftInput
        placeholderText: "Enter shift value"
        width: 200
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: inputText.bottom
        anchors.topMargin: 10
    }

    Dialog {
        id: dialog
        title: "Encrypted Message"
        standardButtons: Dialog.Ok
        contentItem: Label {
            id: encryptedLabel
            text: "Encrypted message will appear here"
            wrapMode: Text.Wrap
        }
    }
}
