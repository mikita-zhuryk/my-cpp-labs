#include "Container2.h"

Container2::Container2() {
	strcpy_s(_name, "\0");
	strcpy_s(_date, "\0");
}

Container2::Container2(char* name, char* date) {
	strcpy_s(_name, name);
	strcpy_s(_date, date);
}

Container2::~Container2() {}

std::ostream& operator<<(std::ostream& out, const Container2& obj) {
	if (!out) {
		throw std::invalid_argument("Bad output stream.");
	}
	if (!out.binary) {
		out << "Name: " << obj._name << "; Date: " << obj._date;
	}
	else {
		char temp[100];
		char buf[15];
		strcpy_s(temp, "Name: ");
		strcat_s(temp, obj._name);
		strcat_s(temp, "; Date: ");
		strcat_s(temp, obj._date);
		out.write(temp, strlen(temp));
	}
	return out;
}
std::istream& operator>>(std::istream& in, Container2& obj) {
	if (!in) {
		throw std::invalid_argument("Bad input stream");
	}
	in.peek();
	if (in.eof()) {
		throw std::invalid_argument("Input file is empty");
	}
	in.getline(obj._name, 49);
	in.getline(obj._date, 10);
	return in;
}