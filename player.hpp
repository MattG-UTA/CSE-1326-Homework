#include "movementinterface.hpp"
#include <vector>
#include <cstring>

class player : movementinterface 
{	
	public:
	
	int y;
	int x;
	int Y;
	int X;
	
	player();
	
	std::vector<char*> moves; 
	void movePiece (char *userMove) override;
	void parseMove(char *move);
	void convertPiece(char *convert);
	void convertPlace(char *convert);
	void printMoves();
	virtual ~player();
};
