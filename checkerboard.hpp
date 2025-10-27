#pragma once
#include "checkerpiece.hpp"
#include <array>

class checkerboard 
{
	public:
	std::array<std::array<checkerpiece*, 8>, 8> checkerBoard;
	
	checkerboard();
	
	void setupBoard();
	void eraseBoard();
	void displayBoard();
	void makeMove(int fromY, int fromX, int toY, int toX);
	void turn();
	void setCounters();
		
};
