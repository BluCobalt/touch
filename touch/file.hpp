#pragma once
#include <iostream>
#include <fstream>

//check if file exists

bool fileExists(char* file) {
	std::ifstream ifile(file);
	if (ifile) {
		return true;
	}
	else {
		return false;
	}
}