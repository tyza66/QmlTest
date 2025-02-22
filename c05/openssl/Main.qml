import QtQuick 2.15
import QtQuick.Controls 2.15
import com.tyza66.crypto 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: "MD5 Encryption Example"

    CryptoUtils {
        id: cryptoUtils
    }

    TextField {
        id: inputText
        placeholderText: "Enter text to encrypt"
        width: 200
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 20
    }

    Button {
        text: "Encrypt"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: inputText.bottom
        anchors.topMargin: 10
        onClicked: {
            var encryptedText = cryptoUtils.md5(inputText.text); //
            encryptedLabel.text = encryptedText;
            dialog.open();
        }
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
