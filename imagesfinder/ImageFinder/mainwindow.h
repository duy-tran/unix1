#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QDir>
#include "filelist.h"
#include "fileswindow.h"

class QComboBox;
class QLabel;
class QPushButton;
class QTableWidget;
class QTableWidgetItem;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_browseButton_clicked();

    void on_findButton_clicked();

    void openFilesWindow(FileList *inputList);
private:
    Ui::MainWindow *ui;
    QComboBox *dirPath;
    FilesWindow *newFilesWindow;
};

#endif // MAINWINDOW_H
