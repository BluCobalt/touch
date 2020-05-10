#ifndef filehandler
#define filehandler
#include <iostream>
#include <fstream>
bool fileExists(char* file) {
	std::ifstream ifile(file);
	if (ifile) {
		return true;
	}
	else {
		return false;
	}

}

void createFile(char* file) {
	std::ofstream fileMade(file);
	fileMade.close();
}
#endif
