import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.2
import QtQuick.Dialogs 1.2

Rectangle {
    id: page
    width: 480
    height: 680
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
    property alias cell11: cell11
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
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 38
        anchors.horizontalCenter: parent.horizontalCenter
        //focus: vueJeu.resume                 //très important, permet de selectionner la zone qui réagit au onPressed
        focus : true

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





            Rectangle {
                id: cell1
                color: vueJeu.states[16]
                radius: 6
                width: 100
                height: 100

                Text {
                    id: textCell0
                    text: vueJeu.states[0]
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                    font.pixelSize: 35

                }

            }
            Rectangle {
                id: cell2
                color: vueJeu.states[17]
                radius: 6
                width: 100
                height: 100

                Text {
                    id: textCell1
                    text: vueJeu.states[1]
                    font.pixelSize: 35
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter


                }
            }

            Rectangle {
                id: cell3
                width: 100
                height: 100
                color: vueJeu.states[18]
                radius: 6

                Text {
                    id: textCell2
                    text: vueJeu.states[2]
                    font.pixelSize: 35
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                }
            }

            Rectangle {
                id: cell4
                width: 100
                height: 100
                color: vueJeu.states[19]
                radius: 6

                Text {
                    id: textCell3
                    text: vueJeu.states[3]
                    font.pixelSize: 35
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                }
            }

            Rectangle {
                id: cell5
                width: 100
                height: 100
                color: vueJeu.states[20]
                radius: 6

                Text {
                    id: textCell4
                    text: vueJeu.states[4]
                    font.pixelSize: 35
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                }
            }

            Rectangle {
                id: cell6
                width: 100
                height: 100
                color: vueJeu.states[21]
                radius: 6

                Text {
                    id: textCell5
                    text: vueJeu.states[5]
                    font.pixelSize: 35
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                }
            }

            Rectangle {
                id: cell7
                width: 100
                height: 100
                color: vueJeu.states[22]
                radius: 6

                Text {
                    id: textCell6
                    text: vueJeu.states[6]
                    font.pixelSize: 35
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                }
            }

            Rectangle {
                id: cell8
                width: 100
                height: 100
                color: vueJeu.states[23]
                radius: 6

                Text {
                    id: textCell7
                    text: vueJeu.states[7]
                    font.pixelSize: 35
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                }
            }

            Rectangle {
                id: cell9
                width: 100
                height: 100
                color: vueJeu.states[24]
                radius: 6

                Text {
                    id: textCell8
                    text: vueJeu.states[8]
                    font.pixelSize: 35
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                }
            }

            Rectangle {
                id: cell10
                width: 100
                height: 100
                color: vueJeu.states[25]
                radius: 6

                Text {
                    id: textCell9
                    text: vueJeu.states[9]
                    font.pixelSize: 35
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                }
            }

            Rectangle {
                id: cell11
                width: 100
                height: 100
                color: vueJeu.states[26]
                radius: 6

                Text {
                    id: textCell10
                    text: vueJeu.states[10]
                    font.pixelSize: 35
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                }
            }

            Rectangle {
                id: cell12
                width: 100
                height: 100
                color: vueJeu.states[27]
                radius: 6

                Text {
                    id: textCell11
                    text: vueJeu.states[11]
                    font.pixelSize: 35
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                }
            }

            Rectangle {
                id: cell13
                width: 100
                height: 100
                color: vueJeu.states[28]
                radius: 6

                Text {
                    id: textCell12
                    text: vueJeu.states[12]
                    font.pixelSize: 35
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                }
            }

            Rectangle {
                id: cell14
                width: 100
                height: 100
                color: vueJeu.states[29]
                radius: 6

                Text {
                    id: textCell13
                    text: vueJeu.states[13]
                    font.pixelSize: 35
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                }
            }

            Rectangle {
                id: cell15
                width: 100
                height: 100
                color: vueJeu.states[30]
                radius: 6

                Text {
                    id: textCell14
                    text: vueJeu.states[14]
                    font.pixelSize: 35
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                }
            }

            Rectangle {
                id: cell16
                width: 100
                height: 100
                color: vueJeu.states[31]
                radius: 6

                Text {
                    id: textCell15
                    text: vueJeu.states[15]
                    font.pixelSize: 35
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                }
            }
        }
    }

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
            text: vueJeu.states[33]
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
            text: vueJeu.states[32]
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 25
            anchors.top: parent.top
            anchors.horizontalCenterOffset: 0
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.topMargin: 30
        }
    }

    Rectangle {
        id: newGame
        x: 360
        width: 100
        height: 50
        color: "#894804"
        anchors.top: parent.top
        anchors.topMargin: 90
        anchors.right: parent.right
        anchors.rightMargin: 20

        Text {
            id: textNewGame
            color: "#ffffff"
            text: qsTr("New Game")
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            font.bold: true
            font.pixelSize: 16
        }

        MouseArea {
            id: boutonNewGame
            anchors.fill: parent
            onClicked: vueJeu.newGame(4,4)
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
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.top: parent.top
        anchors.topMargin: 117
        font.pixelSize: 18
    }


}


