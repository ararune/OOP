#include "MatchesGame.h"
#include <iostream>
#include<cstdlib>
#include <vector>

// A matches game versus a computer, 21 matches, players alternate turns removing 1, 2 or 3 matches
// the player that's forced to remove the last match loses, computer's move is randomly generated 
// computer makes the first move to player's advantage

int main()
{
    MatchesGame matches;
    matches.populateVector(matches);
    matches.alternateTurns(matches);


}