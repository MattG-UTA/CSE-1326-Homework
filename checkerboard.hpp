#include "checkerpiece.hpp"
#include <array>

class checkerboard 
{
	public:
	std::array<std::array<checkerpiece*, 8>, 8> checkerBoard;
	int rowCounter;
	int columnCounter;
	
	checkerboard();
	
	void setupBoard();
	void displayBoard();
	void turn();
	void setCounters();
		
};
