#pragma once
#include "Equation.h"
#include "LinearEq.h"

class QuadraticEq : public LinearEq {

	double c3;

public:

	QuadraticEq(double c3, double c2, double c1): c3 { c3 }, LinearEq(c2, c1) {}

	~QuadraticEq();

	void solve(ostream&) const;

	friend istream& operator>>(istream&, QuadraticEq&);

	friend ostream& operator<<(ostream&, const QuadraticEq&);

};