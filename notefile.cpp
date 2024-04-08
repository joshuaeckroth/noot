#include <string>
#include <unistd.h>
#include <fstream>
#include "notefile.h"

NoteFile::NoteFile() {
	lastid = 0;
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
	std::ifstream file(filename, std::ios::in | std::ios::binary);
	if(file.is_open()) {
		std::string line;
		std::string body;
		int id;
		while (getline(file, line, '\3')) {
			if(line.empty() || line[0] != '\1') {
				continue;
			}
			// find \2
			size_t pos = line.find('\2');
			id = std::stoi(line.substr(1, pos - 1));
			body = line.substr(pos + 1);
			Note note;
			note.setId(id);
			note.setBody(body);
			notes.insert(std::pair<int, const Note&>(id, note));
		}
		file.close();
	}
}

std::string NoteFile::getFilename() const {
	return filename;
}

int NoteFile::add(Note& note) {
	lastid++;
	note.setId(lastid);
	notes.insert(std::pair<int, const Note&>(lastid, note));
	return lastid;
}

void NoteFile::save() const {
	std::ofstream file(filename, std::ios::out | std::ios::binary);
	for (auto it = notes.begin(); it != notes.end(); it++) {
		file << "\1" << (it->first) << "\2" << (it->second).getBody() << "\3";
	}
	file.close();
}
