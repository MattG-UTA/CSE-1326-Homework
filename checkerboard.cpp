#include "checkerboard.hpp"
#include <cstdlib>
#include <stdio.h>
#include <array>

checkerboard::checkerboard () 
{
	gameOver = false;
	validMove = false;
	redScore = 0;
	blackScore = 0;
}
	 
	 
void checkerboard::setupBoard() 
{
    int rowIndex = 0;
    for (auto& row : checkerBoard) 
    {
        int colIndex = 0;
        for (auto& element : row) 
        {
            if ((rowIndex + colIndex) % 2 == 0) 
            {
                element = nullptr;
            } else {
                element = new checkerpiece(rowIndex, colIndex);
                element->setColor();
            }
            ++colIndex;
        }
        ++rowIndex;
    }
}

/*
void checkerboard::displayBoard() 
{
	for(auto& row : checkerBoard) 
	{
		for(auto& element : row) 
		{
			printf(" %p ", element);
		}
		printf("\n");
	}
}*/

void checkerboard::displayBoard() 
{

    printf("   A   B   C   D   E   F   G   H  \tScores:\n");
    printf(" ┌───┬───┬───┬───┬───┬───┬───┬───┐ \t(Player) Red(x) = %d \t (Computer) Black(o) = %d\n", redScore , blackScore);

    for (int row = 0; row < 8; ++row) 
    {
     
        printf("%d", 8 - row);

        for (int col = 0; col < 8; ++col) 
        {
            checkerpiece* piece = checkerBoard[row][col];

            if ((row + col) % 2 == 0) 
            {
             
                printf("│▒▒▒");
            } 
            else if (piece != nullptr) 
            {
               
                if (piece->color == checkerpiece::Color::Red) 
                {
                	if(piece->unit == checkerpiece::Type::King) 
                	{
                		printf("│ X ");
                	}
                	else
                	{
                		printf("│ x ");
                	}
                } 
                else if (piece->color == checkerpiece::Color::Black) 
                {
                	if(piece->unit == checkerpiece::Type::King) 
                	{
                		printf("│ O ");
                	}
                	else 
                	{
                		printf("│ o ");
                	}
                    
                } else {
                    printf("│   ");
                }
            } 
            else 
            {
                printf("│   ");
            }
        }

        printf("│\n");

        if (row < 7) {
            printf(" ├───┼───┼───┼───┼───┼───┼───┼───┤\n");
        } else {
            printf(" └───┴───┴───┴───┴───┴───┴───┴───┘\n");
        }
    }
}

void checkerboard::decideGame() 
{
	gameOver = true;
}

void checkerboard::eraseBoard() 
	{
		for (auto& row : checkerBoard) 
		{
			for(auto& element : row) 
			{
				if(element != nullptr) 
				{
					delete element;
					element  = nullptr;
				}
			}
		}
	}

void checkerboard::makeMove(int fromY, int fromX, int toY, int toX) 
{

    if(checkDelta(fromY, fromX, toY, toX)) 
    {
    	if ( checkerBoard[fromX][fromY] && checkerBoard[toX][toY]) 
    	{
    	    checkerpiece* temp = checkerBoard[fromX][fromY];
    	    if(compare(checkerBoard[fromX][fromY], checkerBoard[toX][toY])) 
    	    {
    	    	checkerBoard[toX][toY]->color = checkerpiece::Color::None;
    	    	if(checkerBoard[fromX][fromY]->color == checkerpiece::Color::Red) 
    	    	{
    	    	        if( (toX == 7) && ((toY % 2 ) == 0) ) 
    	    	        {
    	    	        	checkerBoard[fromX][fromY]->makeKing();
    	    	        	printf("Pawn at (%d,%d) made king\n", toX,toY);
    	    	        }
    	    		redScore++;
    	    	}
    	    	else if(checkerBoard[fromX][fromY]->color == checkerpiece::Color::Black) 
    	    	{
    	    		if( ( toX == 0 ) && ( toY % 2 != 0) ) 
    	    		{
    	    			checkerBoard[fromX][fromY]->makeKing();
    	    			printf("Pawn at (%d,%d) made king\n", toX,toY);
    	    		}
    	    		blackScore++;
    	    	}
    	    }
    	    checkerBoard[fromX][fromY] = checkerBoard[toX][toY];
    	    checkerBoard[toX][toY] = temp;
    	    validMove = true;	    
    	} 
    	else 
    	{
    	    printf("Invalid Move\n"); 
    	}
    }
    else 
    {
    	printf("Invalid Move\n");
    }
    if(validMove) 
    {
    	displayBoard();
    	validMove = false;
    }
}
 
bool checkerboard::compare(checkerpiece* one, checkerpiece* two) 
{
	if( (one->color == checkerpiece::Color::Red && two->color == checkerpiece::Color::Black) || (one->color == checkerpiece::Color::Black && two->color == checkerpiece::Color::Red) ) 
	{
		return true;
	}
	else { return false; }
}

bool checkerboard::checkDelta(int fromY, int fromX, int toY, int toX) 
{
    if( (checkerBoard[fromX][fromY] != nullptr) && (checkerBoard[toX][toY] != nullptr) ) 
    {
	
	if(checkerBoard[fromX][fromY]->unit == checkerpiece::Type::King) 
	{
		if( ((fromY-toY) == 1 || (fromY-toY) == -1) && ((fromX-toX) == -1 || (fromX-toX == 1)) ) 
		{
			return true;
		}
	}
	else
	{
		if(checkerBoard[fromX][fromY]->color == checkerpiece::Color::Red) 
		{
			if( ((fromY-toY) == -1 || (fromY-toY) == 1 ) && ( fromX-toX) == -1 ) 
			{
				return true;
			}
			else 
			{
				printf("Pawn can not move backwards.\n");
				return false;
			}
		}
		if(checkerBoard[fromX][fromY]->color == checkerpiece::Color::Black) 
		{
			if( ((fromY-toY) == -1 || (fromY-toY) == 1 ) && ( fromX-toX == 1) ) 
			{
				return true;
			}
			else 
			{
				printf("Pawn can not move backwards. \n");
				return false;
			}	
		}
	}
    }
    else { return false;}
    return false;
}

void    checkerboard::turn() 
	 {
	 
	 }
	 
