#pragma once
#include <iostream>

using namespace std;

class Equation {

public:

	virtual void solve(ostream& out) const = 0;

	virtual ~Equation() {}
};