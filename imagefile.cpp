#include "imagefile.h"
#include <iostream>
#include <stdlib.h>
#include <cstddef>
ImageFile::ImageFile(){
}
ImageFile::ImageFile(std::string inputPathFile, int inputSizeKB, std::string inputDate){
    pathFile = inputPathFile;
    nameFile = getNameFromPath(inputPathFile);
    sizeKB = inputSizeKB;
    createdDate = inputDate;
}
ImageFile::ImageFile(std::string inputString){
    // Format is 209;May 27 21:13:19 2016;./jc.png;
    std::string temp;
    // Get size
    int mark = inputString.find(";");
    sizeKB = atoi(inputString.substr(0,mark).c_str());
    temp = inputString.substr(mark+1);
    mark = temp.find(";");
    // Get date and path
    createdDate = temp.substr(0,mark);
    temp = temp.substr(mark+1);
    mark = temp.find(";");
    pathFile = temp.substr(0,mark);
    nameFile = getNameFromPath(pathFile);
    temp = temp.substr(mark+1);
    mark = temp.find(";");
    conflict = atoi(temp.substr(0,mark).c_str());
}
void ImageFile::show(){
    std::cout << "Path: "<<pathFile<<", name: "<<nameFile<<", size: "<<sizeKB<<" KB, createdDate: "<<createdDate<<" , conflict: "<<conflict<<std::endl;
}
std::string getNameFromPath(std::string path){
    std::size_t mark = path.find_last_of("/");
    return path.substr(mark+1);
}
std::string ImageFile::getPath(){
    return pathFile;
}

std::string ImageFile::getName(){
    return nameFile;
}

std::string ImageFile::getCreatedDate(){
    return createdDate;
}

int ImageFile::getSize(){
    return sizeKB;
}

int ImageFile::getConflict(){
    return conflict;
}
