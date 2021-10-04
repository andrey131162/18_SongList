#pragma once
#include <QDialog>

namespace Ui 
{	
class SongDialog;
}

class SongDialog : public QDialog
{
	Q_OBJECT
public:
	SongDialog(QWidget* parent = nullptr);
	~SongDialog();

private slots:
    void on_pushButton_ok_clicked();

    void on_pushButton_cancel_clicked();

signals:

    void send_data(QString img_path, QString name, QString performer, QString lengh, QString grade); // считывает и отправляет данные

private:
	void choosePreview();

	QString copiedPreview(const QString& filePath) const;

	void showPreview(const QString& relativePath) const;

	QString fullImagePath(const QString& relativePath) const;
	
	Ui::SongDialog* m_ui = nullptr;
    const QString m_imageDir = "";


    QString str_path_img; // путь до картинки
};

