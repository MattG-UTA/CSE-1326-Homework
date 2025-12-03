#pragma once
#include "checkerpiece.hpp"
#include <array>

class checkerboard 
{
	public:
	std::array<std::array<checkerpiece*, 8>, 8> checkerBoard;
	bool validMove;
	bool gameOver;
	int redScore;
	int blackScore;
	
	checkerboard();
	
	void setupBoard();
	void eraseBoard();
	void displayBoard();
	void decideGame();
	void makeMove(int fromY, int fromX, int toY, int toX);
	bool compare(checkerpiece* one, checkerpiece* two);
	bool checkDelta(int fromY, int fromX, int toY, int toX);
	void turn();
	void setCounters();
		
};
