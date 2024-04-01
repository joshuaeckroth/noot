
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
	// if we are in /home/{user} then find the notes file
	if (currentdir.find("/home/" + username) == 0) {
		// search for the notes file
		while (currentdir != "/home") {
			// check if the file exists
			std::ifstream file(currentdir + "/.notes.txt");
			if (file.good()) {
				filename = currentdir + "/.notes.txt";
				break;
			}
			// go up a directory
			currentdir = currentdir.substr(0, currentdir.find_last_of("/"));
		}
	} else {
		filename = "/home/" + username + "/.notes.txt";
	}
}

