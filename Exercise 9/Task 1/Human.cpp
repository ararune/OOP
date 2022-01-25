#include "Human.h"
#include "Game.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <algorithm>

using std::cout;
using std::endl;

void Human::printChoices(vector <int> vectorPlayer)
{
	for (auto& i : vectorPlayer)
		cout << i << ' ';
}
int Human::Player1Input()
{
	system("cls");
	cout << "Player 1\nPick a number: ";
	printChoices(vP1);
	cout << "\nPress 3 to end selection\n";

	cin >> inputP1;
	if (std::find(vP1.begin(), vP1.end(), inputP1) != vP1.end()) {		// if input element in player 1 vector, remove
		vP1.erase(remove(vP1.begin(), vP1.end(), inputP1), vP1.end());
		sumP1 += inputP1;
		Player1Input();
	}
	else if (std::find(v.begin(), v.end(), inputP1) != v.end()) {		// else if in ref vector and pressed again, push back
		vP1.push_back(inputP1);
		sumP1 -= inputP1;
		Player1Input();
	}
	else if (inputP1 == 3)
		return sumP1;

	else
	{
		cout << "Invalid input";
		Sleep(500);
		Player1Input();
	}
}

int Human::Player1Guess()
{
	system("cls");
	cout << "Pick a number:";
	cin >> guessP1;
	return guessP1;
}

int Human::Player2Input()
{
	system("cls");
	cout << "Player 2\nPick a number: ";
	printChoices(vP2);
	cout << "\nPress 3 to end selection\n";

	cin >> inputP2;
	if (std::find(vP2.begin(), vP2.end(), inputP2) != vP2.end()) {
		vP2.erase(remove(vP2.begin(), vP2.end(), inputP2), vP2.end());
		sumP2 += inputP2;
		Player2Input();
	}
	else if (std::find(v.begin(), v.end(), inputP2) != v.end()) {
		vP2.push_back(inputP2);
		sumP2 -= inputP2;
		Player2Input();
	}
	else if (inputP2 == 3)
		return sumP2;

	else
	{
		cout << "Invalid input";
		Sleep(500);
		Player2Input();
	}
}

int Human::Player2Guess()
{
	system("cls");
	cout << "Guess a number:";
	cin >> guessP2;
	return guessP2;
}
