CXXFLAGS=-g -O2 -Wall -Wextra -std=c++11
CXX=g++

all: main

main: main.o vec2.o
	${CXX} $^ -o $@

main.o: main.cpp export_matlab.hpp bezier.hpp
vec2.o: vec2.cpp vec2.hpp

clean:
	rm -f *.o *~ main