#pragma once
#include "model.h"

class View {

	friend class Model;
	friend class Controller;
public:
	void printLine();
	void printDisplay(std::string message);
	void drawHangman(int errors = 0);
	void printLetters(std::string guesses, char from, char to);
	void printRemainingLetters(std::string taken);
};