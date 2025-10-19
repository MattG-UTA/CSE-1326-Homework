
class checkerpiece 
{	
	public:
	enum class Color {Red, Black};
	int yCord;
	int xCord;
	Color color;
	
	checkerpiece(int boardY, int boardX);
	
	int getY();
	int getX();
	void setColor();
		
};
