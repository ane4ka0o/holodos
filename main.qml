import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQml.Models 2.12
Window {
    visible: true
    width: 300
    height: 480
    title: qsTr("Holodos")
    Rectangle{
        implicitHeight: 100
        color: "green"
        border.width: 2
        border.color: "black"

        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: addButton.top

        TableView {
            anchors.fill: parent
            model: myModel
            delegate: Rectangle {
                implicitWidth: 100
                implicitHeight: 50
                Text {
                    text: display
                }
            }
        }
    }

    Button {
        id: addButton
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        text: "Добавить"
        onClicked: myModel.insertRows(0, 1)
    }
}
