// Connect 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include "Player.h"
#include "HumanPlayer.h"

using namespace std;

int getUserResponse(string s1, string s2);
void playGame(Player& p1, Player& p2, C4Board& b1);

int main()
{
	C4Board c1;
	Player* p1;
	Player* p2;
	int respInd = getUserResponse("How many players do you want (1-2_?: ", "012");
	if (respInd == 2)
	{
		p1 = new HumanPlayer;
		p2 = new HumanPlayer;
	}
	else
	{
		p1 = new HumanPlayer;
		p2 = new HumanPlayer;
	}

	do
	{
		playGame(*p1, *p2, c1);

		int paResp = getUserResponse("Do you want to play again Y/N: ", "YN");
		if (paResp == 1)
			break;
	} while (true);
	delete(p1);
	delete(p2);
}

int getUserResponse(string question, string accResp) //take input of a question and list of acceptable responses and output question to user and only let them continue with acceptable response
{
	string input;
	int result;
	do
	{
		cout << question;
		getline(cin, input);
		result = accResp.find(toupper(input[0])); //run loop until user enters a response that can be found in accResp and return index where it was found (case insensitive)
	} while (result == string::npos);
	return result;
}

void playGame(Player& p1, Player& p2, C4Board& b1)
{
	b1.initBoard();
	p1.resetGame();
	p2.resetGame();
	Player* players[2]{ &p1, &p2 };
	int move = 0;
	b1.displayBoard();
	char player = 0;
	do
	{
		move = players[player]->move(b1);
		if (move == 0)
		{
			printf("Game has ended.\n");
			break;
		}
		if (b1.placePiece(move, player == 0))
		{
			b1.displayBoard();
			printf("Player %d wins!\n", player + 1);
			break;
		}
		if (b1.boardIsFull())
		{
			printf("It was a tie\n");
		}

	} while (!b1.boardIsFull());
}