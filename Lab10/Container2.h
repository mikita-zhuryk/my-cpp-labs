#pragma once
#include <iostream>

struct Container2 {

	char _name[50];
	char _date[11];

public:

	Container2();

	Container2(char*, char*);

	~Container2();

	friend std::ostream& operator<<(std::ostream&, const Container2&);

	friend std::istream& operator>>(std::istream&, Container2&);

};