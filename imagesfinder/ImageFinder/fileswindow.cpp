#include "fileswindow.h"
#include "ui_fileswindow.h"

FilesWindow::FilesWindow(FileList *inputList, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FilesWindow)
{
    ui->setupUi(this);
    createFilesTable();
}

//FilesWindow::FilesWindow(FileList *inputList){
//    list = inputList;
//    list->show();
//    ui->setupUi(new Ui::FilesWindow);
//}

FilesWindow::~FilesWindow()
{
    delete ui;
}
void FilesWindow::createFilesTable(){
    //ui->filesTable = new QTableWidget(0, 3);
    ui->filesTable->setSortingEnabled(true);
    ui->filesTable->sortByColumn(0, Qt::AscendingOrder);
    ui->filesTable->sortByColumn(1, Qt::AscendingOrder);
    ui->filesTable->sortByColumn(2, Qt::AscendingOrder);
    ui->filesTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    QStringList labels;
    labels << tr("File path") << tr("Size") << tr("Created Date");
    ui->filesTable->setHorizontalHeaderLabels(labels);
    ui->filesTable->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->filesTable->verticalHeader()->hide();
    ui->filesTable->setShowGrid(false);
    //connect(ui->filesTable, &QTableWidget::cellActivated,this, &Window::openFileOfItem);
}

void FilesWindow::on_backButton_clicked()
{
    this->mainWindow->show();
    this->hide();
}
