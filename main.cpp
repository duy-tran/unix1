#include <cstdlib>
#include <string>
#include <iostream>
#include "functions.h"

using namespace std;

int main() {
	while (true) {
		system("clear");
		system("echo \"\e[7;96mIMAGES MANAGER\e[0m\"");
		string dirName;
		int folderExists;
		string bashCmd;
		while (true) {
			cout << "Enter directory name (type -q to exit): ";		
			cin >> dirName;
			if (dirName == "-q")
				return 0;
			bashCmd = "./checkDir.sh "+dirName;
			folderExists = system(bashCmd.c_str());
			if (dirName == "" || folderExists != 0 ) {
				cout << "Please enter a valid folder.\n";
			} 
			else {
				findImageIn(dirName);
				cout << "Press any key to continue ";
				int dummy = cin.get();
				dummy = cin.get();
				break;
			}
		}
	}
	return 0;
}