#ifndef HOLODOS_TABLEMODEL_H
#define HOLODOS_TABLEMODEL_H

#include <QAbstractTableModel>
#include <QList>

//! [0]

struct Food
{
    QString name;
    QString shelfLife;

    bool operator==(const Food &other) const
    {
        return name == other.name && shelfLife == other.shelfLife;
    }
};

inline QDataStream &operator<<(QDataStream &stream, const Food &food)
{
    return stream << food.name << food.shelfLife;
}

inline QDataStream &operator>>(QDataStream &stream, Food &food)
{
    return stream >> food.name >> food.shelfLife;
}

class HolodosTableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    HolodosTableModel(QObject *parent = nullptr);
    HolodosTableModel(QList<Food> foods, QObject *parent = nullptr);
    ~HolodosTableModel() override;

    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    bool insertRows(int position, int rows, const QModelIndex &index = QModelIndex()) override;
    bool removeRows(int position, int rows, const QModelIndex &index = QModelIndex()) override;
    QList<Food> getFood() const;

private:
    QList<Food> foods;
};

//! [0]

#endif // HOLODOS_TABLEMODEL_H
