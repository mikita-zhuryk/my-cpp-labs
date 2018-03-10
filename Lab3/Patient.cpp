#include "Patient.h"
#include <iostream>

using namespace std;

Patient::Patient()
{
	surname[0] = '\0';
	forename[0] = '\0';
	middleName[0] = '\0';
	address[0] = '\0';
	medCardNo = 0;
	diagnosis[0] = '\0';
}

Patient::Patient(char* surname, char* forename, char* middleName, char* address, int medCardNo, char* diagnosis)
{
	if (!(_strcmpi(surname, "\0") && _strcmpi(forename, "\0") && _strcmpi(middleName, "\0") && _strcmpi(address, "\0") && _strcmpi(diagnosis, "\0"))) { throw 6; }
	strcpy_s(this->surname, surname);
	strcpy_s(this->forename, forename);
	strcpy_s(this->middleName, middleName);
	strcpy_s(this->address, address);
	this->medCardNo = medCardNo;
	strcpy_s(this->diagnosis, diagnosis);
}

Patient::Patient(const Patient& origin)
{
	strcpy_s(surname, origin.surname);
	strcpy_s(forename, origin.forename);
	strcpy_s(middleName, origin.middleName);
	strcpy_s(address, origin.address);
	medCardNo = origin.medCardNo;
	strcpy_s(diagnosis, origin.diagnosis);
}

Patient::~Patient()
{
}

void Patient::setSurname(const char* surname)
{
	strcpy_s(this->surname, surname);
}

void Patient::setForename(const char* forename)
{
	strcpy_s(this->forename, forename);
}

void Patient::setMiddleName(const char* middleName)
{
	strcpy_s(this->middleName, middleName);
}

void Patient::setAddress(const char* address)
{
	strcpy_s(this->address, address);
}

void Patient::setCardNo(int medCardNo)
{
	this->medCardNo = medCardNo;
}

void Patient::setDiagnosis(const char* diagnosis)
{
	strcpy_s(this->diagnosis, diagnosis);
}

char* Patient::getSurname()
{
	char* temp = new char[20];
	if (!temp) { throw 1; }
	strcpy_s(temp, 20, surname);
	return temp;
}

char* Patient::getForename()
{
	char* temp = new char[20];
	if (!temp) { throw 1; }
	strcpy_s(temp, 20, forename);
	return temp;
}

char* Patient::getMiddleName()
{
	char* temp = new char[20];
	if (!temp) { throw 1; }
	strcpy_s(temp, 20, middleName);
	return temp;
}

char* Patient::getAddress()
{
	char* temp = new char[50];
	if (!temp) { throw 1; }
	strcpy_s(temp, 50, address);
	return temp;
}

int Patient::getCardNo()
{
	return medCardNo;
}

char* Patient::getDiagnosis()
{
	//char* temp = new char[30];
	//if (!temp) { throw 1; }
	//strcpy_s(temp, 30, diagnosis);
	return diagnosis;
}

Patient& Patient::operator=(const Patient& origin)
{
	strcpy_s(surname, origin.surname);
	strcpy_s(forename, origin.forename);
	strcpy_s(middleName, origin.middleName);
	strcpy_s(address, origin.address);
	medCardNo = origin.medCardNo;
	strcpy_s(diagnosis, origin.diagnosis);
	return *this;
}

istream& operator>>(istream& inStream, Patient& patient)
{
	if (!inStream) { throw 2; }
	if (inStream.eof()) { throw 3; }
	inStream.getline(patient.surname, 20);
	inStream.getline(patient.forename, 20);
	inStream.getline(patient.middleName, 20);
	inStream.getline(patient.address, 50);
	char temp[10] = "\0";
	inStream.getline(temp, 10);
	patient.medCardNo = atoi(temp);
	inStream.getline(patient.diagnosis, 30);
	return inStream;
}

ostream& operator<<(ostream& outStream, const Patient& patient)
{
	if (!outStream) { throw 4; }
	outStream << "Surname: " << patient.surname << endl;
	outStream << "Forename: " << patient.forename << endl;
	outStream << "Middle name: " << patient.middleName << endl;
	outStream << "Address: " << patient.address << endl;
	outStream << "Medical card number: " << patient.medCardNo << endl;
	outStream << "Diagnosis: " << patient.diagnosis;
	return outStream;
}
