#pragma once
#include "C4Board.h"


class Player
{
public:
	Player();
	~Player();
	virtual int move(C4Board& b1) = 0;
	virtual void resetGame() {}
	virtual bool educated() { return true; }
};

