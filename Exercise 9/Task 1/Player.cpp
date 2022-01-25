#include "Player.h"
#include "Human.h"
#include "Computer.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

void Player::PvP()
{
	setplayer1Hand();
	setplayer1Guess();

	setplayer2Hand();
	setplayer2Guess();
}

void Player::PvE()
{
	setplayer1Hand();
	setplayer1Guess();

	setComputerHand();
	setcomputerGuess();
}
void Player::setplayer1Hand() { Human b;    player1Hand = b.Player1Input(); }
void Player::setplayer2Hand() { Human b;    player2Hand = b.Player2Input(); }
void Player::setComputerHand() { Computer d; computerHand = d.ComputerInput(); }

void Player::setplayer1Guess() { Human b;    player1Guess = b.Player1Guess(); }
void Player::setplayer2Guess() { Human b;    player2Guess = b.Player2Guess(); }
void Player::setcomputerGuess() { Computer d; computerGuess = d.ComputerGuess(); }

int Player::getplayer1Guess() { return player1Guess; }
int Player::getplayer2Guess() { return player2Guess; }
int Player::getcomputerGuess() { return computerGuess; }
int Player::getplayer1Hand() { return player1Hand; }
int Player::getplayer2Hand() { return player2Hand; }
int Player::getComputerHand() { return computerHand; }
