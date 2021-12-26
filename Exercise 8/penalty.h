#pragma once
#ifndef PENALTY_H
#define PENALTY_H
#include "timer.h"
class Penalty {
	double penalize;

public:
	Penalty(int seconds) : penalize(seconds) {};
	double operator()(Timer& p) const 
	{ 
		if (p.s + penalize >= 60)
		{
			double remainder = 60 - p.s;
			p.m++;
			p.s = 0;
			return p.s += remainder;
		}
			return (p.s += penalize); 
	}
};
#endif 

