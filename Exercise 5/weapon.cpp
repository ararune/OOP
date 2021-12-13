#include <iostream>
#include "weapon.h"
#include "game.h"

void Weapon::reload()
{
	if (ammo < magSize)
		std::cout << "Ammo reloaded!" << std::endl;
	ammo = magSize;
}
const unsigned short Weapon::ammoCheck()
{
	std::cout << "Current ammo : " << ammo << std::endl;
	return ammo;
}
const unsigned short Weapon::getMag()
{
	return magSize;
}

void Weapon::shoot(Target* target, int n)
{

	for (int i = 0; i < n; i++)
	{
		if (ammo)
		{
			ammo--;
			if (shootTest(*this, target[i]))
				target[i].hit();
		}
	}

}

