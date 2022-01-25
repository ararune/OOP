#pragma once
#include "Player.h"
#include <random>



class Computer : public Player
{
public:
	int computerSum = 0;
	int computerGuess = 0;
	vector <int> computerVector = { 0, 1, 2, 3, 5, 6, 7, 8 };

	int ComputerInput();
	int ComputerGuess();
};
