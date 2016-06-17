#ifndef FILESWINDOW_H
#define FILESWINDOW_H

#include <QMainWindow>
#include "filelist.h"
namespace Ui {
class FilesWindow;
}

class FilesWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit FilesWindow(QWidget *parent = 0);
    ~FilesWindow();

private:
    Ui::FilesWindow *ui;
    FileList list;
};

#endif // FILESWINDOW_H
