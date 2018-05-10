#include "Human.h"
#include <exception>

Human::Human() {
	_name = nullptr;
	_age = -1;
	_weight = -1;
}

Human::Human(char* name, double age, double weight) {
	_name = new char[strlen(name) + 1];
	_name[strlen(name)] = '\0';
	strcpy(_name, name);
	_age = age;
	_weight = weight;
}

Human::Human(const Human& obj) {
	_name = new char[strlen(obj._name) + 1];
	_name[strlen(obj._name)] = '\0';
	strcpy(_name, obj._name);
	_age = obj._age;
	_weight = obj._weight;
}

Human::~Human() {
	delete[] _name;
}

bool Human::print(std::ostream& out) const {
	if (!out) { return false; }
	out << "Name: " << _name << "; Age: " << _age << "; Weight: " << _weight;
	return true;
}

//bool Human::printBin(std::ostream& out) const {
//	if (!out.binary) {
//		throw std::invalid_argument("Stream is not in binary mode");
//		return false;
//	}
//	if (!out) {
//		return false;
//	}
//	std::string temp = "Name: " + (std::string)_name + "; Age: " + (std::string(_age)) + "; Weight: " + _weight;
//}

void Human::age(double age) {
	_age = age;
}
