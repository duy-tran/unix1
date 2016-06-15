#include "filelist.h"
FileList::FileList(){
    tail = head = NULL;
}
void FileList::addFile(ImageFile *file){
    if (tail!=NULL){
        tail->next = file;
    } else {
        head = tail = file;
    }
    tail = file;
    file->next = NULL;
}

void FileList::show(){
    ImageFile *ptr = head;
    while (ptr != NULL){
        ptr->show();
        ptr=ptr->next;
    }
}