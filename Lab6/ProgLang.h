#pragma once
#include <iostream>

class ProgLang {

protected:

	char* name_;
	bool dynamicTypization_;
	int typizationStrength_;
	bool objectOriented_;
	int cameOut_;

	ProgLang();

public:

	ProgLang(const char*, bool, int, bool, int);

	virtual ~ProgLang() = 0;

	virtual void print() = 0;

	char* name();

	char* name(const char*);

	bool dynamicTypization();

	void dynamicTypization(bool);

	int typizationStrength();

	void typizationStrength(int);

	bool objectOriented();

	void objectOriented(bool);

	int cameOut();

	void cameOut(int);

};