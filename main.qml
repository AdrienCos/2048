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
                    messageDialog.show(qsTr("Game created by Alexandre Cartier and Adrien Cosson"))
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
            case Qt.Key_P:      // demande de game over immédiat
                vueJeu.defaite();
                break;
            }
        }

        // Gestion des textes des scores
        best_score.text: vueJeu.states[33]
        resultat_jeu.text: vueJeu.states[32]

        // Gestion des textes des cells (sert surtout à clarifier l'interface graphique
        // d'édition de MainForm.ui.qml)
        //textCell0.text : vueJeu.states[0]
        //textCell0.color: (0xffffff - vueJeu.states[0])
//        textCell1.text : vueJeu.states[1]
//        textCell2.text : vueJeu.states[2]
//        textCell3.text : vueJeu.states[3]
//        textCell4.text : vueJeu.states[4]
//        textCell5.text : vueJeu.states[5]
//        textCell6.text : vueJeu.states[6]
//        textCell7.text : vueJeu.states[7]
//        textCell8.text : vueJeu.states[8]
//        textCell9.text : vueJeu.states[9]
//        textCell10.text : vueJeu.states[10]
//        textCell11.text : vueJeu.states[11]
//        textCell12.text : vueJeu.states[12]
//        textCell13.text : vueJeu.states[13]
//        textCell14.text : vueJeu.states[14]
//        textCell15.text : vueJeu.states[15]

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
