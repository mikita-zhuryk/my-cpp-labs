#include "Adult.h"

Adult::Adult() : Human(), _passNum{ 0 } {}

Adult::Adult(Human human, int passNum) : Human(human), _passNum(passNum) {}

Adult::Adult(char* name, double age, double weight, int passNum) : Human(name, age, weight), _passNum(passNum) {}

Adult::~Adult() {}

bool Adult::print(std::ostream& out) const {
	((Human)*this).print(out);
	out << "; Passport number: " << _passNum;
	return true;
}

void Adult::passNum(int passNum) {
	_passNum = passNum;
}
