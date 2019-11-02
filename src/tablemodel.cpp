
#include "tablemodel.h"


//! [0]
HolodosTableModel::HolodosTableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}



HolodosTableModel::HolodosTableModel(QList<Food> foods, QObject *parent)
    : QAbstractTableModel(parent)
    , foods(foods)
{
}

HolodosTableModel::~HolodosTableModel()
{

}
//! [0]

//! [1]
int HolodosTableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return foods.size();
}

int HolodosTableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return 2;
}
//! [1]

//! [2]
QVariant HolodosTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >= foods.size() || index.row() < 0)
        return QVariant();

    if (role == Qt::DisplayRole) {
        const auto &food = foods.at(index.row());

        if (index.column() == 0)
            return food.name;
        else if (index.column() == 1)
            return food.shelfLife;
    }
    return QVariant();
}
//! [2]

//! [3]
QVariant HolodosTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
            case 0:
                return tr("Название");

            case 1:
                return tr("Срок Годности");

            default:
                return QVariant();
        }
    }
    return QVariant();
}
//! [3]

//! [4]
bool HolodosTableModel::insertRows(int position, int rows, const QModelIndex &index)
{
    Q_UNUSED(index);
    beginInsertRows(QModelIndex(), position, position + rows - 1);

    for (int row = 0; row < rows; ++row)
        foods.insert(position, { QString(), QString() });

    endInsertRows();
    return true;
}
//! [4]

//! [5]
bool HolodosTableModel::removeRows(int position, int rows, const QModelIndex &index)
{
    Q_UNUSED(index);
    beginRemoveRows(QModelIndex(), position, position + rows - 1);

    for (int row = 0; row < rows; ++row)
        foods.removeAt(position);

    endRemoveRows();
    return true;
}
//! [5]

//! [6]
bool HolodosTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole) {
        int row = index.row();

        auto food = foods.value(row);

        if (index.column() == 0)
            food.name = value.toString();
        else if (index.column() == 1)
            food.shelfLife = value.toString();
        else
            return false;

//        foods.replace(row, contact);
        emit dataChanged(index, index, {role});

        return true;
    }

    return false;
}
//! [6]

//! [7]
Qt::ItemFlags HolodosTableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}
//! [7]

//! [8]
QList<Food> HolodosTableModel::getFood() const
{
    return foods;
}
//! [8]

