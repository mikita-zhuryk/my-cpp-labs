#pragma once
#include <iostream>

struct Container3 {

	char _name[50];
	char _addr[50];
	double _price;

public:

	Container3();

	Container3(char*, char*, double);

	~Container3();

	friend std::ostream& operator<<(std::ostream&, const Container3&);

	friend std::istream& operator>>(std::istream&, Container3&);

};