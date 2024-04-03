#include <string>
#include <fstream>
#include <iostream>
#include "notefile.h"

int main(int argc, char *argv[])
{
	std::string progname = argv[0];
	progname = progname.substr(progname.find_last_of("/\\") + 1);
	std::cout << "progname: " << progname << std::endl;
	if(progname == "nn")
	{
		// create new .notes.txt file here
		std::ofstream file(".notes.txt");
		file.close();
	} else {
		NoteFile notefile;
		std::cout << "Loaded notes file: " << notefile.getFilename() << std::endl;
	}

	return 0;
}

