#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <time.h>
#include <fstream>
#include <cctype>
#include<cstring>

class Model {

	std::string movie;
	std::string guesses;
	std::vector <std::string> moviesList;
	int errors = 0;

	friend class View;
	friend class Controller;

public:
	void loadMovies();
	void pickMovie();
	void removeSpaces();
	void toUpper();

	//setters
	void setErrors(int n);
	void setGuesses(char input);

	//getters
	std::string getMovie();
	int getErrors();
	std::string getGuesses();
};