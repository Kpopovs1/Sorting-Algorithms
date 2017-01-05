# Here's the flag for C++11 support and a flag asking to be warned about
# everything. 
FLAGS = -Wall -std=c++11

all: Sorter

Sorter: Lab5.o Sorter.o
	g++ $(FLAGS) Lab5.o Sorter.o -o Sorter

Sorter.o: Sorter.cpp Sorter.h
	g++ $(FLAGS) -c Sorter.cpp -o Sorter.o

Lab5.o: Lab5.cpp Sorter.h
	g++ $(FLAGS) -c Lab5.cpp -o Lab5.o
	
clean:
	rm -f *.o Sorter

