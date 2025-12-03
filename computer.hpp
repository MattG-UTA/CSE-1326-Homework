#include <vector>
#include <array>
#include <cstring>
#include <cstdio>
#include "movementinterface.hpp"
//#include "checkerboard.hpp"
#include "checkerpiece.hpp" 

class computer : movementinterface
{
	public:
	
	int y;
	int x;
	int Y;
	int X;
	bool leftRight;
	char* convertedMove;
	computer();
	std::vector<std::vector<int>> pieces;	
	std::vector<char*> moves; 
	
	void decideMove();
	void printMoves();
	void movePiece(char *userMove) override;
	void getPieces(const std::array<std::array<checkerpiece*, 8>,8>& checkerArray);
	void printPieces();
	void convertFrom(int y, int x);
	void convertTo(int Y, int X);
	virtual ~computer();
};
