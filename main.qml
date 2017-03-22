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
                text : qsTr("A propos...")
                onTriggered: messageDialog.show(qsTr("Programme créé par Alexandre Cartier et Adrien Cosson"))
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
                console.log("bouton gauche presse");
                break;
            case Qt.Key_Right:
                vueJeu.deplDroite();
                console.log("bouton droit presse");
                break;
            case Qt.Key_Up:
                vueJeu.deplHaut();
                console.log("bouton haut presse");
                break;

            case Qt.Key_Down:
                vueJeu.deplBas();
                console.log("bouton bas presse")
                break;
            }
        }

        // Gestion des textes des scores
        best_score.text: vueJeu.states[33]
        resultat_jeu.text: vueJeu.states[32]

        // Gestion des textes des cells (sert surtout à clarifier l'interface graphique
        // d'édition de MainForm.ui.qml
        textCell0.text : vueJeu.states[0]
        textCell1.text : vueJeu.states[1]
        textCell2.text : vueJeu.states[2]
        textCell3.text : vueJeu.states[3]
        textCell4.text : vueJeu.states[4]
        textCell5.text : vueJeu.states[5]
        textCell6.text : vueJeu.states[6]
        textCell7.text : vueJeu.states[7]
        textCell8.text : vueJeu.states[8]
        textCell9.text : vueJeu.states[9]
        textCell10.text : vueJeu.states[10]
        textCell11.text : vueJeu.states[11]
        textCell12.text : vueJeu.states[12]
        textCell13.text : vueJeu.states[13]
        textCell14.text : vueJeu.states[14]
        textCell15.text : vueJeu.states[15]
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
        states: [
                    State {
                        name : "GameOver"; when : vueJeu.perdu
                        PropertyChanges {target: gameOver; opacity : 0.7 }
                    },
                    State {
                        name: "noGameOver"; when: !vueJeu.perdu
                        PropertyChanges {target: gameOver; opacity:0.0}
                    }
                ]
        transitions: [
            Transition {
                from: "noGameOver"
                to: "GameOver"
                NumberAnimation { properties: "opacity"; easing.type: Easing.InOutQuad; duration: 1000 }
            },
            Transition {
                from: "GameOver"
                to: "noGameOver"
                NumberAnimation { properties: "opacity"; easing.type: Easing.Linear; duration: 100 }
            }
        ]
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
