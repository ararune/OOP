#include "Counter.h"
#include <iostream>

Counter::Counter()
{
	phySize = 10;
	logSize = 0;
	ct = 0;
	arr = new Animal * [phySize];
}

void Counter::add(Animal* A)
{
	if (phySize <= logSize)
	{
		phySize *= 2;
		Animal** temp = new Animal * [phySize];
		for (int i = 0; i < logSize; i++)
		{
			temp[i] = arr[i];
		}

		delete[] arr;
		arr = temp;
	}

	arr[logSize] = A;

	std::cout << A->getLegs() << std::endl;
	puts(A->getSpecies());
	ct = ct + A->getLegs();

	logSize++;
}

int Counter::sum(){ return ct; }