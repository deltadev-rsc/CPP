CC=gcc
CXX=g++

# flag for ncurses
CXXF=-lncursesw 

all: build

build: src/main.cpp src/chscript.cpp 
	$(CXX) -o bin/prog src/main.cpp $(CXXF)
	$(CXX) -o bin/cs src/chscript.cpp $(CXXF)

run:
	./bin/prog

clean:
	rm -f bin/prog bin/cs

.PHONY: build
