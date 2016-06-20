#include "fileswindow.h"
#include "ui_fileswindow.h"
#include <QtWidgets>
#include <cstdlib>
#include <iostream>
FilesWindow::FilesWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FilesWindow)
{
    ui->setupUi(this);
    setUpUI();
    createFilesTable();
    setWindowTitle(tr("Audio Finder"));
    ui->typeBox->addItem("File name");
    ui->typeBox->addItem("Size");
    ui->typeBox->addItem("Created Date");
    ui->orderBox->addItem("Ascending");
    ui->orderBox->addItem("Descending");
}


FilesWindow::~FilesWindow()
{
    delete ui;
}
void FilesWindow::createFilesTable(){
    //ui->filesTable->setSortingEnabled(true);
    ui->filesTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->filesTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->filesTable->verticalHeader()->hide();
    ui->filesTable->setShowGrid(false);
    ui->filesTable->setColumnHidden(3, true);
    connect(ui->filesTable, &QTableWidget::cellActivated,this, &FilesWindow::openFile);
}

void FilesWindow::on_backButton_clicked()
{
    this->mainWindow->show();
    this->hide();
}

void FilesWindow::updateTable()
{
    AudioFile *ptr = list->head;
    while (ptr != NULL){
        QTableWidgetItem *fileNameItem = new QTableWidgetItem();
        fileNameItem->setText(QString::fromStdString(ptr->getName()));
        fileNameItem->setFlags(fileNameItem->flags() ^ Qt::ItemIsEditable);
        QTableWidgetItem *sizeItem = new QTableWidgetItem();
        sizeItem->setText(QString::number(ptr->getSize())+" KB");
        sizeItem->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
        sizeItem->setFlags(sizeItem->flags() ^ Qt::ItemIsEditable);
        QTableWidgetItem *createdDateItem = new QTableWidgetItem();
        createdDateItem->setText(QString::fromStdString(ptr->getCreatedDate()));
        createdDateItem->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
        createdDateItem->setFlags(createdDateItem->flags() ^ Qt::ItemIsEditable);
        QTableWidgetItem *filePathItem = new QTableWidgetItem();
        filePathItem->setText(QString::fromStdString(ptr->getPath()));
        filePathItem->setFlags(filePathItem->flags() ^ Qt::ItemIsEditable);
        int row = ui->filesTable->rowCount();
        if (ptr->getConflict() == 1){
            fileNameItem->setForeground(Qt::red);
            sizeItem->setForeground(Qt::red);
            createdDateItem->setForeground(Qt::red);
            filePathItem->setForeground(Qt::red);
        }
        ui->filesTable->insertRow(row);
        ui->filesTable->setItem(row, 0, fileNameItem);
        ui->filesTable->setItem(row, 1, sizeItem);
        ui->filesTable->setItem(row, 2, createdDateItem);
        ui->filesTable->setItem(row, 3, filePathItem);
        ptr = ptr->next;
    }
    ui->statusLabel->setText(QString::number(list->getSize())+" file(s) found. Double click to open the file.");
}

void FilesWindow::resetTable(){
    ui->filesTable->setRowCount(0);
}

void FilesWindow::updateList(FileList *inputList){
    list = inputList;
}
void FilesWindow::setUpUI(){
    ui->backButton->setStyleSheet("QPushButton{background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(91, 161, 248, 255), stop:1 rgba(14, 99, 254, 255));color: white;border-radius: 5px;}"
                                  "QPushButton:pressed{background-color: white;color:black;border:1px solid #BBB;border-radius: 5px;}");
}

void FilesWindow::openFile(int row)
{
    QTableWidgetItem *item = ui->filesTable->item(row, 3);
    QDesktopServices::openUrl(QUrl::fromLocalFile((item->text())));
}

void FilesWindow::on_sortButton_clicked()
{
    std::string typeCmd, orderCmd;
    QString type = ui->typeBox->currentText();
    if (type=="File name")
        typeCmd = "-k5 --ignore-case";
    else {
        if (type=="Size")
            typeCmd = "-n";
        else {
            typeCmd = "-k6n";
        }
    }
    QString order = ui->orderBox->currentText();
    if (order=="Descending")
        orderCmd=" -r";
    else
        orderCmd="";
    std::string cmd = "/Users/duy/unix/project1/AudioFinder/findFile.sh \""+path+
            "\" | sort -t ';' "+typeCmd+orderCmd;
    updateListByRunningCmd(cmd);
}

void FilesWindow::on_searchButton_clicked()
{
    std::string keyword = ui->keywordText->text().toStdString();
    std::string cmd = "/Users/duy/unix/project1/AudioFinder/findFile.sh \""+path+
            "\" \""+keyword+"\"";
    updateListByRunningCmd(cmd);
}
void FilesWindow::updateListByRunningCmd(std::__1::string cmd){
    char buffer[512];
    FileList *audio = new FileList();
    resetTable();
    std::shared_ptr<FILE> pipe(popen(cmd.c_str(), "r"), pclose);
    if (!pipe)
        throw std::runtime_error("popen() failed!");
    while (!feof(pipe.get())) {
        if (fgets(buffer, 512, pipe.get()) != NULL){
            std::string temp(buffer);
            audio->addFile(temp);
        }
     }
    list->reset();
    list = audio;
    updateTable();
}
