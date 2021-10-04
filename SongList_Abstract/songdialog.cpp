#include "songdialog.h"
#include "ui_songdialog.h"
#include <QFileDialog>

SongDialog::SongDialog(QWidget* parent): QDialog(parent), m_ui(new Ui::SongDialog())
{
	m_ui->setupUi(this);
    connect(m_ui->btnPreview, &QPushButton::clicked, this, &SongDialog::choosePreview); // если нажали на плюс - тогда choosePreview

    QDir dir;
	if (!dir.exists(m_imageDir))
		dir.mkpath(m_imageDir);
}

SongDialog::~SongDialog()
{
	delete m_ui;
}

void SongDialog::choosePreview()
{ // открывается при нажатии на плюс, могу тут получить путь до картинки
	const auto filename = QFileDialog::getOpenFileName(this, tr("Выберите изображение"),
		QString(), "(*.jpeg *.jpg *png *gif)");
	if (filename.isEmpty())
        return;

	const QString copyName = copiedPreview(filename);

    str_path_img = filename;

    showPreview(copyName);
}

QString SongDialog::copiedPreview(const QString& filePath) const
{ // копирует картинку из label - называет ее 1.png - добавляет в папку с проектом

    const QImage image(filePath); // нужно для создания картинки - которую можно уменьшить
	const auto smaller = image.scaled(m_ui->labelPreview->width(), m_ui->labelPreview->height(),
        Qt::AspectRatioMode::KeepAspectRatioByExpanding); // делаем картинку меньше (подгоняем размер)

    QString name = "1.png"; // тут сохраняется картика
    if (!smaller.save(fullImagePath(name), "PNG"))
        return QString();

    return  name;
	
}

void SongDialog::showPreview(const QString& relativePath) const
{ // путь до изображения "fn"

	if (relativePath.isEmpty())
		return;

    const auto fn = fullImagePath(relativePath); // полный путь до картинки

    if (!QFile::exists(fn))
		return;

	const QPixmap pixmap(fn);	
    m_ui->labelPreview->setPixmap(pixmap); // установка изображениея в label
}


QString SongDialog::fullImagePath(const QString& relativePath) const
{
	QDir dir;
	dir.cd(m_imageDir);

    return dir.absoluteFilePath(relativePath);
}

void SongDialog::on_pushButton_ok_clicked()
{ // кнопка "ok" - считывает данные и передает в модель

    QString name = m_ui->lineEdit_name->text(); // название трека
    QString performer = m_ui->lineEdit_performer->text(); // исполнитель
    QString lengh = m_ui->lineEdit_lengh->text(); // длина трека

    QString grade = QString::number(m_ui->horizontalSlider_grade->value()); // оценка
    emit send_data(str_path_img, name, performer, lengh, grade); // отправили данные


    m_ui->labelPreview->clear();
    m_ui->lineEdit_name->clear(); // название трека
    m_ui->lineEdit_performer->clear(); // исполнитель
    m_ui->lineEdit_lengh->clear(); // длина трека

    m_ui->horizontalSlider_grade->setValue(5);


    this->hide();
}


void SongDialog::on_pushButton_cancel_clicked()
{ // кнопка отмена - закрывает окно

    m_ui->labelPreview->clear();
    m_ui->lineEdit_name->clear(); // название трека
    m_ui->lineEdit_performer->clear(); // исполнитель
    m_ui->lineEdit_lengh->clear(); // длина трека

    m_ui->horizontalSlider_grade->setValue(5);

    this->hide();
}


