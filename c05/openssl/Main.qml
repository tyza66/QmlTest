import QtQuick 2.15
import QtQuick.Controls 2.15
import com.openssl.crypto 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: "MD5 Encryption Example"

    CryptoOpenSSL {
        id: cryptoOpenSSL
    }

    Column {
        anchors.centerIn: parent

        TextField {
            id: inputText
            placeholderText: "Enter text to encrypt"
            width: 200
        }

        Button {
            text: "Encrypt"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: inputText.bottom
            anchors.topMargin: 10
            onClicked: {
                var encryptedText = cryptoOpenSSL.md5(inputText.text);
                encryptedLabel.text = encryptedText;
                dialog.open();
            }
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
