OBJECTS=List.o OList.o main.o Node.o
CXXFLAGS=-g

main: $(OBJECTS)
	g++ -g -o main $(OBJECTS)

tests: tests.o OList.o Node.o
	g++ -o tests tests.o OList.o Node.o

List.o: List.cpp Node.h List.h

main.o: main.cpp List.h Node.h OList.h

Node.o: Node.cpp Node.h

OList.o: OList.cpp Node.h OList.h

tests.o: tests.cpp doctest.h OList.h Node.h
	g++ -c -std=c++11 -Wall tests.cpp

clean:
	rm -f $(OBJECTS)
	rm tests.o