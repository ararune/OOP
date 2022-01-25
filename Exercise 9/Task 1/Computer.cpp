#include "Computer.h"
#include <random>


int Computer::ComputerInput()
{
	std::random_device random_device;
	std::mt19937 engine{ random_device() };
	std::uniform_int_distribution<int> dist(0, computerVector.size() - 1);
	int random_element = computerVector[dist(engine)];
	return computerSum += random_element;
}

int Computer::ComputerGuess()
{
	std::random_device random_device;
	std::mt19937 engine{ random_device() };
	std::uniform_int_distribution<int> dist(0, computerVector.size() - 1);
	int random_element = computerVector[dist(engine)];
	return computerGuess += random_element;
}