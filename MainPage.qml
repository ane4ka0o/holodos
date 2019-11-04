import QtQuick 2.12
import QtQuick.Controls 2.12

Page {
    id: mainView
    title: qsTr("Главная")

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
                border.width: 0.5
                border.color: "black"
                Text {
                    text: display
                }
            }
        }
    }
    Button {
        id: addButton
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: removeButton.left
        text: "Добавить"
        onClicked: stack.push(Qt.resolvedUrl("qrc:/CreateItemPage.qml"))
    }
    Button {
        id: removeButton
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.left: addButton.right
        text: "Удалить"
        onClicked: function() {
            var selectedRow = 0
            myModel.removeRows(selectedRow, 1)
        }
    }
}
