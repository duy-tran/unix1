#ifndef FILELIST_H
#define FILELIST_H
#include "imagefile.h"
class FileList{
  public:
    ImageFile *head;
    ImageFile *tail;
    int size;
    FileList();
    void addFile(ImageFile *file);
    void addFile(std::string inputString);
    void show();
    int getSize();
    ImageFile getHead();
};

#endif // FILELIST_H
