#pragma once
#include "model.h"
#include "view.h"

class Controller {
	friend class Model;
	friend class View;
	View cview;
	Model cmodel;
	bool win = false;
	char input;


public:
	bool checkGame(std::string movie, std::string guesses);
	int errorsMade(std::string movie, std::string guesses);
	bool getWin();
	char getInput();
	void setWin(bool checkGame);
	void setInput(char temp);



};

