import QtQuick
import QtQuick.Controls

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("services")

    StackView {
          id: stack
          anchors.fill: parent
          //initialItem: HomePage {}

          function openServicesPage(id)
          {
              push("ServicesPage.qml", {serviceId:id})
          }
    }

    Component.onCompleted: {
        stack.push("HomePage.qml")
    }

    Connections {
        target: stack.currentItem
        function onNextClicked(id) {
            stack.openServicesPage(id)
        }

        function onBackClicked() {
            stack.pop()
        }
    }

}
