#pragma once
#include <iostream>
#include "Abstract.h"

class Human: public Abstract {

protected:

	char* _name;
	double _age;
	double _weight;
	const int ID;

public:

	Human();

	Human(char*, double, double);

	Human(const Human&);

	virtual ~Human();

	bool print(std::ostream&) const;

	/*virtual bool printBin(std::ostream&) const;*/

	void age(double);
};