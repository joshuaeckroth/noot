#ifndef NOTEFILE_H
#define NOTEFILE_H


class NoteFile
{
public:
	// exists() returns true if the notes file exists;
	// it does not create it.
	bool exists() const;
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
	void remove(const Note& note);
	void update(const Note& note);
	int add(const Note& note);

#endif

