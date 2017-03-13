import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.2

Item {
    id: page
    width: 480
    height: 680

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
                color: "#9a7373"
                width: 100
                height: 100
            }
            Rectangle {
                id: cell2
                color: "#9a7373"
                width: 100
                height: 100
            }

            Rectangle {
                id: cell3
                width: 100
                height: 100
                color: "#9a7373"
            }

            Rectangle {
                id: cell4
                width: 100
                height: 100
                color: "#9a7373"
            }

            Rectangle {
                id: cell5
                width: 100
                height: 100
                color: "#9a7373"
            }

            Rectangle {
                id: cell6
                width: 100
                height: 100
                color: "#9a7373"
            }

            Rectangle {
                id: cell7
                width: 100
                height: 100
                color: "#9a7373"
            }

            Rectangle {
                id: cell8
                width: 100
                height: 100
                color: "#9a7373"
            }

            Rectangle {
                id: cell9
                width: 100
                height: 100
                color: "#9a7373"
            }

            Rectangle {
                id: cell10
                width: 100
                height: 100
                color: "#9a7373"
            }

            Rectangle {
                id: cell11
                width: 100
                height: 100
                color: "#9a7373"
            }

            Rectangle {
                id: cell12
                width: 100
                height: 100
                color: "#9a7373"
            }

            Rectangle {
                id: cell13
                width: 100
                height: 100
                color: "#9a7373"
            }

            Rectangle {
                id: cell14
                width: 100
                height: 100
                color: "#9a7373"
            }

            Rectangle {
                id: cell15
                width: 100
                height: 100
                color: "#9a7373"
            }

            Rectangle {
                id: cell16
                width: 100
                height: 100
                color: "#9a7373"
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
