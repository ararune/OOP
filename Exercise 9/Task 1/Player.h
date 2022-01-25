#pragma once
#include "Game.h"

class Player
{
public:
	int player1Hand, player2Hand, computerHand;
	int player1Guess, player2Guess, computerGuess;

	void PvP();
	void PvE();
	// getters
	int getplayer1Hand();
	int getplayer2Hand();
	int getComputerHand();
	int getplayer1Guess();
	int getplayer2Guess();
	int getcomputerGuess();

	// setters
	void setplayer1Hand();
	void setplayer2Hand();
	void setComputerHand();
	void setplayer1Guess();
	void setplayer2Guess();
	void setcomputerGuess();

};
