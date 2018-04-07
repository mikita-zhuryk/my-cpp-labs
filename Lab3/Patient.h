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

	void setSurname(const char*);

	void setForename(const char*);

	void setMiddleName(const char*);

	void setAddress(const char*);

	void setCardNo(int);

	void setDiagnosis(const char*);

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