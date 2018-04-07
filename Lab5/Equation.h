#pragma once
#include <iostream>

using namespace std;

struct bad_stream {};

struct bad_input {};

class Equation {

public:

	virtual void solve(ostream& out) const = 0;

	virtual ~Equation() {}
};