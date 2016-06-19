/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *browseButton;
    QComboBox *dirPath;
    QPushButton *findButton;
    QLabel *appLabel;
    QLabel *warningLabel;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(500, 321);
        MainWindow->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        browseButton = new QPushButton(centralWidget);
        browseButton->setObjectName(QStringLiteral("browseButton"));
        browseButton->setEnabled(true);
        browseButton->setGeometry(QRect(320, 110, 81, 31));
        browseButton->setStyleSheet(QStringLiteral(""));
        dirPath = new QComboBox(centralWidget);
        dirPath->setObjectName(QStringLiteral("dirPath"));
        dirPath->setGeometry(QRect(110, 110, 211, 31));
        dirPath->setStyleSheet(QStringLiteral(""));
        findButton = new QPushButton(centralWidget);
        findButton->setObjectName(QStringLiteral("findButton"));
        findButton->setGeometry(QRect(220, 170, 61, 32));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(findButton->sizePolicy().hasHeightForWidth());
        findButton->setSizePolicy(sizePolicy);
        findButton->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(91, 161, 248, 255), stop:1 rgba(14, 99, 254, 255));\n"
"color: white;\n"
"border-radius: 5px;\n"
""));
        appLabel = new QLabel(centralWidget);
        appLabel->setObjectName(QStringLiteral("appLabel"));
        appLabel->setGeometry(QRect(160, 40, 201, 51));
        appLabel->setMinimumSize(QSize(201, 51));
        appLabel->setMaximumSize(QSize(16777215, 51));
        appLabel->setStyleSheet(QLatin1String("background: transparent;\n"
"color: rgb(36, 100, 254);\n"
"font-weight: bold;\n"
"font-size: 30px;"));
        warningLabel = new QLabel(centralWidget);
        warningLabel->setObjectName(QStringLiteral("warningLabel"));
        warningLabel->setGeometry(QRect(190, 140, 181, 20));
        warningLabel->setStyleSheet(QLatin1String("color: red;\n"
"background: transparent;\n"
"text-align: center;"));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        browseButton->setText(QApplication::translate("MainWindow", "Browse", 0));
#ifndef QT_NO_TOOLTIP
        dirPath->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-style:italic; color:#737373;\">Choose the directory that you want to find images inside</span></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        findButton->setText(QApplication::translate("MainWindow", "FIND", 0));
        appLabel->setText(QApplication::translate("MainWindow", "Audio Finder", 0));
        warningLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" color:#ff0000;\"/></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
