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
    } else if(progname == "ns") {
        NoteFile notefile;
        std::vector<int> matching_note_ids;
        if(argc == 1) {
            matching_note_ids = notefile.search("");
        } else {
            matching_note_ids = notefile.search(argv[1]);
        }
        std::vector<int>::const_iterator it;
        for(it = matching_note_ids.begin(); it != matching_note_ids.end(); it++) {
            int note_id = *it;
            Note note;
            if(notefile.tryFetch(note_id, note)) {
                std::cout << note_id << ". " << note.getPreview() << std::endl;
            } else {
                std::cout << "Error: could not fetch note with id " << note_id << std::endl;
            }
        }
	} else {
		NoteFile notefile;
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

