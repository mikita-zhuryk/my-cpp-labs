#pragma once
#include "Car.h"

using namespace std;

class Truck : public Car {

protected:

	double maxCargoLoad_;
	int numberOfWheels_;

public:

	Truck(const char*, int, double, double, double, int);
	
	Truck(const Truck&);

	virtual ~Truck();

	void print(ostream&) const;

	void input(istream&);

};