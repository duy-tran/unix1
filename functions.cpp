#include "functions.h"
#include <iostream>

bool showImage(string dirName) {
	int found;
	string bashCmd = "./showImages.sh "+dirName;
	found = system(bashCmd.c_str());
	return found == 0 ? true: false;
}

void imageMenu(string dirName) {
	cout << endl;
}

void findImageIn(string dirName) {
	system("clear");
	cout << "Images in directory "<<dirName<<endl;
	if (!showImage(dirName)) {
		cout << "No image found!\n";
	}
	else {
		imageMenu(dirName);
	}
}