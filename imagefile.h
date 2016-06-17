#ifndef IMAGEFILE_H
#define IMAGEFILE_H
#include <string>
class ImageFile {
  private:
    std::string pathFile;
    std::string nameFile;
    int sizeKB;
    std::string createdDate;
  public:
    ImageFile *next;
    ImageFile();
    ImageFile(std::string inputPathFile, int inputSizeKB, std::string inputDate);
    ImageFile(std::string inputString);
    std::string getPath();
    std::string getName();
    std::string getCreatedDate();
    int getSize();
    void show();
};
std::string getNameFromPath(std::string path);
#endif // IMAGEFILE_H
