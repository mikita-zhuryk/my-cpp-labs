#include "Students.h"
#include <iostream>

int main()
{
	try {
		menu();
	}
	catch(int errorCode) {
		cout << "Error. ";
		if (errorCode == 1)
		{
			cout << "Couldn't open input file\n";
		}
		if (errorCode == 2)
		{
			cout << "Input file is empty\n";
		}
		if (errorCode == 3)
		{
			cout << "Couldn't open output file\n";
		}
		if (errorCode == 10)
		{
			cout << "Incorrect input\n";
		}
	}
	system("pause");
	return 0;
}