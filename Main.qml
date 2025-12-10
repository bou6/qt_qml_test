import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("services")

    property int serviceRectangleWidth: 400
    property int numberRectanglrWidth: 100
    property int rectangleHeight:50


    Rectangle {
               id : mRect1
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
               id : mRect2
               anchors.left: mRect1.right
               anchors.leftMargin: 5
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

    Rectangle {
               id : mRect3
               anchors.top: mRect1.bottom
               anchors.topMargin: 10
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
               id : mRect4
               anchors.left: mRect3.right
               anchors.leftMargin: 5
               anchors.top: mRect2.bottom
               anchors.topMargin: 10
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
