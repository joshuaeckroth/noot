#include <string>
#include <unistd.h>
#include <fstream>
#include "notefile.h"

NoteFile::NoteFile() {
	// filename will be determined by
	// finding a ".notes.txt" file in
	// the current directory, and if
	// not there, in the parent directory,
	// recursively, until it is found;
	// it stops searching at the user's
	// home directory. If the user is
	// not in their home directory or
	// any subdirectory, it will use
	// the notes file in the user's
	// home directory.
	
	// Get current directory
	char cwd[1024];
	getcwd(cwd, sizeof(cwd));
	std::string currentdir = cwd;
	// get user name
	std::string username = getenv("USER");
	std::string homedir = getenv("HOME");
	if (currentdir.find(homedir) == 0) {
		// user is in their home directory or a subdirectory
		// search for the notes file
		while (currentdir != homedir) {
			// check if the file exists
			std::ifstream file(currentdir + "/.notes.txt");
			if (!file.fail()) {
				filename = currentdir + "/.notes.txt";
				break;
			}
			// go up a directory
			currentdir = currentdir.substr(0, currentdir.find_last_of("/"));
		}
		if (currentdir == homedir) {
			// file not found in any subdirectory
			filename = homedir + "/.notes.txt";
		}
	} else {
		filename = homedir + "/.notes.txt";
	}
}

std::string NoteFile::getFilename() const {
	return filename;
}

