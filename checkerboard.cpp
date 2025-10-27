#include "checkerboard.hpp"
#include <cstdlib>
#include <stdio.h>
#include <array>

checkerboard::checkerboard () 
{
	
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


void checkerboard::displayBoard() 
{

    printf("   A   B   C   D   E   F   G   H\n");
    printf(" ┌───┬───┬───┬───┬───┬───┬───┬───┐\n");

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
                    printf("│ X ");
                } else if (piece->color == checkerpiece::Color::Black) 
                {
                    printf("│ O ");
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
    if (checkerBoard[fromX][fromY]) 
    {
    	if (checkerBoard[toX][toY]) 
    	{
            delete checkerBoard[toX][toY];
            checkerBoard[toX][toY] = nullptr;
        }
        checkerBoard[toX][toY] = checkerBoard[fromX][fromY];
        checkerBoard[fromX][fromY] = nullptr;
    } 
    else 
    {
        printf("No piece to move from (%d, %d)\n", fromY, fromX);
    }
}
 

void	 checkerboard::turn() 
	 {
	 
	 }
	 
