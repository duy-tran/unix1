/********************************************************************************
** Form generated from reading UI file 'fileswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILESWINDOW_H
#define UI_FILESWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FilesWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *keywordLabel;
    QLineEdit *keywordText;
    QPushButton *searchButton;
    QTableWidget *filesTable;
    QPushButton *backButton;
    QLabel *statusLabel;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QLabel *sortLabel;
    QHBoxLayout *horizontalLayout;
    QComboBox *typeBox;
    QComboBox *orderBox;
    QPushButton *sortButton;

    void setupUi(QMainWindow *FilesWindow)
    {
        if (FilesWindow->objectName().isEmpty())
            FilesWindow->setObjectName(QStringLiteral("FilesWindow"));
        FilesWindow->resize(602, 382);
        FilesWindow->setStyleSheet(QStringLiteral(""));
        centralwidget = new QWidget(FilesWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(90, 10, 391, 33));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        keywordLabel = new QLabel(layoutWidget);
        keywordLabel->setObjectName(QStringLiteral("keywordLabel"));

        horizontalLayout_2->addWidget(keywordLabel);

        keywordText = new QLineEdit(layoutWidget);
        keywordText->setObjectName(QStringLiteral("keywordText"));

        horizontalLayout_2->addWidget(keywordText);

        searchButton = new QPushButton(layoutWidget);
        searchButton->setObjectName(QStringLiteral("searchButton"));

        horizontalLayout_2->addWidget(searchButton);

        filesTable = new QTableWidget(centralwidget);
        if (filesTable->columnCount() < 4)
            filesTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        filesTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        filesTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        filesTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        filesTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        filesTable->setObjectName(QStringLiteral("filesTable"));
        filesTable->setGeometry(QRect(20, 90, 561, 221));
        backButton = new QPushButton(centralwidget);
        backButton->setObjectName(QStringLiteral("backButton"));
        backButton->setGeometry(QRect(270, 350, 61, 21));
        backButton->setStyleSheet(QLatin1String("\n"
"border: 1px solid rgb(62, 142, 247);\n"
"color: white;\n"
"border-radius: 6px;\n"
"background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(91, 161, 248, 255), stop:1 rgba(14, 99, 254, 255))"));
        statusLabel = new QLabel(centralwidget);
        statusLabel->setObjectName(QStringLiteral("statusLabel"));
        statusLabel->setGeometry(QRect(20, 310, 561, 31));
        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(90, 40, 391, 51));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        sortLabel = new QLabel(layoutWidget1);
        sortLabel->setObjectName(QStringLiteral("sortLabel"));

        horizontalLayout_3->addWidget(sortLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        typeBox = new QComboBox(layoutWidget1);
        typeBox->setObjectName(QStringLiteral("typeBox"));

        horizontalLayout->addWidget(typeBox);

        orderBox = new QComboBox(layoutWidget1);
        orderBox->setObjectName(QStringLiteral("orderBox"));

        horizontalLayout->addWidget(orderBox);


        horizontalLayout_3->addLayout(horizontalLayout);

        sortButton = new QPushButton(layoutWidget1);
        sortButton->setObjectName(QStringLiteral("sortButton"));

        horizontalLayout_3->addWidget(sortButton);

        FilesWindow->setCentralWidget(centralwidget);
        layoutWidget->raise();
        layoutWidget->raise();
        filesTable->raise();
        statusLabel->raise();
        backButton->raise();

        retranslateUi(FilesWindow);

        QMetaObject::connectSlotsByName(FilesWindow);
    } // setupUi

    void retranslateUi(QMainWindow *FilesWindow)
    {
        FilesWindow->setWindowTitle(QApplication::translate("FilesWindow", "MainWindow", 0));
        keywordLabel->setText(QApplication::translate("FilesWindow", "Keyword: ", 0));
        searchButton->setText(QApplication::translate("FilesWindow", "Search", 0));
        QTableWidgetItem *___qtablewidgetitem = filesTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("FilesWindow", "File Name", 0));
        QTableWidgetItem *___qtablewidgetitem1 = filesTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("FilesWindow", "Size", 0));
        QTableWidgetItem *___qtablewidgetitem2 = filesTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("FilesWindow", "Created Date", 0));
        QTableWidgetItem *___qtablewidgetitem3 = filesTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("FilesWindow", "Path", 0));
        backButton->setText(QApplication::translate("FilesWindow", "Back", 0));
        statusLabel->setText(QApplication::translate("FilesWindow", "<html><head/><body><p align=\"center\"/></body></html>", 0));
        sortLabel->setText(QApplication::translate("FilesWindow", "Sort by:", 0));
        sortButton->setText(QApplication::translate("FilesWindow", "Sort", 0));
    } // retranslateUi

};

namespace Ui {
    class FilesWindow: public Ui_FilesWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILESWINDOW_H
