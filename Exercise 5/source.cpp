#include <iostream>
#include "game.h"

int main()
{
	Point a, b;

	a.setX(10);
	a.setY(10);
	a.setZ(10);

	b.setRandX(10, 30);
	b.setRandY(10, 30);
	b.setRandZ(10, 30);

	a.printPosition();
	b.printPosition();

	std::cout << "2D distance : " << a.distance2D(b) << std::endl << "3D distance : " << a.distance3D(b) << std::endl;

	Weapon gun = generateWeapon();

	std::cout << "Gun position : "; 
	gun.position.printPosition();
	gun.reload();
	std::cout << gun.ammoCheck() << std::endl;

	int n = 10;
	Target* targets = generateTargets(n);

	std::cout << std::endl;

	for (int i = 0; i < n; i++)
	{
		std::cout << "a = " << targets[i].a.getZ() << std::endl;
		std::cout << "d = " << targets[i].d.getZ() << std::endl;
		std::cout << std::endl;
	}

	gun.shoot(targets, n);

	std::cout << "Targets shot : " << strike(targets, n) << std::endl;
}

