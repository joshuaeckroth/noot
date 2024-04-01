#ifndef NOTE_H
#define NOTE_H

#include <string>

class Note {
private:
	int id; // -1 means not assigned
	std::string body;
	long timestamp;

public:
	Note();
	Note(const std::string& body);
	void setId(int id);
	int getId() const;
	void setBody(const std::string& body);
	const std::string& getBody() const;

};


#endif

