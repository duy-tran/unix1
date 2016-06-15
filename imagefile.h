#ifndef IMAGEFILE_H
#define IMAGEFILE_H
#include <string>
class ImageFile {
    public:
    std::string pathFile;
    std::string nameFile;
    int sizeKB;
    std::string createdDate;
    ImageFile *next;
    ImageFile();
    ImageFile(std::string inputPathFile, int inputSizeKB, std::string inputDate);
    ImageFile(std::string inputString);
    void show();
};
std::string getNameFromPath(std::string path);
#endif // IMAGEFILE_H
