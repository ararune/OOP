#include <iostream>
#include "Animal.h"
#include "Counter.h"
using namespace std;

int main()
{
	Tarantula t;
	Sparrow s;
	Cockroach c;
	Counter ct;

	ct.add(&t);
	ct.add(&s);
	ct.add(&c);

	cout << ct.sum() << endl;
}