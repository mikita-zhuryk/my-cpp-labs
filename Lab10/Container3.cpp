#include "Container3.h"
#include <stdlib.h>

Container3::Container3() {
	strcpy_s(_name, "\0");
	strcpy_s(_addr, "\0");
	_price = 0;
}

Container3::Container3(char* name, char* addr, double price) {
	strcpy_s(_name, name);
	strcpy_s(_addr, addr);
	_price = price;
}

Container3::~Container3() {}

std::ostream& operator<<(std::ostream& out, const Container3& obj) {
	if (!out) {
		throw std::invalid_argument("Bad output stream.");
	}
	if (!out.binary) {
		out << "Name: " << obj._name << "; Address: " << obj._addr << "; Price to pay: " << obj._price;
	}
	else {
		char temp[100];
		strcpy_s(temp, "Name: ");
		strcat_s(temp, obj._name);
		strcat_s(temp, "; Address: ");
		strcat_s(temp, obj._addr);
		strcat_s(temp, "; Price to pay: ");
		char convStr[8] = "\0";
		if (_gcvt_s(convStr, obj._price, 6)) {
			throw "Error converting double to char*";
		}
		strcat_s(temp, convStr);
		out.write(temp, strlen(temp));
	}
	return out;
}

std::istream & operator>>(std::istream& in, Container3& obj) {
	if (!in) {
		throw std::invalid_argument("Bad input stream");
	}
	in.peek();
	if (in.eof()) {
		throw std::invalid_argument("Input file is empty");
	}
	in.getline(obj._name, 49);
	in.getline(obj._addr, 49);
	in >> obj._price;
	return in;
}
