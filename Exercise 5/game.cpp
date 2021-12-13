#include <iostream>
#include "game.h"

Weapon generateWeapon()
{
	Weapon gun;

	gun.position.setRandX(1, 10);
	gun.position.setRandY(1, 10);
	gun.position.setRandZ(1, 10);
	
	return gun;
}

Target* generateTargets(int n)
{
	Target* targets = new Target[n];

	for (int i = 0; i < n; i++)
	{
		targets[i].a.setRandX(1, 10);
		targets[i].a.setRandY(1, 10);
		targets[i].a.setRandZ(1, 10);
		targets[i].d.setRandX(1, 10);
		targets[i].d.setRandY(1, 10);
		targets[i].d.setRandZ(1, 10);
	}

	return targets;
}
bool shootTest(Weapon& gun, Target targ)
{
	double a, b;

	if (targ.a.getZ() > targ.d.getZ())
	{
		a = targ.d.getZ();
		b = targ.a.getZ();
	}
	else
	{
		b = targ.d.getZ();
		a = targ.a.getZ();
	}

	return (gun.position.getZ() >= a && gun.position.getZ() <= b) ? 1 : 0;

}
int strike(Target* target, int n)
{
	int k = 0;

	for (int i = 0; i < n; i++)
		if (target[i].isHit())
			k++;

	return k;
}
