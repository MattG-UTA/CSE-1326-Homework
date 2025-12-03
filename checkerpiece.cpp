#include "checkerpiece.hpp"
#include <stdio.h>
#include <cstdlib>

checkerpiece::checkerpiece(int boardY, int boardX) 
{
	yCord = boardY;
	xCord = boardX;
	unit = Type::Pawn;
};

/*checkerpiece::checkerpiece(const checkerpiece& hardCopy)
{
        yCord = hardCopy.yCord;
        xCord = hardCopy.xCord;
        color = hardCopy.color;
}*/

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
		if(this->getY() < 3) 
		{
			color = Color::Red;
		}
		else if(this->getY() > 4) 
		{
			color = Color::Black;
		} 
		else {color = Color::None; }	
}

void checkerpiece::makeKing() 
{
	unit = Type::King;
}
