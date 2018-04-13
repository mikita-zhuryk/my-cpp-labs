#pragma once
#include <iostream>
#include <exception>

using namespace std;

class List {

public:

	virtual ~List() {}

	virtual void print(ostream&) const = 0;

	virtual bool isEmpty() const = 0;

};