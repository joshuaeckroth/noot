#include "note.h"
#include <time.h>

Note::Note() { }

Note::Note(const std::string& body) {
	this->id = -1;
	this->body = body;
	// get unix time
	this->timestamp = time(0);
}

void Note::setId(int id) {
	this->id = id;
}

int Note::getId() const {
	return this->id;
}

void Note::setBody(const std::string& body) {
	this->body = body;
}

const std::string& Note::getBody() const {
	return this->body;
}

