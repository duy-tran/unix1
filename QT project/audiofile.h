#ifndef AUDIOFILE_H
#define AUDIOFILE_H
#include <string>
class AudioFile {
  private:
    std::string pathFile;
    std::string nameFile;
    int sizeKB;
    std::string createdDate;
    int conflict;
  public:
    AudioFile *next;
    AudioFile();
    AudioFile(std::string inputPathFile, int inputSizeKB, std::string inputDate);
    AudioFile(std::string inputString);
    std::string getPath();
    std::string getName();
    std::string getCreatedDate();
    int getSize();
    int getConflict();
    void show();
    std::string toString();
};
std::string getNameFromPath(std::string path);
std::string formatDate(std::string date);
std::string numberMonth(std::string month);
std::string intToString(int input);
#endif // AudioFile_H
