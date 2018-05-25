#pragma once
#include <iostream>

struct Container1 {

	char _name[50];
	char _addr[50];

public:

	Container1();

	Container1(char*, char*);

	~Container1();

	friend std::ostream& operator<<(std::ostream&, const Container1&);

	friend std::istream& operator>>(std::istream&, Container1&);

};