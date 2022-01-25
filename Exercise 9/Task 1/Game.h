#pragma once
using namespace std;

class Game
{
	int modeInput;
	friend class Player;

public:
	Game() { modeInput = 0; }
	void modeSelect();
	void gameLoop();
	void playerVsPlayer();
	void playerVsComputer();
};
