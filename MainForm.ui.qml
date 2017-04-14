import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.2
import QtQuick.Dialogs 1.2

Rectangle {
    id: page
    width: 480
    height: 680
    property alias swapColor: swapColor
    property alias boutonSwapColor: boutonSwapColor
    property alias textSwapColor: textSwapColor
    property alias cell11: cell11
    property alias resultat_jeu: resultat_jeu
    property alias best_score: best_score
    property alias boutonUndo: boutonUndo
    property alias textUndo: textUndo
    property alias undo: undo
    property alias boutonNewGame: boutonNewGame
    property alias instructions: instructions
    property alias titre2048: titre2048
    property alias textNewGame: textNewGame
    property alias newGame: newGame
    property alias textScore: textScore
    property alias score: score
    property alias textBest: textBest
    property alias best: best
    property alias cell16: cell16
    property alias cell15: cell15
    property alias cell14: cell14
    property alias cell13: cell13
    property alias cell12: cell12
    property alias cell10: cell10
    property alias cell9: cell9
    property alias cell8: cell8
    property alias cell7: cell7
    property alias cell6: cell6
    property alias cell5: cell5
    property alias cell4: cell4
    property alias cell3: cell3
    property alias cell2: cell2
    property alias cell1: cell1
    property alias grille: grille
    property alias game: game

    Rectangle {
        id: game
        x: 92
        y: 154
        width: 440
        height: 440
        color: "#685759"
        radius: 7
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 38
        anchors.horizontalCenter: parent.horizontalCenter
        focus: true         //très important, permet de selectionner la zone qui réagit au onPressed

        Grid {
            id: grille
            width: 424
            height: 424
            anchors.rightMargin: 8
            anchors.bottomMargin: 8
            anchors.leftMargin: 8
            anchors.topMargin: 8
            rows: 4
            opacity: 1
            spacing: 8
            anchors.fill: parent
            columns: 4

            Cell2 {
                id: cell1
                sensx: vueJeu.states[34]
                sensy: vueJeu.states[35]
                colorBack : vueJeu.states[16]
                textBack: vueJeu.states[0]

            }

            Cell2 {
                id: cell2
                sensx: vueJeu.states[34]
                sensy: vueJeu.states[35]
                colorBack: vueJeu.states[17]
                textBack: vueJeu.states[1]
            }

            Cell2 {
                id: cell3
                sensx: vueJeu.states[34]
                sensy: vueJeu.states[35]
                colorBack: vueJeu.states[18]
                textBack: vueJeu.states[2]
            }

            Cell2 {
                id: cell4
                sensx: vueJeu.states[34]
                sensy: vueJeu.states[35]
                colorBack: vueJeu.states[19]
                textBack: vueJeu.states[3]
            }

            Cell2 {
                id: cell5
                sensx: vueJeu.states[34]
                sensy: vueJeu.states[35]
                colorBack: vueJeu.states[20]
                textBack: vueJeu.states[4]
            }

            Cell2 {
                id: cell6
                sensx: vueJeu.states[34]
                sensy: vueJeu.states[35]
                colorBack: vueJeu.states[21]
                textBack: vueJeu.states[5]
            }

            Cell2 {
                id: cell7
                sensx: vueJeu.states[34]
                sensy: vueJeu.states[35]
                colorBack: vueJeu.states[22]
                textBack: vueJeu.states[6]
            }

            Cell2 {
                id: cell8
                sensx: vueJeu.states[34]
                sensy: vueJeu.states[35]
                colorBack: vueJeu.states[23]
                textBack: vueJeu.states[7]
            }

            Cell2 {
                id: cell9
                sensx: vueJeu.states[34]
                sensy: vueJeu.states[35]
                colorBack: vueJeu.states[24]
                textBack: vueJeu.states[8]
            }

            Cell2 {
                id: cell10
                sensx: vueJeu.states[34]
                sensy: vueJeu.states[35]
                colorBack: vueJeu.states[25]
                textBack: vueJeu.states[9]
            }

            Cell2 {
                id: cell11
                sensx: vueJeu.states[34]
                sensy: vueJeu.states[35]
                colorBack: vueJeu.states[26]
                textBack: vueJeu.states[10]
            }

            Cell2 {
                id: cell12
                sensx: vueJeu.states[34]
                sensy: vueJeu.states[35]
                colorBack: vueJeu.states[27]
                textBack: vueJeu.states[11]
            }

            Cell2 {
                id: cell13
                sensx: vueJeu.states[34]
                sensy: vueJeu.states[35]
                colorBack: vueJeu.states[28]
                textBack: vueJeu.states[12]
            }

            Cell2 {
                id: cell14
                sensx: vueJeu.states[34]
                sensy: vueJeu.states[35]
                colorBack: vueJeu.states[29]
                textBack: vueJeu.states[13]
            }

            Cell2 {
                id: cell15
                sensx: vueJeu.states[34]
                sensy: vueJeu.states[35]
                colorBack: vueJeu.states[30]
                textBack: vueJeu.states[14]
            }

            Cell2 {
                id: cell16
                sensx: vueJeu.states[34]
                sensy: vueJeu.states[35]
                colorBack: vueJeu.states[31]
                textBack: vueJeu.states[15]
            }
        }
    }

//    Cell2 {
//        id: celltest
//        x: 100
//        y: 300
//        sensx: "1"
//        sensy: "1"
//        colorBack: "#ad9b9e"
//        textBack: "2"
//        fontsize: 35
//    }
//    Cell2 {
//        id: celltest2
//        x: 300
//        y: 300
//        sensx: "1"
//        sensy: "1"
//        colorBack: "#ad9b9e"
//        textBack: "102"
//        fontsize: 35
//    }

    Rectangle {
        id: best
        width: 100
        height: 70
        color: "#ad9b9e"
        clip: false
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.right: parent.right
        anchors.rightMargin: 20

        Text {
            id: textBest
            color: "#ffffff"
            text: qsTr("Best")
            anchors.top: parent.top
            anchors.topMargin: 5
            anchors.horizontalCenter: parent.horizontalCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 19
        }

        Text {
            id: best_score
            text: "best score"
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 25
            anchors.top: parent.top
            anchors.horizontalCenterOffset: 0
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.topMargin: 30
        }
    }

    Rectangle {
        id: score
        width: 100
        height: 70
        color: "#ad9b9e"
        anchors.right: parent.right
        anchors.rightMargin: 130
        anchors.top: parent.top
        anchors.topMargin: 10

        Text {
            id: textScore
            width: 48
            height: 20
            color: "#ffffff"
            text: qsTr("Score")
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 19
            anchors.top: parent.top
            anchors.horizontalCenterOffset: 0
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.topMargin: 5
        }

        Text {
            id: resultat_jeu
            text: "score"
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 25
            anchors.top: parent.top
            anchors.horizontalCenterOffset: 0
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.topMargin: 30
        }
    }

    Text {
        id: titre2048
        width: 200
        height: 70
        color: "#3d3434"
        text: qsTr("2048")
        font.bold: true
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.left: parent.left
        anchors.leftMargin: 20
        font.pixelSize: 68
    }

    Text {
        id: instructions
        text: qsTr("Join the numbers and get a 2048 tile !")
        font.family: "Verdana"
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.top: parent.top
        anchors.topMargin: 117
        font.pixelSize: 18
    }

    Rectangle {
        id: undo
        x: 360
        width: 100
        height: 50
        color: "#894804"
        radius: 6
        border.color: "#00000000"
        border.width: 3
        anchors.top: parent.top
        anchors.topMargin: 150
        anchors.right: parent.right
        anchors.rightMargin: 20
        Behavior on color { ColorAnimation {duration : 150}}

        Text {
            id: textUndo
            color: "#ffffff"
            text: qsTr("Undo")
            font.bold: true
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            anchors.fill: parent
            font.pixelSize: 16
        }

        MouseArea {
            id: boutonUndo
            anchors.fill: parent
            hoverEnabled: true // on active la détection du passage de la souris
        }
    }

    Rectangle {
        id: newGame
        x: 360
        width: 100
        height: 50
        color: "#894804"
        radius: 6
        border.color: "#00000000"
        anchors.top: parent.top
        anchors.topMargin: 90
        anchors.right: parent.right
        anchors.rightMargin: 20
        Behavior on color { ColorAnimation {duration : 150}}

        Text {
            id: textNewGame
            color: "#ffffff"
            text: qsTr("New Game")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            anchors.fill: parent
            font.bold: true
            font.pixelSize: 16
        }

        MouseArea {
            id: boutonNewGame
            anchors.fill: parent
            hoverEnabled: true // on active la détection du passage de la souris
        }
    }

    Rectangle {
        id: swapColor
        x: 231
        width: 150
        height: 50
        color: "#894804"
        radius: 6
        border.color: "#00000000"
        anchors.top: parent.top
        anchors.topMargin: 150
        anchors.right: parent.right
        anchors.rightMargin: 130
        Behavior on color { ColorAnimation {duration : 150}}

        Text {
            id: textSwapColor
            color: "#ffffff"
            text: qsTr("Swap Colors")
            font.bold: true
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            anchors.fill: parent
            font.pixelSize: 16
        }

        MouseArea {
            id: boutonSwapColor
            hoverEnabled: true
            anchors.fill: parent
        }
    }
}
