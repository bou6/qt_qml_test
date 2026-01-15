import QtQuick
import QtQuick.Controls

Item {
    property var serviceId
    signal backClicked()

    property int serviceRectangleWidth: 600
    property int numberRectanglrWidth: 400
    property int rectangleHeight:100

    Text {
        id: serviceIdDisplay
        text: "Service ID: " + (serviceId || "N/A")
        font.pointSize: 12
        font.bold: true
        color: "darkblue"
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.margins: 10
    }

    Row {
        id: topRow
        anchors.top: serviceIdDisplay.bottom
        anchors.topMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 5

        Rectangle {
            id: mRect1
            width: serviceRectangleWidth
            height: rectangleHeight
            color: "beige"
            border.color: "yellow"

            Text {
                id: mText1
                anchors.centerIn: parent
                text: passport.service_name
                font.pointSize: 20
            }
        }

        Rectangle {
            id: mRect2
            width: numberRectanglrWidth
            height: rectangleHeight
            color: "beige"
            border.color: "yellow"

            Text {
                id: mText2
                anchors.centerIn: parent
                text: passport.service_number
                font.pointSize: 20
            }
        }
    }

    Row {
        id: bottomRow
        anchors.top: topRow.bottom
        anchors.topMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 5

        Rectangle {
            id: mRect3
            width: serviceRectangleWidth
            height: rectangleHeight
            color: "lightblue"
            border.color: "blue"

            Text {
                id: mText3
                anchors.centerIn: parent
                text: driverLicense.service_name
                font.pointSize: 20
            }
        }

        Rectangle {
            id: mRect4
            width: numberRectanglrWidth
            height: rectangleHeight
            color: "lightblue"
            border.color: "blue"

            Text {
                id: mText4
                anchors.centerIn: parent
                text: driverLicense.service_number
                font.pointSize: 20
            }
        }
    }

    Button {
        id: backButton
        text: "← Back"
        width: 120
        height: 45
        
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottomMargin: 20
        
        font.pointSize: 14
        font.bold: true
        
        background: Rectangle {
            color: backButton.pressed ? "#2c5aa0" : "#4a7abd"
            border.color: "#1e3a5f"
            border.width: 2
            radius: 8
        }
        
        contentItem: Text {
            text: backButton.text
            color: "white"
            font: backButton.font
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
        
        onClicked: backClicked()
    }

}
