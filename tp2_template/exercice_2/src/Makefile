CXXFLAGS=-g -O2 -Wall -Wextra -std=c++17
CXX=g++

all: main

main: main.o
	${CXX} $^ -o $@

main.o: main.cpp export_matlab.hpp bezier.hpp

clean:
	rm -f *.o *~ main