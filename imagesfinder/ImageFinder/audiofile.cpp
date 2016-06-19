#include "AudioFile.h"
#include <iostream>
#include <stdlib.h>
#include <cstddef>
#include <sstream>
AudioFile::AudioFile(){
}
AudioFile::AudioFile(std::string inputPathFile, int inputSizeKB, std::string inputDate){
    pathFile = inputPathFile;
    nameFile = getNameFromPath(inputPathFile);
    sizeKB = inputSizeKB;
    createdDate = inputDate;
}
AudioFile::AudioFile(std::string inputString, int formated){
    // Format is 209;May 27 21:13:19 2016;./jc.png;1; => Unformated (formated = 0 )
    // Format is 209;2016/05/27 21:13;./jc.png;1;     => Formated   (formated = 1 )
    std::string temp;
    // Get size
    int mark = inputString.find(";");
    sizeKB = atoi(inputString.substr(0,mark).c_str());
    temp = inputString.substr(mark+1);
    mark = temp.find(";");
    // Get date and path
    createdDate = temp.substr(0,mark);
    if (formated == 0)
        createdDate = formatDate(createdDate);
    temp = temp.substr(mark+1);
    mark = temp.find(";");
    pathFile = temp.substr(0,mark);
    nameFile = getNameFromPath(pathFile);
    // Get conflict status
    temp = temp.substr(mark+1);
    mark = temp.find(";");
    conflict = atoi(temp.substr(0,mark).c_str());
}
std::string formatDate(std::string date){
    // Format is "May 27 21:13:19 2016"
    std::string month = date.substr(0,3);
    month = numberMonth(month);
    std::string day = date.substr(4,2);
    if (day.substr(0,1)==" ")
            day = "0"+day.substr(1,1);
    std::string hm = date.substr(7,5);
    std::string year = date.substr(16);
    return year+"/"+month+"/"+day+" "+hm;
}
std::string numberMonth(std::string month){
    if (month=="Jan")
        return "01";
    if (month=="Feb")
        return "02";
    if (month=="Mar")
        return "03";
    if (month=="Apr")
        return "04";
    if (month=="May")
        return "05";
    if (month=="Jun")
        return "06";
    if (month=="Jul")
        return "07";
    if (month=="Aug")
        return "08";
    if (month=="Sep")
        return "09";
    if (month=="Oct")
        return "10";
    if (month=="Nov")
        return "11";
    if (month=="Dec")
        return "12";
    else
        return "error";
}

void AudioFile::show(){
    std::cout << "Path: "<<pathFile<<", name: "<<nameFile<<", size: "<<sizeKB<<" KB, createdDate: "<<createdDate<<" , conflict: "<<conflict<<std::endl;
}
std::string getNameFromPath(std::string path){
    std::size_t mark = path.find_last_of("/");
    return path.substr(mark+1);
}
std::string AudioFile::getPath(){
    return pathFile;
}

std::string AudioFile::getName(){
    return nameFile;
}

std::string AudioFile::getCreatedDate(){
    return createdDate;
}

int AudioFile::getSize(){
    return sizeKB;
}

int AudioFile::getConflict(){
    return conflict;
}
std::string AudioFile::toString(){
    return intToString(sizeKB)+";"+createdDate+";"+pathFile+";"+intToString(conflict)+";\n";
}
std::string intToString(int input){
    std::stringstream convert;
    convert << input;
    return convert.str();
}
