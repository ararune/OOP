#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <random>
#include <chrono>
#include "point.h"


void Point::setX(const double x)
{
	this->x = x;
	
}
void Point::setY(const double y)
{
	this->y = y;

}
void Point::setZ(const double z)
{
	this->z = z;

}
void Point::setRandX(const double a, const double b) {
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::mt19937_64 generator(seed);		// random number engine class that generates pseudo-random numbers
	std::uniform_real_distribution<double> distribution(a, b);	// p(x|a, b) = 1/(b-a) , a <= x < b 
	//uniform real distribution for floating point
	x = distribution(generator);
	
}
void Point::setRandY(const double a, const double b) {
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::mt19937_64 generator(seed);
	
	std::uniform_real_distribution<double> distribution(a, b);
	y = distribution(generator);
}
void Point::setRandZ(const double a, const double b) {
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::mt19937_64 generator(seed);
	
	std::uniform_real_distribution<double> distribution(a, b);
	z = distribution(generator);
}
const double Point::getX()
{
	return x;
}

const double Point::getY()
{
	return y;
}
const double Point::getZ()
{
	return z;
}
void Point::printPosition()
{
	std::cout << x << " " << y << " " << z << std::endl;
}

const double Point::distance2D(Point b)
{
	return sqrt(pow((b.getX() - x), 2) + pow((b.getY() - y), 2));
}

const double Point::distance3D(Point b)
{
	return sqrt(pow((b.getX() - x), 2) + pow((b.getY() - y), 2) + pow((b.getZ() - z), 2));
}
