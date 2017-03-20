import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2

ApplicationWindow {
    visible: true
    width: 480
    height: 680
    title: qsTr("Le 2048 d'Adrien et Alexandre")

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("New game")
                onTriggered: vueJeu.newGame(4,4)
            }
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
        Menu {
            title: qsTr("Help")
            MenuItem {
                text : qsTr("A propos...")
                onTriggered: messageDialog.show(qsTr("Programme créé par Alexandre Cartier et Adrien Cosson"))
            }
        }
    }

    MainForm {
        anchors.fill: parent
        //button1.onClicked: messageDialog.show(qsTr("Button 1 pressed"))
        //button2.onClicked: messageDialog.show(qsTr("Button 2 pressed"))
    }

    MessageDialog {
        id: messageDialog
        title: qsTr("May I have your attention, please?")

        function show(caption) {
            messageDialog.text = caption;
            messageDialog.open();
        }
    }
}
