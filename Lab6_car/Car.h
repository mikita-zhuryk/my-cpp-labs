#pragma once
#include <iostream>

using namespace std;

class Car {

protected:

	char* model_;
	int strL;
	int gears_;
	double fuelConsumption_;
	double tankVolume_;

	virtual ~Car();

public:

	virtual void print(ostream&) const = 0;

	virtual void input(istream&) = 0;

	double calcMaxDist();

};