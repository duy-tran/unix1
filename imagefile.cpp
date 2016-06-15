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
    // Format is 209;May 27 21:13:19 2016;./jc.png
    std::string temp;
    // Get size
    int mark = inputString.find(";");
    sizeKB = atoi(inputString.substr(0,mark).c_str());
    temp = inputString.substr(mark+1);
    mark = temp.find(";");
    // Get date and path
    createdDate = temp.substr(0,mark);
    pathFile = temp.substr(mark+1);
    nameFile = getNameFromPath(pathFile);
}
void ImageFile::show(){
    std::cout << "Path: "<<pathFile<<", name: "<<nameFile<<", size: "<<sizeKB<<" KB, createdDate: "<<createdDate<<std::endl;
}
std::string getNameFromPath(std::string path){
    std::size_t mark = path.find_last_of("/");
    return path.substr(mark+1);
}
