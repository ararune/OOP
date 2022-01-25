#pragma once
#include "Animal.h"


class Counter
{
private:
	Animal** arr;
	int logSize;
	int phySize;
	int ct;

public:
	Counter();
	void add(Animal* A);
	int sum();
};
