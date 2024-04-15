CXXFLAGS = -Wall -g -std=c++11

all: noot n nn ns

main.o: main.cpp note.h notefile.h
	g++ $(CXXFLAGS) -c main.cpp

note.o: note.cpp note.h
	g++ $(CXXFLAGS) -c note.cpp

notefile.o: notefile.cpp notefile.h note.h
	g++ $(CXXFLAGS) -c notefile.cpp

noot: main.o note.o notefile.o
	g++ $(CXXFLAGS) -o noot main.o note.o notefile.o

n: noot
	ln -s noot n

nn: noot
	ln -s noot nn

ns: noot
	ln -s noot ns

clean:
	@rm -f *.o noot n nn ns

