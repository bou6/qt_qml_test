import QtQuick
import QtQuick.Controls

Item {
    id: homePage
    width: parent ? parent.width : 400
    height: parent ? parent.height : 300

    signal nextClicked(string id)

    Column {
        anchors.centerIn: parent
        spacing: 12

        TextField {
            id: idInput
            placeholderText: "Enter your ID"
            width: 200
        }

        Button {
            text: "Next"
            onClicked: {
                homePage.nextClicked(idInput.text)
            }
        }
    }
}
