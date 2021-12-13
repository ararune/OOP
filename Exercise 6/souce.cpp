#include <iostream>
#include "model.h"
#include "view.h"
#include "controller.h"
using namespace std;


int main()
{
    View v;
    Model m; 
    Controller c;

    m.loadMovies();
    m.pickMovie();
    m.removeSpaces();
    m.toUpper();
    
    do {
        system("cls");
        v.printLine();
        v.printDisplay("HANGMAN");
        v.printLine();
        v.drawHangman(m.getErrors());
        v.printLine();
        v.printRemainingLetters(m.getGuesses());
        v.printLine();
        v.printDisplay("Guess the word");
        v.printLine();
        
        c.setWin(c.checkGame(m.getMovie(), m.getGuesses()));
        if (c.getWin() || m.getErrors() == 9)
            break;
        v.printLine();

        char temp, input;
        cout << "Enter a character : "; cin >> temp;
        input = toupper(temp);

        if (m.getGuesses().find(input) == string::npos)
            m.setGuesses(input);

        m.setErrors(c.errorsMade(m.getMovie(), m.getGuesses()));

    } while (1);
    v.printLine();
    (c.getWin()) ? v.printDisplay("YOU WON!") : v.printDisplay("GAME OVER");
    v.printLine();

    system("pause"); 
    getchar();

}

