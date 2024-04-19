#ifndef NOTEFILE_H
#define NOTEFILE_H

#include <map>
#include <vector>
#include <string>
#include "note.h"

class NoteFile
{
private:
	std::map<int, Note> notes;
	std::string filename;
	int lastid;

public:
	NoteFile();
	// exists() returns true if the notes file exists;
	// it does not create it.
	bool exists() const;
	std::string getFilename() const;
	// fetch(int) returns the note with the given id,
	// which the user probably supplies on the console.
	// example code:
	// NoteFile nf;
	// Note note;
	// if (nf.tryFetch(5, note))
	// {
	//    cout << "Note 5: " << note << endl;
	// } else {
	//   cout << "Note 5 not found." << endl;
	// }
	bool tryFetch(int id, Note& note) const;
	//void remove(const Note& note);
	//void update(const Note& note);
	int add(Note& note);
	void save() const;
    std::vector<int> search(const std::string& query) const;
};

#endif

