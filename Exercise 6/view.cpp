#include "view.h"

void View::printLine() {
    std::cout << "+-----------------------------------------------------+" << std::endl;
}
void View::printDisplay(std::string message) {
    std::cout << "|";
    bool flag = true;                                   // flag is used to alternate printing | from left side to the right
    for (int i = message.length(); i < 53; i++)         // 53 arbitrarily selected to fit the top print - count
    {
       (flag) ? (message = " " + message) : (message = message + " ");
        flag = !flag;
    }
    std::cout << message.c_str();
    std::cout << "|" << std::endl;
}
void View::drawHangman(int errors)
{
    (errors >= 1) ? printDisplay("|") : printDisplay("");           // print rope
    (errors >= 2) ? printDisplay("|") : printDisplay("");           // rope
    (errors >= 3) ? printDisplay("O") : printDisplay("");           // head
    if (errors == 4) printDisplay("/  ");                           // arm
    if (errors == 5)  printDisplay("/| ");;                         // arm+body
    (errors >= 6) ? printDisplay("/|\\") : printDisplay("");        //arms + body
    (errors >= 7) ? printDisplay("|") : printDisplay("");           // more body
    if (errors == 8) printDisplay("/");                             // leg
    (errors >= 9) ? printDisplay("/ \\") : printDisplay("");        // another leg
}
void View::printLetters(std::string guesses, char from, char to) {
    std::string str;
    for (char i = from; i <= to; i++)
    {
        if (guesses.find(i) == std::string::npos)
        {
            str += i;
            str += " ";           // if the letter is still available
        }
        else
            str += "  ";          // if the letter has been taken by the user
    }
    printDisplay(str);
}
void View::printRemainingLetters(std::string taken)
{
    printDisplay("Letter selection");
    printLetters(taken, 'A', 'M');      // display all the non-taken letters from A-M, N-Z then 0-9
    printLetters(taken, 'N', 'Z');      
    printLetters(taken, '0', '9');
}