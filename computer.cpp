#include "computer.hpp"
//#include "checkerboard.hpp"
//#include "checkerpiece.hpp" 
//#include <cstring>
//#include <cstdio>

computer::computer() 
{
	 y = 0;
	 x = 0;
	 Y = 0;
	 X = 0;
	 leftRight = true;
	 convertedMove = new char[(size_t)9];
	 convertedMove[2] = ' ';
	 convertedMove[3] = 't';
	 convertedMove[4] = 'o';
	 convertedMove[5] = ' ';
	 convertedMove[8] = '\0';	
};

void computer::decideMove() 
{
	x = pieces[0][0]; 
	y = pieces[0][1];
	if(x > 0) 
	{
		X = x - 1;
		if(leftRight) 
		{
			Y = y+1;
		}
		else 
		{
			Y = y-1;
		}
	}
	else 
	{ 
	  printf("Reached the top.\n");
	}
	
	convertFrom(x,y);	
	convertTo(X,Y);
	movePiece(convertedMove);
	leftRight = !leftRight;
}

void computer::movePiece(char *userMove) 
{
	char *tempString = new char[strlen(userMove) +1];
	strcpy(tempString, userMove);
	moves.push_back(tempString);
}

void computer::getPieces(const std::array<std::array<checkerpiece*, 8>,8>& checkerArray) 
{
	int rowIndex = 0;
	for (const auto& row : checkerArray) 
	{
		int colIndex = 0;
		for (const auto& element : row) 
		{
			if((element != nullptr) && (element->color == checkerpiece::Color::Black)) 
			{
				std::vector<int> piece = {rowIndex,colIndex};
				pieces.push_back(piece);
			}
			colIndex++;
		}
		rowIndex++;
	}
}

void computer::printMoves() 
{
	printf("Computer Moves:\n");
	for(const auto& element : moves) 
	{
		printf("%s\n" , element);
	}
}

void computer::printPieces() 
{	
	printf("Computer Pieces: \n");	
//	pieces.erase(pieces.begin());
	for (const auto& row : pieces) 
	{
		convertFrom(row[0],row[1]);
		convertTo((row[0]-1),(row[1]+1));
		printf("%s\n", convertedMove);
	}
}



void computer::convertFrom(int y, int x) 
{
	switch(x) 
	{
	case 0:
	convertedMove[0] = 'A';
	//printf("A");
	break;
	case 1:
	convertedMove[0] = 'B';
	//printf("B");
	break;
	case 2:
	convertedMove[0] = 'C';
	//printf("C");
	break;
	case 3:
	convertedMove[0] = 'D';
	//printf("D");
	break;
	case 4:
	convertedMove[0] = 'E';
	//printf("E");
	break;
	case 5:
	convertedMove[0] = 'F';
	//printf("F");
	break;
	case 6:
	convertedMove[0] = 'G';
	//printf("G");
	break;
	case 7:
	convertedMove[0] = 'H';
	//printf("H");
	break;
			
	}
	switch(y) 
	{
	case 0:
	convertedMove[1] = '8';
	//printf("8");
	break;
	case 1:
	convertedMove[1] = '7';
	//printf("7");
	break;
	case 2:
	convertedMove[1] = '6';
	//printf("6");
	break;
	case 3:
	convertedMove[1] = '5';
	//printf("5");
	break;
	case 4:
	convertedMove[1] = '4';
	//printf("4");
	break;
	case 5:
	convertedMove[1] = '3';
	//printf("3");
	break;
	case 6:
	convertedMove[1] = '2';
	//printf("2");
	break;
	case 7:
	convertedMove[1] = '1';
	//printf("1");
	break;
	}
	
}

void computer::convertTo(int Y, int X) 
{
	
	switch(X) 
	{
	case 0:
	convertedMove[6] = 'A';
	//printf("A");
	break;
	case 1:
	convertedMove[6] = 'B';
	//printf("B");
	break;
	case 2:
	convertedMove[6] = 'C';
	//printf("C");
	break;
	case 3:
	convertedMove[6] = 'D';
	//printf("D");
	break;
	case 4:
	convertedMove[6] = 'E';
	//printf("E");
	break;
	case 5:
	convertedMove[6] = 'F';
	//printf("F");
	break;
	case 6:
	convertedMove[6] = 'G';
	//printf("G");
	break;
	case 7:
	convertedMove[6] = 'H';
	//printf("H");
	break;
			
	}
	switch(Y) 
	{
	case 0:
	convertedMove[7] = '8';
	//printf("8");
	break;
	case 1:
	convertedMove[7] = '7';
	//printf("7");
	break;
	case 2:
	convertedMove[7] = '6';
	//printf("6");
	break;
	case 3:
	convertedMove[7] = '5';
	//printf("5");
	break;
	case 4:
	convertedMove[7] = '4';
	//printf("4");
	break;
	case 5:
	convertedMove[7] = '3';
	//printf("3");
	break;
	case 6:
	convertedMove[7] = '2';
	//printf("2");
	break;
	case 7:
	convertedMove[7] = '1';
	//printf("1");
	break;
	}
}

computer::~computer() 
{

}
