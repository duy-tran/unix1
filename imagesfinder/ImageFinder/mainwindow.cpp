#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include "filelist.h"
#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include "fileswindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->dirPath->setEditable(true);
    ui->dirPath->addItem("/Users/duy/Desktop");
    ui->dirPath->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_browseButton_clicked()
{
    QString directory = QFileDialog::getExistingDirectory(this,
                               tr("Find Files"), QDir::currentPath());
    if (!directory.isEmpty()) {
        if (ui->dirPath->findText(directory) == -1)
            ui->dirPath->addItem(directory);
        ui->dirPath->setCurrentIndex(ui->dirPath->findText(directory));
    }
}
void MainWindow::openFilesWindow(FileList *inputList){
    newFilesWindow = new FilesWindow();
    newFilesWindow->show();
}

void MainWindow::on_findButton_clicked()
{
    QString path = ui->dirPath->currentText();
    std::string cmd = "/Users/duy/unix/project1/imagesfinder/ImageFinder/findImage.sh \""+ path.toStdString()+
            "\" \\*";
    char buffer[128];
    FileList *images = new FileList();
    std::shared_ptr<FILE> pipe(popen(cmd.c_str(), "r"), pclose);
    if (!pipe)
        throw std::runtime_error("popen() failed!");
    while (!feof(pipe.get())) {
      if (fgets(buffer, 128, pipe.get()) != NULL){
        std::string temp(buffer);
        images->addFile(temp);
      }
     }
    openFilesWindow(images);
}
