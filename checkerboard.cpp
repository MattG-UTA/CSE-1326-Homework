#include "checkerboard.hpp"
#include <stdio.h>
#include <array>

	checkerboard::checkerboard () 
	{
		 rowCounter = 0;
		 columnCounter = 0;
	}
	
	/*
	void setupBoard();
	void displayBoard();
	void turn();
	void setCounters();
	 */
	 
void	 checkerboard::setupBoard() 
	 {
	 	for(auto& row : checkerBoard) 
		{
			
			for(auto& element : row) 
			{
				if((rowCounter + columnCounter)% 2 == 0)
				{
					delete element;
					element = nullptr;
				}
				else
				{
					element->setColor();
				}
				columnCounter++;
			}
			rowCounter++;
		}
	 }
	 
void	 checkerboard::displayBoard() 
	 {
	 	printf("   A   B   C   D   E   F   G   H\n");
		printf(" ┌───┬───┬───┬───┬───┬───┬───┬───┐\n");
	 	for(const auto &row : checkerBoard) 
		{
			printf("%d", (rowCounter+1));
			for(const auto &element : row) 
			{
			
				if((rowCounter + columnCounter)% 2 == 0)
				{
					printf("│▒▒▒");
				}
				else
				{	
					{
						if(element->color == checkerpiece::Color::Red) 
						{
							printf("│ X ");
						}
					}
					
					{
						if(element->color == checkerpiece::Color::Black) 
						{
							printf("│ O ");
						}
					}
					//printf("│ %c ", element);
				}
				columnCounter++;
			
			}
	
		printf("│");
		printf("\n");
		if(rowCounter <= 6)
		{
			printf(" ├───┼───┼───┼───┼───┼───┼───┼───┤\n");
		}
		else 
		{
			printf(" └───┴───┴───┴───┴───┴───┴───┴───┘\n");	
		}
		rowCounter++;

		}
	 }
	 
void	 checkerboard::turn() 
	 {
	 
	 }
	 
void	 checkerboard::setCounters() 
	 {
	 	rowCounter = 0;
	 	columnCounter = 0;
	 }
