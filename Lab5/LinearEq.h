#pragma once
#include "Equation.h"

class LinearEq : public Equation {
protected:

	double c1;
	double c2;

public:

	LinearEq(double c2, double c1) : c1{ c1 }, c2{ c2 } {}

	virtual ~LinearEq();

	virtual void solve(ostream&) const;

	friend istream& operator>>(istream&, LinearEq&);

	friend ostream& operator<<(ostream&, const LinearEq&);

};