import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("services")


    Rectangle {
               id : mRect1
               width: mText1.implicitWidth + 20
               height: mText1.implicitHeight + 20
               color: "beige"
               border.color: "yellowgreen"

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
               width: mText2.implicitWidth + 20
               height: mText2.implicitHeight + 20
               color: "beige"
               border.color: "yellowgreen"

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
               width: mText3.implicitWidth + 20
               height: mText3.implicitHeight + 20
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
               width: mText4.implicitWidth + 20
               height: mText4.implicitHeight + 20
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
