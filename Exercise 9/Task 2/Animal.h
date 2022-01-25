#pragma once

class Animal
{
public:
	virtual int getLegs() = 0;
	virtual char* getSpecies() = 0;
};

class Spider : public Animal
{
protected:
	char species[20] = "Spider";
};
class Bird : public Animal
{
protected:
	char species[20] = "Ptica";
};
class Insect : public Animal
{
protected:
	char species[20] = "Insect";
};
class Tarantula : public Spider
{
private:
	int legs = 8;

public:
	int getLegs();
	char* getSpecies();
};
class Sparrow : public Bird
{
private:
	int legs = 2;

public:
	int getLegs();
	char* getSpecies();
};
class Cockroach : public Insect
{
private:
	int legs = 6;

public:
	int getLegs();
	char* getSpecies();
};

