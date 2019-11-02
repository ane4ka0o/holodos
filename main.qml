import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQml.Models 2.12
Window {
    visible: true
    width: 300
    height: 480
    title: qsTr("Holodos")

    TableView {
        id: mdl
        model: myModel
//        delegate: Text { text: "Animal: " + type + ", " + size }
    }


    Button {
        text: "Добавить"
        onClicked: myModel.insertRows(0, 1)
        //setData({row: 0, column: 0}, "A", "display")
    }
}
