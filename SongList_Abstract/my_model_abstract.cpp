#include "my_model_abstract.h"

My_model_abstract::My_model_abstract(int quantity_columns)
{ // конструктор моей модели - устанавливает колличество столбцов
    this->quantity_columns = quantity_columns; // установили колличестов столбцов

    //List_string.append("D:/telephone.JPG");
    //List_string.append("hello"); // добавление элементов в список - при создании модели
    //List_string.append("dog");
    //List_string.append("cat");
    //List_string.append("polka");

    //N.append(List_string); // добавление списка в структуру - вывод ее
    //quantity_rows++;

}

int My_model_abstract::columnCount(const QModelIndex & parent) const
{ // возвращает колличество столбцов
    return quantity_columns;
}

int My_model_abstract::rowCount(const QModelIndex & parent) const
{ // возвращает колличество строк
    return quantity_rows; // вернули колличество строк
}

QVariant My_model_abstract::data(const QModelIndex& index, int role) const
{ // метод заполняющий данными поля TableView

    if (role == Qt::DisplayRole)
    {
        const QList<QString> & duplicate = N[index.row()];
        switch (index.column())
        {
            //case 0: return duplicate[0]; // тут будет изображение
            case 1: return duplicate[1];
            case 2: return duplicate[2];
            case 3: return duplicate[3];
            case 4: return duplicate[4];
        }

    }


    if (role == Qt::DecorationRole)
    { // вывод изображений
        if (index.column() == 0)
        { // выводить картинку можно по адресу, и осталось адрес получать научиться из формы
            const QList<QString> & duplicate = N[index.row()];

            //QString polka = "D:/qt_project/15-songList./songList/imG/lol.png"; // так работало
            QString img = duplicate[0];
            QPixmap icon = QPixmap(img);
            QPixmap tmp = icon.scaled(50, 50, Qt::KeepAspectRatio); // 30 30
            QVariant value = tmp;
            return value;
        }

    }

    return QVariant();
}
