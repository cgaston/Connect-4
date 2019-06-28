#include "HumanPlayer.h"
#include <iostream>
#include <sstream>

using namespace std;

HumanPlayer::HumanPlayer()
{
}


HumanPlayer::~HumanPlayer()
{
}

int HumanPlayer::move(C4Board& b1)
{
	short colNum;
	do
	{
		colNum = getUserResponse("Choose a column 1-7 or q to quit: " , "Q1234567")

	} while (true);
	return colNum;
}