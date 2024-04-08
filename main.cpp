#include <string>
#include <fstream>
#include <iostream>
#include "notefile.h"

int main(int argc, char *argv[])
{
	std::string progname = argv[0];
	progname = progname.substr(progname.find_last_of("/\\") + 1);
	if(progname == "nn")
	{
		// create new .notes.txt file here
		std::ofstream file(".notes.txt");
		file.close();
	} else {
		NoteFile notefile;
		std::cout << "Loaded notes file: " << notefile.getFilename() << std::endl;
		if(progname == "n") {
			std::string notetxt = "";
			for(int i = 1; i < argc; i++)
			{
				notetxt += argv[i];
				if(i < argc - 1)
					notetxt += " ";
			}
			if(notetxt == "")
			{
				std::cout << "Usage: n <note>" << std::endl;
				return 1;
			}
			Note note(notetxt);
			notefile.add(note);
		}
		notefile.save();
	}

	return 0;
}

