#pragma once
#include "Human.h"

class Adult : public Human {

	int _passNum;

public:

	Adult();

	Adult(Human, int);

	Adult(char*, double, double, int);

	~Adult();

	bool print(std::ostream&) const;

	/*bool printBin(std::ostream&) const;*/

	void passNum(int);

};