#include "songlistdialog.h"

#include "songdialog.h"
#include "ui_songlistdialog.h"

SongListDialog::SongListDialog(QWidget *parent): QDialog(parent)
{
	m_ui = new Ui::SongListDialog();
	m_ui->setupUi(this);

    connect(window_new_string, &SongDialog::send_data, my_model, &My_model_abstract::add_row); // передача данных из окна создания в главное

    connect(window_change_string, &SongDialog::send_data, my_model, &My_model_abstract::change_row); // передача из окна изменения в главное

    connect(this, &SongListDialog::send_current_string, my_model, &My_model_abstract::set_current_row);

    m_ui->tableView->setModel(my_model); // установка моей модели в tableView

    m_ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers); // запрет прямого редактирования

    m_ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch); // на всю длину таблицы
    m_ui->tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    m_ui->tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
    m_ui->tableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);


    m_ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows); // выделяет всю строку выбранную
}

SongListDialog::~SongListDialog()
{
	delete m_ui;
}

void SongListDialog::on_btnCreate_clicked()
{
    window_new_string->show();
}

void SongListDialog::on_pushButton_change_clicked()
{ // кнопка редактирования
    window_change_string->show();
}


void SongListDialog::on_pushButton_2_clicked()
{ // кнопка сохранения

}


void SongListDialog::on_tableView_clicked(const QModelIndex &index)
{ // отслеживание клика - нужно передать номер текущей строки тут
    emit send_current_string(index.row());
}


void SongListDialog::on_tableView_doubleClicked(const QModelIndex &index)
{ // запуск редактирования по двойному клику
    window_change_string->show();
}

