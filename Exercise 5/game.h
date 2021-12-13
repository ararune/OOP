#pragma once
#include "point.h"
#include "weapon.h"
#include "target.h"

Weapon generateWeapon();
Target* generateTargets(int n);
bool shootTest(Weapon& gun, Target targ);
int strike(Target* target, int n);