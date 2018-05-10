#pragma once
#include "Car.h"

class Sportcar : public Car {

	double maxSpeed_;

public:

	Sportcar(const char*, int, double, double, double);

	Sportcar(const Sportcar&);

	~Sportcar();

	void print(ostream&) const;

	void input(istream&);

};