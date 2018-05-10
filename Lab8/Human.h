#pragma once
#include <iostream>

class Human {

protected:

	char* _name;
	double _age;
	double _weight;

public:

	Human();

	Human(char*, double, double);

	Human(const Human&);

	virtual ~Human();

	virtual bool print(std::ostream&) const;

	/*virtual bool printBin(std::ostream&) const;*/

	void age(double);
};