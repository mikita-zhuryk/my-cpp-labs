#include "Container1.h"

Container1::Container1() {
	strcpy_s(_name, "\0");
	strcpy_s(_addr, "\0");
}

Container1::Container1(char* name, char* addr) {
	strcpy_s(_name, name);
	strcpy_s(_addr, addr);
}

Container1::~Container1() {}

std::ostream& operator<<(std::ostream& out, const Container1& obj) {
	if (!out) {
		throw std::invalid_argument("Bad output stream.");
	}
	if (!out.binary) {
		out << "Name: " << obj._name << "; Address: " << obj._addr;
	}
	else {
		char temp[100];
		strcpy_s(temp, "Name: ");
		strcat_s(temp, obj._name);
		strcat_s(temp, "; Address: ");
		strcat_s(temp, obj._addr);
		out.write(temp, strlen(temp));
	}
	return out;
}

std::istream& operator>>(std::istream& in, Container1& obj) {
	if (!in) {
		throw std::invalid_argument("Bad input stream");
	}
	in.peek();
	if (in.eof()) {
		throw std::invalid_argument("Input file is empty");
	}
	in.getline(obj._name, 49);
	in.getline(obj._addr, 49);
	return in;
}