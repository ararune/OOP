#pragma once

class Point
{

	double x;
	double y;
	double z;

public:
	// setters
	void setX(const double x = 0);
	void setY(const double x = 0);
	void setZ(const double x = 0);
	void setRandX(const double a = 0, const double b = 0);
	void setRandY(const double a = 0, const double b = 0);
	void setRandZ(const double a = 0, const double b = 0);

	// getters
	const double getX();
	const double getY();
	const double getZ();


	void printPosition();
	const double distance2D(Point b);
	const double distance3D(Point b);

};
