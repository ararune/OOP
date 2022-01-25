#pragma once
#include "Player.h"
#include <vector>

class Human : public Player
{
public:
	vector <int> vP1 = { 1, 2, 5 };
	int inputP1 = 0;
	int guessP1 = 0;
	int sumP1 = 0;


	vector <int> vP2 = { 1, 2, 5 };
	int inputP2 = 0;
	int guessP2 = 0;
	int sumP2 = 0;

	vector <int> v = { 1, 2, 5 };

	friend class Player;

	void printChoices(vector <int> vectorPlayer);

	int Player1Input();
	int Player1Guess();
	int Player2Input();
	int Player2Guess();
};

