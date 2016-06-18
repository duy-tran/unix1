#ifndef FILESWINDOW_H
#define FILESWINDOW_H

#include <QMainWindow>
#include "filelist.h"
#include "mainwindow.h"

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

private slots:
    void on_backButton_clicked();

private:
    void createFilesTable();

    Ui::FilesWindow *ui;
};

#endif // FILESWINDOW_H
