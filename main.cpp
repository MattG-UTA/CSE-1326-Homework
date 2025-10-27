//Matthew Gutierrez
//ID: 1002333697
//Assignment 3

#include <stdio.h>
#include <array>
#include <cstdio>
#include <cstring>
#include "checkerboard.hpp"
#include "player.hpp"
#include "computer.hpp"

int main ( int argc, char *argv[]) 
{
	
	checkerboard gameBoard;
	gameBoard.setupBoard();
	gameBoard.displayBoard();
	char buffer[300];
	int moves = 0;
	player* humanPlayer = new player();
	while(1) 
	{
		scanf("%[^\n]%*c", buffer);
		if (strcmp(buffer, "stop") == 0) 
		{
        	break;
    		}
		humanPlayer->movePiece(buffer);
		gameBoard.makeMove(humanPlayer->y, humanPlayer->x, humanPlayer->Y, humanPlayer->X);
		gameBoard.displayBoard();
		moves++;
	}
	humanPlayer->printMoves();
	delete humanPlayer;
	humanPlayer = nullptr;
	gameBoard.eraseBoard();
	
	
	return 0;
}
