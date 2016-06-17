#include "filelist.h"
FileList::FileList(){
    tail = head = NULL;
    size = 0;
}
void FileList::addFile(ImageFile *file){
    if (tail!=NULL){
        tail->next = file;
    } else {
        head = tail = file;
    }
    tail = file;
    file->next = NULL;
    size++;
}

void FileList::addFile(std::string inputString){
    ImageFile *temp = new ImageFile(inputString);
    addFile(temp);
}

void FileList::show(){
    ImageFile *ptr = head;
    while (ptr != NULL){
        ptr->show();
        ptr=ptr->next;
    }
}

int FileList::getSize(){
    return size;
}

