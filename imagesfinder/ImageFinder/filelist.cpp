#include "filelist.h"
FileList::FileList(){
    tail = head = NULL;
    size = 0;
}
void FileList::addFile(AudioFile *file){
    if (tail!=NULL){
        tail->next = file;
    } else {
        head = tail = file;
    }
    tail = file;
    file->next = NULL;
    size++;
}

void FileList::addFile(std::string inputString, int formated){
    AudioFile *temp = new AudioFile(inputString,formated);
    addFile(temp);
}

void FileList::show(){
    AudioFile *ptr = head;
    while (ptr != NULL){
        ptr->show();
        ptr=ptr->next;
    }
}

int FileList::getSize(){
    return size;
}
void FileList::reset(){
    tail=head=NULL;
    size=0;
}
