#include "mainwindow.h"

#include <QApplication>

#include "songlistdialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SongListDialog w;
    w.show();

    return a.exec();
}
