#pragma once
#include <iostream>

using namespace std;

class Patient
{

	char surname[20];
	char forename[20];
	char middleName[20];
	char address[50];
	int medCardNo;
	char diagnosis[30];

public:

	Patient();

	Patient(char*, char*, char*, char*, int, char*);

	Patient(const Patient&);

	~Patient();

	void setSurname(const char* = "\0");

	void setForename(const char* = "\0");

	void setMiddleName(const char* = "\0");

	void setAddress(const char* = "\0");

	void setCardNo(int = 0);

	void setDiagnosis(const char* = "\0");

	char* getSurname();

	char* getForename();

	char* getMiddleName();

	char* getAddress();

	int getCardNo();

	char* getDiagnosis();

	Patient& operator=(const Patient&);

	friend istream& operator>>(istream&, Patient&);

	friend ostream& operator<<(ostream&, const Patient&);

};