#include "checkerpiece.hpp"
#include <stdio.h>
#include <cstdlib>

checkerpiece::checkerpiece(int boardY, int boardX) 
{
	yCord = boardY;
	xCord = boardX;
};

int checkerpiece::getY() 
{
	return yCord;
}

int checkerpiece::getX() 
{
	return xCord;
}

void checkerpiece::setColor() 
{
	{
		if(this->getY() <= 2) 
		{
			color = Color::Red;
		}
	}
	
	{
		if(this->getX() >= 6) 
		{
			color = Color::Black;
		}
	}	
}
