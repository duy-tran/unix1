#include "functions.h"
#include <iostream>

bool showImage(string dirName) {
	int found;
	string bashCmd = "./showImages.sh "+dirName+" \\*";
	found = system(bashCmd.c_str());
	return found == 0 ? true: false;
}

void imageMenu(string dirName) {
	char selection;
	bool checkExit = false, caseLoop = true;
	while (!checkExit) {
		system("echo \"\e[96m1. Sort\n2. Open image\n3. Find an image\n0. Quit\e[0m\"");
		do {
			cout << "Enter your choice: ";
			cin >> selection;
			switch (selection) {
				case '1': {
					cout << "Sort function here\n";
					caseLoop = false;
					break;			
				}
				case '2': {
					cout << "Open function here\n";
					caseLoop = false;
					break;			
				}
				case '3': {
					cout << "Find function here\n";
					caseLoop = false;
					break;			
				}
				case '0': {
					cout << "Quit\n";
					caseLoop = false;
					checkExit = true;
					break;			
				}
				default: {
					system("echo \"\e[91mPlease enter a valid choice\e[0m\"");
					break;			
				}
			}
		} while (caseLoop);
	}
}

void findImageIn(string dirName) {
	system("clear");
	if (!showImage(dirName)) {
		cout << "No image found!\n";
	}
	else {
		imageMenu(dirName);
	}
}