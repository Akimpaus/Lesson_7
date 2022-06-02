/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *open;
    QAction *save;
    QAction *save_as;
    QAction *about_programm;
    QAction *exit;
    QAction *open_only_for_read;
    QAction *language_rus;
    QAction *language_eng;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QPlainTextEdit *plainTextEdit;
    QMenuBar *menubar;
    QMenu *file;
    QMenu *reference;
    QMenu *view;
    QMenu *language;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        open = new QAction(MainWindow);
        open->setObjectName(QString::fromUtf8("open"));
        save = new QAction(MainWindow);
        save->setObjectName(QString::fromUtf8("save"));
        save_as = new QAction(MainWindow);
        save_as->setObjectName(QString::fromUtf8("save_as"));
        about_programm = new QAction(MainWindow);
        about_programm->setObjectName(QString::fromUtf8("about_programm"));
        exit = new QAction(MainWindow);
        exit->setObjectName(QString::fromUtf8("exit"));
        open_only_for_read = new QAction(MainWindow);
        open_only_for_read->setObjectName(QString::fromUtf8("open_only_for_read"));
        language_rus = new QAction(MainWindow);
        language_rus->setObjectName(QString::fromUtf8("language_rus"));
        language_eng = new QAction(MainWindow);
        language_eng->setObjectName(QString::fromUtf8("language_eng"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));

        horizontalLayout->addWidget(plainTextEdit);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        file = new QMenu(menubar);
        file->setObjectName(QString::fromUtf8("file"));
        reference = new QMenu(menubar);
        reference->setObjectName(QString::fromUtf8("reference"));
        view = new QMenu(menubar);
        view->setObjectName(QString::fromUtf8("view"));
        language = new QMenu(view);
        language->setObjectName(QString::fromUtf8("language"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(file->menuAction());
        menubar->addAction(view->menuAction());
        menubar->addAction(reference->menuAction());
        file->addAction(open);
        file->addAction(open_only_for_read);
        file->addAction(save);
        file->addAction(save_as);
        file->addSeparator();
        file->addAction(exit);
        reference->addAction(about_programm);
        view->addAction(language->menuAction());
        language->addAction(language_rus);
        language->addAction(language_eng);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Text editor", nullptr));
        open->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        save->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        save_as->setText(QCoreApplication::translate("MainWindow", "Save as", nullptr));
        about_programm->setText(QCoreApplication::translate("MainWindow", "About programm", nullptr));
        exit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        open_only_for_read->setText(QCoreApplication::translate("MainWindow", "Open read-only", nullptr));
        language_rus->setText(QCoreApplication::translate("MainWindow", "Russian", nullptr));
        language_eng->setText(QCoreApplication::translate("MainWindow", "English", nullptr));
        file->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        reference->setTitle(QCoreApplication::translate("MainWindow", "Reference", nullptr));
        view->setTitle(QCoreApplication::translate("MainWindow", "View", nullptr));
        language->setTitle(QCoreApplication::translate("MainWindow", "Language", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
