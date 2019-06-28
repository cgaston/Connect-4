#pragma once
#include "Player.h"
#include <list>

using namespace std;

class CPUPlayer
	: public Player
{
public:
	CPUPlayer();
	~CPUPlayer();
	int move(C4Board& b1);
	void resetGame();
	bool educated() { return isEducated; }
private:
	bool isEducated;

};

