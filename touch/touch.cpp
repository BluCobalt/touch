#include <iostream>
#include <string>
#include <fstream>
#include "filehandler.hpp"


int main(int argc, char* argv[]) {
	// Print usage into stderr if somehow no arguments are given or just the executable is called
	// eg. .\touch.exe
	// note to self: probably going to change the usage to stdout one day
	if (argc == 0 || argc == 1) {
		std::cerr << "Create empty files, loosely based on the touch *nix command.\n";
		std::cerr << "Usage: \n";
		std::cerr << "\t" << argv[0] << " [file(s) to create] \n";
		std::cerr << "\n";
		std::cerr << "Example usages:\n";
		std::cerr << "\t" << argv[0] << " __init__.py __main__.py\n";
		std::cerr << "\t\tcreate 2 empty files, __init__.py and __main__.py respectively.";
		std::cerr << "\n";
		std::cerr << "\t" << argv[0] << " config.json\n";
		std::cerr << "\t\tcreates 1 empty file, config.json\n";
		return 0;
	}
	// Super simple if just one argument is given
	// Checks for the file's existance, and if it doesnt already exist, creates it.
	// If the file doesnt exist after trying to create it, the user is warned
	if (argc == 2) {
		if (filehandler::fileExists(argv[1])) {
			// Tell user if the file exists and skips trying to create it
			std::cout << "File \"" << argv[1] << "\" already exists, skipping...\n";
			return 0;
		}
		else {
			filehandler::createFile(argv[1]);
			if (filehandler::fileExists(argv[1])) {
				return 0;
			}
			else {
				std::cerr << "The file's existance could not be checked for after trying to make it.";
				return 1;
			}
		}
	}
	// not so super simple if more then one argument is given
	// once again, it checks for the file's existance and if it doesnt exist creates it
	// and, like before, alerts the user if the file can not be found after trying to make it
	// however, i have to do some weird voodoo variable shiz to make it work with multiple inputs
	if (argc >> 2) {
		// Create the variables
		int targ;
		int cargn;
		targ = argc;
	    cargn = 1;
		
		while (targ != cargn) {
			if (filehandler::fileExists(argv[cargn])) {
				std::cout << "File \"" << argv[cargn] << "\" already exists, skipping...\n";
				cargn += 1;
			}
			
			else {
				filehandler::createFile(argv[cargn]);
				if (filehandler::fileExists(argv[cargn])) {
				// i dont really know what to put here so um
				// 🐕
				// if some weird unicode shiz breaks its a dog emoji
				// enjoy
				}
				else {
					std::cerr << "The file's existance could not be checked for after trying to make it.\n";
				}
				cargn += 1;
			}
		}
		return 0;
	}
}