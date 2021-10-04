#pragma once
#include <QDialog>

#include "my_model_abstract.h"
#include "songdialog.h"

namespace Ui 
{
class SongListDialog;
}


class SongListDialog : public QDialog 
{
Q_OBJECT

public:
	SongListDialog(QWidget *parent = nullptr);
	~SongListDialog();

public slots:
	void on_btnCreate_clicked();

signals:
    void send_current_string(int current); // отправляет текущую строку

private slots:
    void on_pushButton_change_clicked();

    void on_pushButton_2_clicked();

    void on_tableView_clicked(const QModelIndex &index); // обычный клик - сохраняет номер выбранной строки

    void on_tableView_doubleClicked(const QModelIndex &index); // запуск редактирования по двойному клику

private:
	Ui::SongListDialog* m_ui = nullptr;

    My_model_abstract *my_model = new My_model_abstract(5); // указатель на мою модель с 5 столбцами

    SongDialog *window_new_string = new SongDialog(); // указатель на окно добавления строки
    SongDialog *window_change_string = new SongDialog(); // указатель на окно добавления строки

};
