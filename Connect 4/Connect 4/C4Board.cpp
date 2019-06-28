#include "C4Board.h"
#include <iostream>
#include "math.h"

using namespace std;

C4Board::C4Board()
{
	initBoard();
}


C4Board::~C4Board()
{
}

void C4Board::initBoard()
{
	for (int r = 0; r < 6; r++)
	{
		for (int c = 0; c < 7; c++)
		{
			myBoard[r][c] = 0;
		}
	}
}

void C4Board::displayBoard()
{
	for (int r = 0; r < 6; r++)
	{
		for (int c = 0; c < 7; c++)
		{
			printf("+---");
		}
		printf("+\n");

		for (int c = 0; c < 7; c++)
		{
			if (myBoard[r][c] > 0)
				printf("| X ");
			else if (myBoard[r][c] < 0)
				printf("| O ");
			else
				printf("|   ");
		}
		printf("|\n");
	}
	for (int c = 0; c < 7; c++)
	{
		printf("+---");
	}
	printf("+\n");
	cout << endl;
}

char C4Board::validMoves()
{
	char movesVal = 0; //binary representation of valid moves
	for (int c = 0; c < 7; c++) //iterate through columns of the board to test if top squares are open
	{
		movesVal <<= 1;
		movesVal |= (myBoard[0][c] == 0); //if top square of board in current column is open then turn on bit for that column
	}
	return movesVal;
}

bool C4Board::placePiece(int col, bool firstMoves)
{
	col--;
	int r;
	for (r = 5; r >= 0; r--) //iterate through rows starting at bottom of board and going up at column passed in and find first empty space available
	{
		if (myBoard[r][col] == 0) // found first empty space available
		{
			myBoard[r][col] = (firstMoves ? 1 : -1); //set value at current location to 1 or -1 depening on who's turn it is
			break;
		}
	}
	return isWinningMove(r, col); //return whether move made was a winnign move or not
}

bool C4Board::isWinningMove(int row, int col)
{
	char playerNum = getAt(row, col); //get the player based on value of latest move
	char sum;
	char xPos;
	char yPos;
	char xDif[4] = { 1, 1, 1, 0 }; // array to keep track of changes in column position for the 4 directions to be tested
	char yDif[4] = { 1, 0, -1, 1 }; // array to keep track of changes in row position for the 4 directions to be tested
	for (int i = 0; i <= 3; i++) //run loop 4 times to test the 4 directions (horizontal, vertical, and 2 diagonals)
	{
		sum = 0;
		xPos = col - (3 * xDif[i]); //set initial column to test based on what direction you are testing
		yPos = row - (3 * yDif[i]); //set initial row to test based on what direction you are testing
		for (int c = 0; c <= 6; c++) //test from 3 positions before latest move to 3 positions after
		{
			if (getAt(xPos, yPos) == playerNum) //increment sum if position tested is the same as the player otherwise reset the sum to 0
				sum++;
			else
				sum = 0;
			xPos += xDif[i]; //move to the next column to be tested
			yPos += xDif[i]; //move to the next row to be tested
			if (sum == 4) //if you have found 4 in a row then the move wins
				return true;
		}
	}
	return false; //no winning move was found
}

char C4Board::getAt(int row, int col)
{
	char returnVal = SCHAR_MAX;
	if (row >= 0 && col >= 0 && row <= 5 && col <= 6) // if row and col is a valid index then return value of board at that position otherwise return max char
		returnVal = myBoard[row][col];
	return returnVal;
}

bool C4Board::boardIsFull() //used to help determine if game was a tie or not
{
	for (int r = 0; r < 6; r++)
	{
		for (int c = 0; c < 7; c++)
		{
			if (myBoard[r][c] == 0)
				return false;
		}
	}
	return true;
}
