#ifndef MY_MODEL_ABSTRACT_H
#define MY_MODEL_ABSTRACT_H

#include <QAbstractTableModel>

#include <QImage>
#include <QPixmap>

class My_model_abstract : public QAbstractTableModel
{
    Q_OBJECT

public:
    My_model_abstract(int quantity_column); // определяет колличество столбцов

    int columnCount(const QModelIndex & parent) const override; // возвращает колличество столбцов
    int rowCount(const QModelIndex & parent) const override; // возвращает колличество строк

    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const override; // заполняет ячейки данными

    // для отображения заголовков
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override
    {
        //if (orientation == Qt::Horizontal)
        if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
        {
            switch(section) {
                    case 0:
                        return QString("Изображение");
                    case 1:
                        return QString("Название");
                    case 2:
                        return QString("Исполнитель");
                    case 3:
                        return QString("Длина");
                    case 4:
                        return QString("Оценка");
                    default:
                        return QVariant();
                }
            }

            return QVariant();
    }


public slots:

    void set_current_row(int current)
    {
        current_row = current;
    }

    void change_row (QString img_path, QString name, QString performer, QString lengh, QString grade)
    { // получаеn данные и вставляет их в текущую строку
        N[current_row][0] = img_path;
        N[current_row][1] = name;
        N[current_row][2] = performer;
        N[current_row][3] = lengh;
        N[current_row][4] = grade;
    }

    void add_row(QString img_path, QString name, QString performer, QString lengh, QString grade)
    { // слот - добавляющий строку
        beginInsertRows(QModelIndex(), 0, 0);

        List_string.clear(); // очистка листа и дальше заполнение новыми данными

        //List_string.append("D:/telephone.JPG"); // изображение
        List_string.append(img_path); // изображение

        List_string.append(name); // название трека
        List_string.append(performer); // исполнитель
        List_string.append(lengh); // длина
        List_string.append(grade); // оценка

        N.append(List_string); // добавление списка в структуру - вывод ее
        quantity_rows++;

        endInsertRows();
    }

private:
    int quantity_columns; // колличество столбцов
    int quantity_rows = 0; // колличество строк

    QVector<QList<QString>> N; // моя структура данных (вектор списков строк)

    QList<QString> List_string; // список строк (хранит данные одной строки)

    int current_row;
};

#endif // MY_MODEL_ABSTRACT_H
