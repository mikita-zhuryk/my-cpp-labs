#pragma once
#include "Truck.h"

class Pickup :public Truck {

	double trunkL_;
	double trunkW_;
	double trunkH_;

public:

	Pickup(const Truck&, double, double, double);

	Pickup(const char*, int, double, double, double, int, double, double, double);
	
	Pickup(const Pickup&);

	~Pickup() {}

	void print(ostream&) const;

	void input(istream&);

	double trunkVolume() const;
};