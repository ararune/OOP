#include <iostream>
#include "target.h"

bool Target::isHit()
{
	return shot;
}
void Target::hit()
{
	shot = 1;
}