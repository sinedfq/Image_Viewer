/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *action_2;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QFrame *menuFrame;
    QGridLayout *gridLayout;
    QPushButton *openDatabaseButton;
    QPushButton *createDatabaseButton;
    QTextBrowser *textBrowser;
    QPushButton *deleteAlbumButton;
    QListWidget *databaseListWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayoutButtons;
    QPushButton *addPhotoButton;
    QPushButton *deletePhotoButton;
    QPushButton *prevPhotoButton;
    QPushButton *nextPhotoButton;
    QListWidget *listWidget;
    QPushButton *sortDownButton;
    QPushButton *sortUpButton;
    QLabel *imageLabel;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1916, 980);
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        MainWindow->setMouseTracking(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../Downloads/ic_photo_album_128_28567.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        menuFrame = new QFrame(centralwidget);
        menuFrame->setObjectName(QString::fromUtf8("menuFrame"));
        menuFrame->setMinimumSize(QSize(0, 178));
        gridLayout = new QGridLayout(menuFrame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        openDatabaseButton = new QPushButton(menuFrame);
        openDatabaseButton->setObjectName(QString::fromUtf8("openDatabaseButton"));

        gridLayout->addWidget(openDatabaseButton, 3, 0, 1, 1);

        createDatabaseButton = new QPushButton(menuFrame);
        createDatabaseButton->setObjectName(QString::fromUtf8("createDatabaseButton"));
        createDatabaseButton->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(createDatabaseButton, 2, 0, 1, 1);

        textBrowser = new QTextBrowser(menuFrame);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setMaximumSize(QSize(16777215, 30));
        textBrowser->setTabChangesFocus(false);
        textBrowser->setUndoRedoEnabled(false);

        gridLayout->addWidget(textBrowser, 0, 0, 1, 1);

        deleteAlbumButton = new QPushButton(menuFrame);
        deleteAlbumButton->setObjectName(QString::fromUtf8("deleteAlbumButton"));
        deleteAlbumButton->setMinimumSize(QSize(0, 30));
        deleteAlbumButton->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(deleteAlbumButton, 4, 0, 1, 1);

        databaseListWidget = new QListWidget(menuFrame);
        databaseListWidget->setObjectName(QString::fromUtf8("databaseListWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(databaseListWidget->sizePolicy().hasHeightForWidth());
        databaseListWidget->setSizePolicy(sizePolicy);
        databaseListWidget->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(databaseListWidget, 1, 0, 1, 1);


        horizontalLayout->addWidget(menuFrame);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayoutButtons = new QHBoxLayout();
        horizontalLayoutButtons->setObjectName(QString::fromUtf8("horizontalLayoutButtons"));
        addPhotoButton = new QPushButton(centralwidget);
        addPhotoButton->setObjectName(QString::fromUtf8("addPhotoButton"));

        horizontalLayoutButtons->addWidget(addPhotoButton);

        deletePhotoButton = new QPushButton(centralwidget);
        deletePhotoButton->setObjectName(QString::fromUtf8("deletePhotoButton"));

        horizontalLayoutButtons->addWidget(deletePhotoButton);

        prevPhotoButton = new QPushButton(centralwidget);
        prevPhotoButton->setObjectName(QString::fromUtf8("prevPhotoButton"));

        horizontalLayoutButtons->addWidget(prevPhotoButton);

        nextPhotoButton = new QPushButton(centralwidget);
        nextPhotoButton->setObjectName(QString::fromUtf8("nextPhotoButton"));

        horizontalLayoutButtons->addWidget(nextPhotoButton);


        verticalLayout->addLayout(horizontalLayoutButtons);

        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setMinimumSize(QSize(900, 0));
        listWidget->setMaximumSize(QSize(16777215, 16777215));
        listWidget->setContextMenuPolicy(Qt::DefaultContextMenu);

        verticalLayout->addWidget(listWidget);

        sortDownButton = new QPushButton(centralwidget);
        sortDownButton->setObjectName(QString::fromUtf8("sortDownButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(sortDownButton->sizePolicy().hasHeightForWidth());
        sortDownButton->setSizePolicy(sizePolicy1);
        sortDownButton->setMaximumSize(QSize(400, 16777215));

        verticalLayout->addWidget(sortDownButton);

        sortUpButton = new QPushButton(centralwidget);
        sortUpButton->setObjectName(QString::fromUtf8("sortUpButton"));
        sortUpButton->setMaximumSize(QSize(400, 16777215));
        sortUpButton->setAutoFillBackground(false);

        verticalLayout->addWidget(sortUpButton);


        horizontalLayout->addLayout(verticalLayout);

        imageLabel = new QLabel(centralwidget);
        imageLabel->setObjectName(QString::fromUtf8("imageLabel"));
        imageLabel->setMinimumSize(QSize(700, 600));
        imageLabel->setMaximumSize(QSize(16777215, 16777215));
        imageLabel->setMouseTracking(true);
        imageLabel->setAutoFillBackground(false);
        imageLabel->setTextFormat(Qt::PlainText);
        imageLabel->setScaledContents(true);

        horizontalLayout->addWidget(imageLabel);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1916, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(action);
        menu->addAction(action_2);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Image Viewer", nullptr));
        action->setText(QApplication::translate("MainWindow", "\320\230\320\275\321\204\320\276", nullptr));
        action_2->setText(QApplication::translate("MainWindow", "\320\240\320\260\320\267\321\200\320\260\320\261\320\276\321\202\321\207\320\270\320\272", nullptr));
        openDatabaseButton->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \320\260\320\273\321\214\320\261\320\276\320\274", nullptr));
        createDatabaseButton->setText(QApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \321\204\320\276\321\202\320\276\320\260\320\273\321\214\320\261\320\276\320\274", nullptr));
        textBrowser->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:7.8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\241\320\277\320\270\321\201\320\276\320\272 \320\264\320\276\321\201\321\202\321\203\320\277\320\275\321\213\321\205 \321\204\320\276\321\202\320\276\320\260\320\273\321\214\320\261\320\276\320\274\320\276\320\262</p></body></html>", nullptr));
        deleteAlbumButton->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\260\320\273\321\214\320\261\320\276\320\274", nullptr));
        addPhotoButton->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\204\320\276\321\202\320\276", nullptr));
        deletePhotoButton->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\204\320\276\321\202\320\276", nullptr));
        prevPhotoButton->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\265\320\264\321\213\320\264\321\203\321\211\320\260\321\217 \321\204\320\276\321\202\320\276\320\263\321\200\320\260\321\204\320\270\321\217", nullptr));
        nextPhotoButton->setText(QApplication::translate("MainWindow", "\320\241\320\273\320\265\320\264\321\203\321\216\321\211\320\260\321\217 \321\204\320\276\321\202\320\276\320\263\321\200\320\260\321\204\320\270\321\217", nullptr));
        sortDownButton->setText(QApplication::translate("MainWindow", "\320\241\320\275\320\260\321\207\320\260\320\273\320\260 \320\275\320\276\320\262\321\213\320\265", nullptr));
        sortUpButton->setText(QApplication::translate("MainWindow", "\320\241\320\275\320\260\321\207\320\260\320\273\320\260 \321\201\321\202\320\260\321\200\321\213\320\265", nullptr));
        imageLabel->setText(QString());
        menu->setTitle(QApplication::translate("MainWindow", "\320\237\320\276\320\274\320\276\321\211\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
