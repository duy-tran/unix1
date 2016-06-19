#ifndef FILESWINDOW_H
#define FILESWINDOW_H

#include <QMainWindow>
#include "filelist.h"
#include "mainwindow.h"
#include <string>

namespace Ui {
class FilesWindow;
}

class FilesWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit FilesWindow(QWidget *parent = 0);
    //FilesWindow(FileList *inputList);
    ~FilesWindow();
    MainWindow *mainWindow;
    FileList *list;
    void resetTable();
    void updateTable();
    void updateList(FileList *inputList);
    std::string path;
private slots:
    void on_backButton_clicked();

    void on_sortButton_clicked();

    void on_searchButton_clicked();

private:
    void createFilesTable();
    void setUpUI();
    Ui::FilesWindow *ui;
    void openFile(int row);
    void updateListByRunningCmd(std::string cmd);
};

#endif // FILESWINDOW_H
