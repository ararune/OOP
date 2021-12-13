#pragma once
#include "point.h"

class Target {
	int shot = 0;

public:
	Point a;
	Point d;
	void hit();
	bool isHit();
};
