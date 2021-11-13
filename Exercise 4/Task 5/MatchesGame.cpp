#include "MatchesGame.h"
#include <iostream>
#include<cstdlib>
#include <vector>


void MatchesGame::populateVector(MatchesGame& matches)
{
    for (int i = 0; i < 21; i++)
        matches.m.push_back(1);
}
int MatchesGame::random(int min, int max)
{
    srand(time(NULL));
    return min + rand() % ((max + 1) - min);
}

void MatchesGame::computerTurn(MatchesGame& matches, MatchesGame& computerInput)
{
    std::cout << "\nTotal matches : " << matches.m.size() << std::endl;
    if (matches.m.size() == 1) {      // if there's 1 match remaining and it's computer turn, you won
        std::cout << "\nYou won!";
        exit(0);
    }
    else if (matches.m.size() >= 2 && matches.m.size() <= 4 )    // if computer is in position to win, force it to win
    {
        std::cout << "\nYou lose :(";
        exit(0);
    }
    computerInput.ci = random(1, 3);

    matches.m.erase(matches.m.begin() + (matches.m.size() - computerInput.ci), matches.m.end());
    std::cout << "\nComputer removed " << computerInput.ci << " matches" << std::endl;
    std::cout << "\nTotal matches : " << matches.m.size() << std::endl << "\nPlease remove 1-3 matches " << std::endl;
}
void MatchesGame::playerTurn(MatchesGame& matches, MatchesGame& userInput)
{
    std::cin >> userInput.ui;
    if (userInput.ui > 3 || userInput.ui < 1 || userInput.ui > matches.m.size())
    {
        std::cout << "\nInvalid entry";       // to prevent drawing more or less than allowed
        exit(1);                                                    // or more than remaining
    }
    if (matches.m.size() <= 3 && userInput.ui == matches.m.size())
    {
        std::cout << "\nYou lose";                                    // if the player draws all the remaining matches
        exit(0);                                                    // they lose
    }
    matches.m.erase(matches.m.begin() + (matches.m.size() - userInput.ui), matches.m.end());
    std::cout << "\nYou removed " << userInput.ui << " matches" << std::endl;
}
void MatchesGame::alternateTurns(MatchesGame& matches)
{
    MatchesGame computerInput, userInput;
    while (matches.m.size() >= 1)
    {
        computerTurn(matches, computerInput);
        playerTurn(matches, userInput);
    }
    
}
