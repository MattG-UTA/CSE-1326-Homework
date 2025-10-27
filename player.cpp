#include "player.hpp"
#include <cstring>
#include <cstdio>
player::player() 
{
	y = 0;
	x = 0;
	Y = 0;
	X = 0;
}


void player::movePiece(char *userMove) 
{
	char *tempString = new char [strlen(userMove) +1];
	strcpy(tempString, userMove);
	moves.push_back(tempString);
	this->parseMove(userMove);	
}

/*void player::parseMove(char *move) 
{
	char *piece = new char[strlen(move) + 1];
	piece = strtok(move, " ");
	this->convertPiece(piece);
	strtok(NULL, " ");
	char *place = new char[strlen(move) + 1];
	place = strtok(NULL, " ");
	this->convertPlace(place);
	printf("%d,%d to %d,%d\n", y,x,Y,X);
}*/

void player::parseMove(char *move) 
{
    char *piece = strtok(move, " ");
    strtok(NULL, " "); // skip "to"
    char *place = strtok(NULL, " ");
    this->convertPiece(piece);
    this->convertPlace(place);
    printf("%d,%d to %d,%d\n", y, x, Y, X);
}


void player::convertPiece(char *convert) 
{
	for(size_t i = 0; i < strlen(convert); i++) 
	{
		if(i == 0)
		{
		switch(convert[i]) 
		{
			case 'A':
			    	y = 0;
			        break;
			case 'B':
				y = 1;
				break;
			case 'C':
				y = 2;
				break;
			case 'D':
				y = 3;
				break;
			case 'E':
				y = 4;
				break;
			case 'F':
				y = 5;
				break;
			case 'G':
				y = 6;
				break;
			case 'H':
				y = 7;
				break; 
		}
		}
		else
		{
			switch(convert[i]) 
		{
			case '8':
			    	x = 0;
			        break;
			case '7':
				x = 1;
				break;
			case '6':
				x = 2;
				break;
			case '5':
				x = 3;
				break;
			case '4':
				x = 4;
				break;
			case '3':
				x = 5;
				break;
			case '2':
				x = 6;
				break;
			case '1':
				x = 7;
				break; 
		}
		}
	}
}

void player::convertPlace(char *convert) 
{
	for(size_t i = 0; i < strlen(convert); i++) 
	{
		if(i == 0)
			{
			switch(convert[i]) 
			{
				case 'A':
				    	Y = 0;
				        break;
				case 'B':
					Y = 1;
					break;
				case 'C':
					Y = 2;
					break;
				case 'D':
					Y = 3;
					break;
				case 'E':
					Y = 4;
					break;
				case 'F':
					Y = 5;
					break;
				case 'G':
					Y = 6;
					break;
				case 'H':
					Y = 7;
					break; 
			}
			}
			else
			{
				switch(convert[i]) 
			{
				case '8':
				    	X = 0;
				        break;
				case '7':
					X = 1;
					break;
				case '6':
					X = 2;
					break;
				case '5':
					X = 3;
					break;
				case '4':
					X = 4;
					break;
				case '3':
					X = 5;
					break;
				case '2':
					X = 6;
					break;
				case '1':
					X = 7;
					break; 
			}
			}
		}
}

void player::printMoves() 
{
	for(auto& element : moves) 
	{
		printf("%s\n", element);
	}
}

player::~player() 
{
	for (auto& element : moves) 
		{
			if(element != nullptr) 
			{
				delete[] element;
				element  = nullptr;
			}
		}
}
