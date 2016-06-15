#ifndef FILELIST_H
#define FILELIST_H
#include "imagefile.h"
class FileList{
public:
    ImageFile *head;
    ImageFile *tail;
    FileList();
    void addFile(ImageFile *file);
    void addFile(std::string inputString);
    void show();
};

#endif // FILELIST_H
