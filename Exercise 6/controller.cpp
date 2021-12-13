#include "controller.h"

bool Controller::checkGame(std::string movie, std::string guesses)
{
    bool won = true;
    std::string str;
    for (int i = 0; i < movie.length(); i++)
    {
        if (guesses.find(movie[i]) == std::string::npos)
        {
            won = false;
            str += "_ ";
        }
        else
        {
            str += movie[i];
            str += " ";
        }
    }
    cview.printDisplay(str);
    return won;
}
int Controller::errorsMade(std::string movie, std::string guesses) {
    cmodel.errors = 0;
    for (int i = 0; i < guesses.length(); i++)
    {
        if (movie.find(guesses[i]) == std::string::npos)
            cmodel.errors++;
    }
    return cmodel.errors;
}
bool Controller::getWin() {
    return win;
}
void Controller::setWin(bool checkGame) {
    win = checkGame;
}
void Controller::setInput(char temp) {
    input = temp;
}
