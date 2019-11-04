import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Page{
    id: createItem
    title: qsTr("Создание продукта")
    Item{
        TextInput {
            id: itemName
        }
        Button{
            text: "Сохранить"
            onClicked: function(){
                myModel.addFood(itemName.text)
            }
        }
    }
}
