#pragma once
class checkerpiece 
{	
	public:
	enum class Color {Red, Black, None};
	int yCord;
	int xCord;
	Color color;
	
	checkerpiece();
	
	checkerpiece(int boardY, int boardX);

	//checkerpiece(const checkerpiece& hardCopy);	
		
	int getY();
	int getX();
	void setColor();
		
};
