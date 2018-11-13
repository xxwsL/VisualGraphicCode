/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *Load;
    QLabel *label;
    QPushButton *Gray;
    QPushButton *Display;
    QPushButton *Threshold;
    QMenuBar *menuBar;
    QMenu *file;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(862, 739);
        MainWindow->setCursor(QCursor(Qt::ArrowCursor));
        MainWindow->setMouseTracking(false);
        MainWindow->setIconSize(QSize(24, 99));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Load = new QPushButton(centralWidget);
        Load->setObjectName(QStringLiteral("Load"));
        Load->setGeometry(QRect(620, 20, 75, 23));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 110, 791, 561));
        Gray = new QPushButton(centralWidget);
        Gray->setObjectName(QStringLiteral("Gray"));
        Gray->setGeometry(QRect(10, 20, 75, 23));
        Display = new QPushButton(centralWidget);
        Display->setObjectName(QStringLiteral("Display"));
        Display->setGeometry(QRect(700, 20, 75, 23));
        Threshold = new QPushButton(centralWidget);
        Threshold->setObjectName(QStringLiteral("Threshold"));
        Threshold->setGeometry(QRect(110, 20, 75, 23));
        MainWindow->setCentralWidget(centralWidget);
        label->raise();
        Gray->raise();
        Load->raise();
        Display->raise();
        Threshold->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 862, 26));
        file = new QMenu(menuBar);
        file->setObjectName(QStringLiteral("file"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(file->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "xxwsL_opencv", nullptr));
        Load->setText(QApplication::translate("MainWindow", "Load", nullptr));
#ifndef QT_NO_SHORTCUT
        Load->setShortcut(QApplication::translate("MainWindow", "Space", nullptr));
#endif // QT_NO_SHORTCUT
        label->setText(QString());
        Gray->setText(QApplication::translate("MainWindow", "Gray", nullptr));
        Display->setText(QApplication::translate("MainWindow", "Display", nullptr));
        Threshold->setText(QApplication::translate("MainWindow", "Threshold", nullptr));
        file->setTitle(QApplication::translate("MainWindow", "file", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
