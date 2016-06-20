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
#include <iostream>
FilesWindow *filesWindow;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    filesWindow = new FilesWindow();
    filesWindow->mainWindow = this;
    filesWindow->hide();
    ui->setupUi(this);
    setUpUI();
    ui->dirPath->setEditable(true);
    ui->dirPath->addItem("/Users/duy/Desktop");
    ui->dirPath->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    setWindowTitle(tr("Audio Finder"));
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
    filesWindow->resetTable();
    filesWindow->updateList(inputList);
    filesWindow->updateTable();
    filesWindow->show();
    this->hide();
}

void MainWindow::on_findButton_clicked()
{
    QString path = ui->dirPath->currentText();
    if (!checkDir(path.toStdString())){
        ui->warningLabel->setText("Invalid folder name");
        return;
    }
    filesWindow->path=path.toStdString();
    ui->warningLabel->setText(" ");
    std::string cmd = "/Users/duy/unix/project1/AudioFinder/findFile.sh \""+ path.toStdString()+
            "\"";
    char buffer[512];
    FileList *audio = new FileList();
    std::shared_ptr<FILE> pipe(popen(cmd.c_str(), "r"), pclose);
    if (!pipe)
        throw std::runtime_error("popen() failed!");
    while (!feof(pipe.get())) {
      if (fgets(buffer, 512, pipe.get()) != NULL){
        std::string temp(buffer);
        audio->addFile(temp);
      }
     }
    openFilesWindow(audio);
}
bool checkDir(std::string dirPath){
    int found;
    std::string bashCmd = "/Users/duy/unix/project1/AudioFinder/checkDir.sh \""+dirPath+"\"";
    found = system(bashCmd.c_str());
    return found == 0 ? true: false;
}
void MainWindow::setUpUI(){
    ui->findButton->setStyleSheet("QPushButton{background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(91, 161, 248, 255), stop:1 rgba(14, 99, 254, 255));color: white;border-radius: 5px;}"
"QPushButton:pressed{background-color: white;color:black;border:1px solid #BBB;border-radius: 5px;}");
}
