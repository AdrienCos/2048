import QtQuick 2.0
import QtGraphicalEffects 1.0

Flipable {
    id: flipable
    height: 100
    width: 100

    property int animDuration : 150 // durée d'animation
    property int animDurationBis : 150
    property string textBack
    property string colorBack
    property string sensx: "-1"      // rotation selon l'axe x
    property string sensy: "0"      // rotation selon l'axe y

    onColorBackChanged: showBack()

    function showBack()
    {
        rotation.angle=180;     // premiere rotation
        timer.running = true;   // lancement du timer
    }
    function showFront()
    {
        rotation.angle=0;
    }

    front: Rectangle {
        id: rectFront
        width: 100
        height: 100
        color: "#b48f8f"
        radius: 6

        Text { id: textFrontID; text: " " ; anchors.centerIn: parent; font.pixelSize: 38 }  // texte inital        
    }

    back: Rectangle {
        id: rectBack
        width: 100
        height: 100
        color: flipable.colorBack
        radius: 6

        Text { id: textBackID; text: flipable.textBack ; anchors.centerIn: parent; font.pixelSize: 38 }     // nouveau texte

    }

    Timer{
        id:timer
        running:false
        repeat: false
        interval: flipable.animDuration         // duree d'attente avant la seconde animation
        onTriggered: {
            textFrontID.text = textBackID.text      // on remplace la nouvelle valeur de front
            rectFront.color = rectBack.color
            flipable.animDuration = 0           // on cache la seconde rotation
            rotation.angle=0                    // seconde rotation
            flipable.animDuration = flipable.animDurationBis    // on reset la valeur du temps de rotation
        }
    }

    transform: Rotation {
        id: rotation
        origin.x: flipable.width/2
        origin.y: flipable.height/2
        axis.x: flipable.sensx; axis.y: flipable.sensy; axis.z: 0     // set axis.y to 1 to rotate around y-axis
        angle: 0    // the default angle
        Behavior on angle { PropertyAnimation{ duration: flipable.animDuration }}
    }
}

