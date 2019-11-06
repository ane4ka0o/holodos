import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQml.Models 2.12


ApplicationWindow {
    visible: true
    width: 300
    height: 480
    title: qsTr("Holodos")

    StackView {
        id: stack
        anchors.fill: parent
        initialItem: MainPage {
            id: mainView
        }
    }
}

