#ifndef FILELIST_H
#define FILELIST_H
#include "audiofile.h"
class FileList{
  public:
    AudioFile *head;
    AudioFile *tail;
    int size;
    FileList();
    void addFile(AudioFile *file);
    void addFile(std::string inputString);
    void show();
    int getSize();
    void reset();
};

#endif // FILELIST_H
