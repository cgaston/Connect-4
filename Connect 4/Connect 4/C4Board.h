#pragma once

using namespace std;

class C4Board
{
public:
	C4Board();
	~C4Board();
	void displayBoard();
	bool placePiece(int move, bool firstMoves);
	char validMoves();
	void initBoard();
	bool boardIsFull();
private:
	char myBoard[6][7];
	bool isWinningMove(int row, int col);
	char getAt(int row, int col);
};

