#pragma once
class checkerpiece 
{	
	public:
	enum class Color {Red, Black, None};
	enum class Type {Pawn, King};
	int yCord;
	int xCord;
	Color color;
	Type unit;
	
	checkerpiece();
	
	checkerpiece(int boardY, int boardX);

	//checkerpiece(const checkerpiece& hardCopy);	
		
	int getY();
	int getX();
	void setColor();
	void makeKing();
		
};
