#pragma once
#ifndef TIMER_H
#define TIMER_H
#include <iostream>
#include <stdlib.h>
#include <vector>
using std::ostream;
using std::endl;
class Timer
{
	int h;
	int m;
	double s;

public:
	Timer(int h, int m, double s) : h(h), m(m), s(s) {}
	Timer() { this->h = 0; this->m = 0; this->s = 0.0; };

	// operators
	Timer& operator+=(const Timer& other) { h += other.h, m += other.m, s += other.s; return *this; }
	Timer& operator-=(const Timer& other) { h -= other.h, m -= other.m, s -= other.s; return *this; }
	Timer& operator/=(const Timer& other) { h /= other.h, m /= other.m, s /= other.s; return *this; }
	Timer& operator*=(const Timer& other) { h *= other.h, m *= other.m, s *= other.s; return *this; }
	Timer& operator/=(size_t sz) { h /= sz, m /= sz, s /= sz; return *this; }
	bool operator<(Timer& tm) { return((toSeconds() - tm.toSeconds() ) < 0); };
	double operator-(Timer& tm) { return(toSeconds() - tm.toSeconds()); }
	double operator+(Timer& tm) { return(toSeconds() + tm.toSeconds()); }

	friend std::ostream& operator<< (std::ostream& os, const Timer& avg);
	friend class Penalty;

	// getters
	const double getSeconds() { return s; }
	const int getMinutes() { return m; }
	const int getHours() { return h; }

	// setters
	void setSeconds(const double s = 0) { this->s = s; }
	void setMinutes(const double m = 0) { this->m = m; }
	void setHours(const double h = 0) { this->h = h; }

	// member functions
	double toSeconds() { return ((h * 3600) + (m * 60) + s); }

};
ostream& operator<< (ostream& os, const Timer& avg) {
	os << "\nhrs : " << avg.h << "\nmin : " << avg.m << "\nsec : " << avg.s << endl;
	return os;
}
#endif
