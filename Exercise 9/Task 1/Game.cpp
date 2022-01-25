#include "Game.h"
#include "Player.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
using std::cout;
using std::endl;

void Game::modeSelect()
{
	cout << "Player vs Player (Enter 1)\n";
	cout << "Player vs Computer (Enter 2)\n";
}
void Game::playerVsPlayer()
{
	Player c;
	c.PvP();
	cout << "Player 1 hand: " << c.player1Hand;
	cout << "   Player 1 guess : " << c.getplayer1Guess() << endl;
	cout << "Player 2 hand: " << c.player2Hand;
	cout << "   Player 2 guess : " << c.getplayer2Guess() << endl;

	c.getplayer1Guess() == c.player2Hand ? cout << "Player 1 won"
		: (c.getplayer2Guess() == c.player1Hand) ? cout << "Player 2 won"
		: cout << "No winner";

}
void Game::playerVsComputer()
{
	Player c;
	c.PvE();
	cout << "Player 1 hand: " << c.player1Hand;
	cout << "   Player 1 guess : " << c.getplayer1Guess() << endl;
	cout << "Computer hand: " << c.computerHand;
	cout << "   Computer guess : " << c.getcomputerGuess() << endl;


	c.getplayer1Guess() == c.computerHand ? cout << "Player 1 won"
		: (c.getcomputerGuess() == c.player1Hand) ? cout << "Player 2 won"
		: cout << "No winner";

}

void Game::gameLoop()
{
	system("cls");
	modeSelect();
	while (1)
	{
		cin >> modeInput;
		if (modeInput == 1)
			playerVsPlayer();
		else if (modeInput == 2)
			playerVsComputer();
		else {
			system("cls");
			cout << "Invalid input";
			Sleep(600);
			gameLoop();
		}
	}
}