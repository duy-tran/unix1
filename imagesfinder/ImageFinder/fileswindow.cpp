#include "fileswindow.h"
#include "ui_fileswindow.h"

FilesWindow::FilesWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FilesWindow)
{
    ui->setupUi(this);
    createFilesTable();
    setWindowTitle(tr("Images Finder"));
}


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

void FilesWindow::updateTable()
{
    ImageFile *ptr = list->head;
    while (ptr != NULL){
        QTableWidgetItem *fileNameItem = new QTableWidgetItem();
        fileNameItem->setText(QString::fromStdString(ptr->getPath()));
        fileNameItem->setFlags(fileNameItem->flags() ^ Qt::ItemIsEditable);
        QTableWidgetItem *sizeItem = new QTableWidgetItem();
        sizeItem->setText(QString::number(ptr->getSize())+" KB");
        sizeItem->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
        sizeItem->setFlags(sizeItem->flags() ^ Qt::ItemIsEditable);
        QTableWidgetItem *createdDateItem = new QTableWidgetItem();
        createdDateItem->setText(QString::fromStdString(ptr->getCreatedDate()));
        createdDateItem->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
        createdDateItem->setFlags(createdDateItem->flags() ^ Qt::ItemIsEditable);
        int row = ui->filesTable->rowCount();
        if (ptr->getConflict() == 1){
            fileNameItem->setForeground(Qt::red);
            sizeItem->setForeground(Qt::red);
            createdDateItem->setForeground(Qt::red);
        }
        ui->filesTable->insertRow(row);
        ui->filesTable->setItem(row, 0, fileNameItem);
        ui->filesTable->setItem(row, 1, sizeItem);
        ui->filesTable->setItem(row, 2, createdDateItem);
        ptr = ptr->next;
    }
//    filesFoundLabel->setText(QString::number(list->getSize())+" file(s) found");
//    filesFoundLabel->setWordWrap(true);
}

void FilesWindow::resetTable(){
    ui->filesTable->setRowCount(0);
}

void FilesWindow::updateList(FileList *inputList){
    list = inputList;
}
