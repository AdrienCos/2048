import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2

ApplicationWindow {
    visible: true
    width: 500
    height: 720
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
            MenuItem{
                text: qsTr("Save Game")
                onTriggered: vueJeu.saveGame();
            }
            MenuItem{
                text: qsTr("Load Game")
                onTriggered: vueJeu.loadGame();
            }
        }
        Menu {
            title: qsTr("Help")
            MenuItem {
                text: qsTr ("How to play")
                onTriggered: {
                    messageDialog.title = qsTr("How to play")
                    messageDialog.show(qsTr("Use the arrow keys or the ZQSD keys to move the tiles around.
When to tiles of identical value collide, they merge into a tile of twice the value.
After each move, a new tile will apprear on the board, either 2 or a 4.

Try to reach the 2048 tile ! Good luck"))
                }
            }

            MenuItem {
                text : qsTr("About...")
                onTriggered: {
                    messageDialog.title = qsTr("About...")
                    messageDialog.show(qsTr("Game created by Alexandre Cartier and Adrien Cosson \nBased on 2048 by Gabriel Cirulli, a clone of 1024.\nhttps://github.com/AdrienCos/2048"))
                }
            }
        }
    }

    MainForm {
        anchors.fill: parent

        // Gestion du bouton New Game
        boutonNewGame.onClicked: vueJeu.newGame(4,4)
        boutonNewGame.onEntered: newGame.color = "#af4804"
        boutonNewGame.onExited: newGame.color = "#894804"
        boutonNewGame.onPressed: newGame.color = "#794804"
        boutonNewGame.onReleased: newGame.color = "#af4804"


        // Gestion du bouton Undo
        boutonUndo.onClicked: vueJeu.undo()
        boutonUndo.onEntered: undo.color = "#af4804"
        boutonUndo.onExited: undo.color = "#894804"
        boutonUndo.onPressed: undo.color = "#794804"
        boutonUndo.onReleased: undo.color = "#af4804"

        // Gestion du bouton Swap Colors
        boutonSwapColor.onClicked: vueJeu.swapColors()
        boutonSwapColor.onEntered: swapColor.color = "#af4804"
        boutonSwapColor.onExited: swapColor.color = "#894804"
        boutonSwapColor.onPressed: swapColor.color = "#794804"
        boutonSwapColor.onReleased: swapColor.color = "#af4804"


        // Gestion des touches fléchées
        Keys.onPressed:{
            switch (event.key) {
            case Qt.Key_Left:
                vueJeu.deplGauche();
                //console.log("bouton gauche presse");
                break;
            case Qt.Key_Right:
                vueJeu.deplDroite();
                //console.log("bouton droit presse");
                break;
            case Qt.Key_Up:
                vueJeu.deplHaut();
                //console.log("bouton haut presse");
                break;
            case Qt.Key_Down:
                vueJeu.deplBas();
                //console.log("bouton bas presse")
                break;
            case Qt.Key_Q:
                vueJeu.deplGauche();
                //console.log("bouton gauche presse");
                break;
            case Qt.Key_D:
                vueJeu.deplDroite();
                //console.log("bouton droit presse");
                break;
            case Qt.Key_Z:
                vueJeu.deplHaut();
                //console.log("bouton haut presse");
                break;
            case Qt.Key_S:
                vueJeu.deplBas();
                //console.log("bouton bas presse")
                break;
            case Qt.Key_Escape:
                Qt.quit();
            }
        }

        // Gestion des textes des scores
        best_score.text: vueJeu.states[33]
        resultat_jeu.text: vueJeu.states[32]


        // Désactivation des boutons quand l'écran de Game Over est présent
        boutonNewGame.enabled: !vueJeu.perdu
        boutonUndo.enabled: !vueJeu.perdu
        boutonSwapColor.enabled: !vueJeu.perdu
    }

    Rectangle {     // la page de game over est mise ici pour conserver un fichier.ui éditable
        id: gameOver
        color: "#f0ca81"
        visible: true
        opacity: 0.0
        anchors.fill: parent

        Text {
            id: textGameOver
            text: "Game Over !"
            anchors.verticalCenterOffset: -60
            font.italic: false
            font.bold: true
            font.family: "Verdana"
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            font.pixelSize: 60

            Text {
                id: textTryAgain
                x: 14
                text: qsTr(" Try again ?")
                anchors.top: parent.top
                anchors.topMargin: 60
                font.bold: true
                anchors.horizontalCenter: parent.horizontalCenter
                font.pixelSize: 60
            }
        }
        Rectangle {
            id: retry
            x: 360
            width: 150
            height: 80
            color: "#894804"
            radius: 6
            border.color: "#00000000"
            anchors.verticalCenter: parent.verticalCenter
            anchors.verticalCenterOffset : 110
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.horizontalCenterOffset: -100
            Behavior on color { ColorAnimation {duration : 150}}

            Text {
                id: textRetry
                color: "#ffffff"
                text: qsTr("Try Again")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                anchors.fill: parent
                font.bold: true
                font.pixelSize: 25
            }

            MouseArea {
                id: boutonRetry
                anchors.fill: parent
                hoverEnabled: true // on active la détection du passage de la souris
                enabled: vueJeu.perdu
                onClicked: vueJeu.newGame(4,4)
                onEntered: retry.color = "#af4804"
                onExited: retry.color = "#894804"
                onPressed: retry.color = "#794804"
                onReleased: retry.color = "#af4804"
            }
        }
        Rectangle {
            id: quit
            x: 360
            width: 150
            height: 80
            color: "#894804"
            radius: 6
            border.color: "#00000000"
            anchors.verticalCenter: parent.verticalCenter
            anchors.verticalCenterOffset : 110
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.horizontalCenterOffset: 100
            Behavior on color { ColorAnimation {duration : 150}}

            Text {
                id: textQuit
                color: "#ffffff"
                text: qsTr("Exit")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                anchors.fill: parent
                font.bold: true
                font.pixelSize: 25
            }

            MouseArea {
                id: boutonQuit
                anchors.fill: parent
                hoverEnabled: true // on active la détection du passage de la souris
                enabled: vueJeu.perdu
                onClicked: Qt.quit()
                onEntered: quit.color = "#af4804"
                onExited: quit.color = "#894804"
                onPressed: quit.color = "#794804"
                onReleased: quit.color = "#af4804"
            }
        }
        states: [
            State {
                name : "GameOver"; when : vueJeu.perdu
                PropertyChanges {target: gameOver; opacity : 0.85 }
            },
            State {
                name: "noGameOver"; when: !vueJeu.perdu
                PropertyChanges {target: gameOver; opacity : 0.0 }
            }
        ]
        transitions: [
            Transition {
                from: "noGameOver"
                to: "GameOver"
                NumberAnimation { easing.amplitude: 1.5; properties: "opacity"; easing.type: Easing.OutBounce; duration: 1000 }
            },
            Transition {
                from: "GameOver"
                to: "noGameOver"
                NumberAnimation { properties: "opacity"; easing.type: Easing.Linear; duration: 100 }
            }
        ]
    }

    Dialog {
        id: messageDialog
        title: qsTr("May I have your attention, please?")
        height: 100
        width: 100
        Label {
            id:label
            text: "Hello blue sky!"
            color: "black"
            anchors.centerIn: parent
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 16
        }

        function show(caption) {
            label.text = caption;
            messageDialog.open();
        }
    }
}
