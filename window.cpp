/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtWidgets>

#include "window.h"
#include "filelist.h"
#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>

Window::Window(QWidget *parent)
    : QWidget(parent)
{
    browseButton = new QPushButton(tr("&Browse..."), this);
    connect(browseButton, &QAbstractButton::clicked, this, &Window::browse);
    findButton = new QPushButton(tr("&Find"), this);
    connect(findButton, &QAbstractButton::clicked, this, &Window::find);

    fileComboBox = createComboBox();
    textComboBox = createComboBox();
    directoryComboBox = createComboBox("/Users/duy/Desktop");

    fileLabel = new QLabel(tr("Key word:"));
    directoryLabel = new QLabel(tr("Directory:"));
    filesFoundLabel = new QLabel;

    createFilesTable();

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(fileLabel, 0, 0);
    mainLayout->addWidget(fileComboBox, 0, 1, 1, 1);
    mainLayout->addWidget(directoryLabel, 1, 0);
    mainLayout->addWidget(directoryComboBox, 1, 1);
    mainLayout->addWidget(findButton, 2, 1);
    mainLayout->addWidget(browseButton, 1, 2);
    mainLayout->addWidget(filesTable, 3, 0, 1, 3);
    mainLayout->addWidget(filesFoundLabel, 4, 0, 1, 2);
    setLayout(mainLayout);

    setWindowTitle(tr("Images Finder"));
    resize(600, 300);
}

void Window::browse()
{
    QString directory = QFileDialog::getExistingDirectory(this,
                               tr("Find Files"), QDir::currentPath());

    if (!directory.isEmpty()) {
        if (directoryComboBox->findText(directory) == -1)
            directoryComboBox->addItem(directory);
        directoryComboBox->setCurrentIndex(directoryComboBox->findText(directory));
    }
}

static void updateComboBox(QComboBox *comboBox)
{
    if (comboBox->findText(comboBox->currentText()) == -1)
        comboBox->addItem(comboBox->currentText());
}

void Window::find()
{
    filesTable->setRowCount(0);

    QString fileName = fileComboBox->currentText();
    QString path = directoryComboBox->currentText();

    updateComboBox(fileComboBox);
    updateComboBox(directoryComboBox);

    if (fileName.isEmpty())
        fileName = "*";
    std::string cmd = "/Users/duy/unix/project1/findImage.sh \""+ path.toStdString()+
            "\" \"*"+fileName.toStdString()+"*\"";
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
    showFiles(images);
}


void Window::showFiles(FileList *list)
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
        int row = filesTable->rowCount();
        if (ptr->getConflict() == 1){
            fileNameItem->setForeground(Qt::red);
            sizeItem->setForeground(Qt::red);
            createdDateItem->setForeground(Qt::red);
        }
        filesTable->insertRow(row);
        filesTable->setItem(row, 0, fileNameItem);
        filesTable->setItem(row, 1, sizeItem);
        filesTable->setItem(row, 2, createdDateItem);
        ptr = ptr->next;
    }
    filesFoundLabel->setText(QString::number(list->getSize())+" file(s) found");
    filesFoundLabel->setWordWrap(true);
}

QComboBox *Window::createComboBox(const QString &text)
{
    QComboBox *comboBox = new QComboBox;
    comboBox->setEditable(true);
    comboBox->addItem(text);
    comboBox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    return comboBox;
}

void Window::createFilesTable()
{
    filesTable = new QTableWidget(0, 3);
    filesTable->setSortingEnabled(true);
    filesTable->sortByColumn(0, Qt::AscendingOrder);
    filesTable->sortByColumn(1, Qt::AscendingOrder);
    filesTable->sortByColumn(2, Qt::AscendingOrder);
    filesTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    QStringList labels;
    labels << tr("File path") << tr("Size") << tr("Created Date");
    filesTable->setHorizontalHeaderLabels(labels);
    filesTable->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    filesTable->verticalHeader()->hide();
    filesTable->setShowGrid(false);
    connect(filesTable, &QTableWidget::cellActivated,
            this, &Window::openFileOfItem);
}


void Window::openFileOfItem(int row, int /* column */)
{
    QTableWidgetItem *item = filesTable->item(row, 0);
    QDesktopServices::openUrl(QUrl::fromLocalFile(currentDir.absoluteFilePath(item->text())));
}
