import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Page{
    property StackView stack
    id: createItem
    title: qsTr("Создание продукта")
    header: ToolBar {
        RowLayout {
            anchors.fill: parent
            ToolButton{
                text: qsTr("<")
                onClicked: stack.pop()
            }
        }
    }

    Button{
        text: "Сохранить"
        anchors.topMargin: 19
        anchors.top: textInput.bottom
        onClicked: function(){
            myModel.addFood(textInput.text)
            stack.pop()
        }
    }

    TextField {
        id: textInput
        placeholderText: qsTr("Название")
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.top: parent.top
        font.pixelSize: 12
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:5;anchors_height:20;anchors_width:80;anchors_x:0;anchors_y:0}
}
##^##*/
