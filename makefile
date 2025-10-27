CXXFLAGS = -Wall -g -std=gnu++17
CXX = g++

all: HW3

HW3: main.o checkerboard.o checkerpiece.o player.o computer.o
	$(CXX) $(CXXFLAGS) -o HW3 main.o checkerboard.o checkerpiece.o player.o computer.o

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

checkerboard.o: checkerboard.cpp
	$(CXX) $(CXXFLAGS) -c checkerboard.cpp	

checkerpiece.o: checkerpiece.cpp
	$(CXX) $(CXXFLAGS) -c checkerpiece.cpp
	
player.o: player.cpp
	$(CXX) $(CXXFLAGS) -c player.cpp

computer.o: computer.cpp
	$(CXX) $(CXXFLAGS) -c computer.cpp	

.PHONY: all clean

clean:
	rm -rf HW3 main.o checkerboard.o checkerpiece.o player.o computer.o

