#include <iostream>
#include "Animal.h"
using namespace std;

int Animal::getLegs(){ return 0; }
int Tarantula::getLegs(){ return legs;}
int Sparrow::getLegs(){ return legs; }
int Cockroach::getLegs(){ return legs; }
char* Tarantula::getSpecies(){ return species; }
char* Sparrow::getSpecies() { return species; }
char* Cockroach::getSpecies(){ return species; }
