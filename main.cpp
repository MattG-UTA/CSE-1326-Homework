//Matthew Gutierrez
//ID: 1002333697
//Assignment 3

#include <stdio.h>
#include <array>
#include "checkerboard.hpp"

int main ( int argc, char *argv[]) 
{
	
	checkerboard gameBoard;
	gameBoard.setupBoard();
	gameBoard.setCounters();
	gameBoard.displayBoard();
	
	
	return 0;
}
