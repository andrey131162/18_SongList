/********************************************************************************
** Form generated from reading UI file 'songlistdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SONGLISTDIALOG_H
#define UI_SONGLISTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_SongListDialog
{
public:
    QGridLayout *gridLayout;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnCreate;
    QPushButton *pushButton_change;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *SongListDialog)
    {
        if (SongListDialog->objectName().isEmpty())
            SongListDialog->setObjectName(QString::fromUtf8("SongListDialog"));
        SongListDialog->resize(950, 500);
        gridLayout = new QGridLayout(SongListDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableView = new QTableView(SongListDialog);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout->addWidget(tableView, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnCreate = new QPushButton(SongListDialog);
        btnCreate->setObjectName(QString::fromUtf8("btnCreate"));

        horizontalLayout->addWidget(btnCreate);

        pushButton_change = new QPushButton(SongListDialog);
        pushButton_change->setObjectName(QString::fromUtf8("pushButton_change"));

        horizontalLayout->addWidget(pushButton_change);

        pushButton_2 = new QPushButton(SongListDialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


        retranslateUi(SongListDialog);

        QMetaObject::connectSlotsByName(SongListDialog);
    } // setupUi

    void retranslateUi(QDialog *SongListDialog)
    {
        SongListDialog->setWindowTitle(QString());
        btnCreate->setText(QCoreApplication::translate("SongListDialog", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214", nullptr));
        pushButton_change->setText(QCoreApplication::translate("SongListDialog", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        pushButton_2->setText(QCoreApplication::translate("SongListDialog", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SongListDialog: public Ui_SongListDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SONGLISTDIALOG_H
