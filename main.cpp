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
	//int redOrBlack = -1;
	player* humanPlayer = new player();
	computer* verseComputer = new computer();
	//verseComputer->getPieces(gameBoard.checkerBoard);
	//verseComputer.printPieces();
	/*while(!humanPlayer->redBlack(redOrBlack)) 
	{
		printf("Enter 1 to play Red(x) or 0 to play Black(o): ");
		scanf("%d", &redOrBlack);
		//fscanf(stdin, "%d%[^\n]%*c", &redOrBlack);
	}*/
	//fscanf(stdin, "%[^\n]%*c", buffer);
	while(!gameBoard.gameOver) 
	{
		printf("Players turn:\n");
		printf("Enter move: ");
		//scanf("%[^\n]%*c", buffer);
		fscanf(stdin, "%[^\n]%*c", buffer);
		if (strcmp(buffer, "stop") == 0) 
		{
        	break;
    		}
		humanPlayer->movePiece(buffer);		
		gameBoard.makeMove(humanPlayer->y, humanPlayer->x, humanPlayer->Y, humanPlayer->X);
		printf("Computers Turn:\n");
		printf("Computers move: ");
		verseComputer->getPieces(gameBoard.checkerBoard);
		verseComputer->decideMove();
		printf("%d,%d,%d,%d\n",verseComputer->y,verseComputer->x,verseComputer->Y,verseComputer->X);
		gameBoard.makeMove(verseComputer->y,verseComputer->x,verseComputer->Y,verseComputer->X);
		//printf("%d,%d,%d,%d",verseComputer.y,verseComputer.x,verseComputer.Y,verseComputer.X);
		printf("%s\n", verseComputer->convertedMove);
		verseComputer->pieces.clear();
		//verseComputer->getPieces(gameBoard.checkerBoard);
		//gameBoard.displayBoard();		
		moves++;
		if( (gameBoard.redScore == 12) || (gameBoard.blackScore == 12) ) 
		{
			gameBoard.decideGame();
		}
	}
	humanPlayer->printMoves();
	verseComputer->printMoves();
	delete humanPlayer;
	humanPlayer = nullptr;
	delete verseComputer;
	verseComputer = nullptr;
	gameBoard.eraseBoard();
	
	
	return 0;
}
