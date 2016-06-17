#include "fileswindow.h"
#include "ui_fileswindow.h"

FilesWindow::FilesWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FilesWindow)
{
    ui->setupUi(this);
}

FilesWindow::~FilesWindow()
{
    delete ui;
}
