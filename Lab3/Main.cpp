#include "Patient.h"
#include <iostream>
#include <fstream>

using namespace std;

size_t detectLength(ifstream& fin)
{
	size_t n = 0;
	char buf[255];
	if (!fin) { throw 2; }
	if (fin.eof()) { throw 3; }
	while (fin.getline(buf, 255))
	{
		n++;
	}
	fin.clear(fin.rdstate() & !fin.eofbit);
	fin.seekg(0, ios::beg);
	return n / 6;
}

Patient* input(size_t& n)
{
	int choice = 0;
	Patient* patArray = nullptr;
	cout << "Choose input option: 1. File; 2. Console.\n";
	cin >> choice;
	switch (choice)
	{
	case 1:
		{
			ifstream fin("Patients.txt");
			if (!fin) { throw 2; }
			if (fin.eof()) { throw 3; }
			n = detectLength(fin);
			patArray = new Patient[n];
			if (!patArray) { throw 1; }
			for (size_t i = 0; i < n; i++)
			{
				fin >> patArray[i];
			}
			break;
		}
	case 2:
		{
			cout << "Enter number of patients.\n";
			cin >> n;
			patArray = new Patient[n];
			if (!patArray) { throw 1; }
			for (size_t i = 0; i < n; i++)
			{
				cout << "Enter patients' data. Each parameter must be entered on a different string.\n";
				cin >> patArray[i];
			}
			break;
		}
	default:
		{
			throw 5;
		}
	}
	return patArray;
}

size_t* findByDiagnosis(Patient* patArray, size_t n, char* diagnosis)
{
	if (!diagnosis) { throw 5; }
	size_t* indexArr = new size_t[n];
	for (size_t i = 0; i < n; i++)
	{
		indexArr[i] = 0;
	}
	Patient* foundArr = nullptr;
	char* curDiag = nullptr;
	for (size_t i = 0; i < n; i++)
	{
		curDiag = patArray[i].getDiagnosis();
		if (!strcmp(curDiag, diagnosis))
		{
			indexArr[i] = 1;
		}
		//delete[] curDiag;
	}
	return indexArr;
}

size_t* findByNo(Patient* patArray, size_t n, int smallerNo, int biggerNo)
{
	if (smallerNo > biggerNo) { throw 5; }
	size_t* indexArr = new size_t[n];
	for (size_t i = 0; i < n; i++)
	{
		indexArr[i] = 0;
	}
	Patient* foundArr = nullptr;
	int curNo = 0;
	for (size_t i = 0; i < n; i++)
	{
		curNo = patArray[i].getCardNo();
		if ((smallerNo <= curNo) && (curNo <= biggerNo))
		{
			indexArr[i] = 1;
		}
	}
	return indexArr;
}

int main()
{
	size_t n = 0;
	Patient* patArray = nullptr;
	size_t* foundDiag = nullptr;
	size_t* foundNumber = nullptr;
	try
	{
		patArray = input(n);
		char diagnosis[30];
		cout << "Enter diagnosis.\n";
		cin.ignore(1);
		cin.getline(diagnosis, 30);
		foundDiag = findByDiagnosis(patArray, n, diagnosis);
		for (size_t i = 0; i < n; i++)
		{
			if (foundDiag[i])
			{
				cout << patArray[i] << endl;
				cout << endl;
			}
		}
		cout << "Enter lower and then higher border.\n";
		int lower = 0;
		int higher = 0;
		cin >> lower >> higher;
		foundNumber = findByNo(patArray, n, lower, higher);
		for (size_t i = 0; i < n; i++)
		{
			if (foundNumber[i])
			{
				cout << patArray[i] << endl;
				cout << endl;
			}
		}
		delete[] patArray;
		delete[] foundDiag;
		delete[] foundNumber;
	}
	catch (int errCode)
	{
		delete[] patArray;
		delete[] foundDiag;
		delete[] foundNumber;
		switch(errCode)
		{
		case 1:
			{
				cout << "Allocation error.\n";
				break;
			}
		case 2:
			{
				cout << "Couldn't open input file.\n";
				break;
			}
		case 3:
			{
				cout << "Input file is empty.\n";
				break;
			}
		case 4:
			{
				cout << "Couldn't open output file.\n";
				break;
			}
		case 5:
			{
				cout << "Incorrect input.\n";
				break;
			}
		default:
			{
				cout << "Unhandled exception.\n";
			}
		}
	}
	std::system("pause");
	return 0;
}