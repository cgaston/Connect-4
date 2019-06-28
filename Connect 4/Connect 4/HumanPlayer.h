#pragma once
#include "Player.h"
class HumanPlayer :
	public Player
{
public:
	HumanPlayer();
	~HumanPlayer();
	int move(C4Board& b1);
};

