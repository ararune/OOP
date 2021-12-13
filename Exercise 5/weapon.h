#pragma once
#include "point.h"
#include "target.h"

class Weapon {

	const unsigned short  magSize = 45;
	unsigned short ammo = 45;

public:
	Point position;
	void reload();
	const unsigned short  ammoCheck();
	const unsigned short getMag();
	void shoot(Target* target, int n);

};
