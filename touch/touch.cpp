#include <iostream>
#include <string>
#include <fstream>
#include "filehandler.hpp"


int main(int argc, char* argv[]) {
	// Print usage into stderr if somehow no arguments are given or just the executable is called
	// eg. .\touch.exe
	if (argc < 2) {

		std::cout << "Create empty files, loosely based unix command, touch.\n";
		std::cout << "Usage: \n";
		std::cout << "\t" << argv[0] << " [file(s) to create] \n";
		std::cout << "\n";
		std::cout << "Example usages:\n";
		std::cout << "\t" << argv[0] << " __init__.py __main__.py\n";
		std::cout << "\t\tcreate 2 empty files, __init__.py and __main__.py respectively.";
		std::cout << "\n";
		std::cout << "\t" << argv[0] << " config.json\n";
		std::cout << "\t\tcreates 1 empty file, config.json\n";
		return 0;
	}
	// Checks for the file's existance, and if it doesnt already exist, creates it.
	// If the file doesnt exist after trying to create it, the user is warned
	for(int i=1; i<argc; i++)  {
		if (filehandler::fileExists(argv[i])) {
			// Tell user if the file exists and skips trying to create it
			std::cout << "File \"" << argv[i] << "\" already exists, skipping...\n";
		}
		else {
			filehandler::createFile(argv[i]);
			if (!filehandler::fileExists(argv[i])) {
			std::cerr << "The file's existance could not be checked for after trying to make it.";
			}
		}
	}

	return 0;
}
