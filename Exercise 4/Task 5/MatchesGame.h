#ifndef MATCHESGAME_H
#define MATCHESGAME_H
#include <vector>


class MatchesGame {

    std::vector<int> m;
    int ci, ui;

    int random(int min, int max);
    void computerTurn(MatchesGame& matches, MatchesGame& computerInput);
    void playerTurn(MatchesGame& matches, MatchesGame& userInput);
public:
    void populateVector(MatchesGame& matches);
    void alternateTurns(MatchesGame& matches);
};


#endif


