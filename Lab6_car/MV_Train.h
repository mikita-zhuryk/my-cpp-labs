#pragma once
#include "Truck.h"

class MV_Train :public Truck {

	bool hasRefridgerator_;

public:

	MV_Train(const Truck&, bool);

	MV_Train(const char*, int, double, double, double, int, bool);

	~MV_Train() {}

	void print(ostream&) const;

	void input(istream&);
};