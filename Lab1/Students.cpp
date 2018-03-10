#include "Students.h"
#include <iostream>
#include <fstream>

using namespace std;

struct Student
{
	char name[10];
	int num;
	double grade;
};

int findNumStud(ifstream& fin)
{
	int num = 0;
	char buf[51];
	while (fin.getline(buf, 50)) num++;
	fin.clear(fin.rdstate() & !fin.eofbit);
	fin.seekg(0, ios::beg);
	return num;
}

int cmpStringAlphabetically(const void* s1, const void* s2)
{
	return _strcmpi((char*)s1, (char*)s2);
}

int cmpFuncAlphabetically(const void* e1, const void* e2)
{
	return cmpStringAlphabetically(((Student*)e1)->name, ((Student*)e2)->name);
}

int cmpSearchFunc(const void* key, const void* elem)
{
	return cmpStringAlphabetically((char*)key, ((Student*)elem)->name);
}

int cmpFuncGroups(const void* e1, const void* e2)
{
	if (((Student*)e1)->num == ((Student*)e2)->num) { return _strcmpi(((Student*)e1)->name, ((Student*)e2)->name); }
	return ((Student*)e1)->num - ((Student*)e2)->num;;
}

void inline printStudent(ostream& out, Student stud)
{
	out << "Surname: " << stud.name << "\nGroup number: " << stud.num << "\nGrade: " << stud.grade;
}

void printArray(ostream& out, Student* studArray, unsigned short n)
{
	for (int i = 0; i < n; i++)
	{
		printStudent(out, studArray[i]);
		out << endl << endl;
	}
}

void readArray(Student* studArray, unsigned short n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Enter " << i + 1 << " student's surname\n";
		cin >> studArray[i].name;
		cout << "Enter " << i + 1 << " student's group number\n";
		cin >> studArray[i].num;
		cout << "Enter " << i + 1 << " student's grade\n";
		cin >> studArray[i].grade;
	}
}

void readArray(ifstream &in, Student* studArray, unsigned short n)
{
	for (int i = 0; i < n; i++)
	{
		in >> studArray[i].name >> studArray[i].num >> studArray[i].grade;
	}
}

void input(Student*& studArray, unsigned short& n)
{
	unsigned short choice = 0;
	cout << "Choose input: 1. File; 2. Console\n";
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		ifstream fin("Input.txt");
		if (!fin) throw 1;
		if (fin.eof()) throw 2;
		n = findNumStud(fin);
		studArray = new Student[n];
		readArray(fin, studArray, n);
		break;
	}
	case 2:
	{
		cout << "Enter number of students\n";
		cin >> n;
		studArray = new Student[n];
		readArray(studArray, n);
		break;
	}
	default:
	{
		throw 10;
	}
	}
}

void sortNames(Student* studArray, unsigned short n)
{
	qsort(studArray, n, sizeof(Student), cmpFuncAlphabetically);
	printArray(cout, studArray, n);
	ofstream foutAlpha("OutputAlpha.txt");
	if (!foutAlpha) throw 3;
	printArray(foutAlpha, studArray, n);
}

void findStudent(Student* studArray, unsigned short n)
{
	qsort(studArray, n, sizeof(Student), cmpFuncAlphabetically);
	cout << "Enter student's surname\n";
	char surname[10];
	cin >> surname;
	Student* res = (Student*)bsearch(surname, studArray, n, sizeof(Student), cmpSearchFunc);
	if (res)
	{
		printStudent(cout, *res);
	}
	else
	{
		cout << "No match found\n";
	}
}

void sortGroupsNames(Student* studArray, unsigned short n)
{
	qsort(studArray, n, sizeof(Student), cmpFuncGroups);
	printArray(cout, studArray, n);
	ofstream foutGroupsAlpha("OutputGroupsAlpha.txt");
	if (!foutGroupsAlpha) throw 3;
	printArray(foutGroupsAlpha, studArray, n);
}

void calcGroupAvg(Student* studArray, unsigned short n)
{
	qsort(studArray, n, sizeof(Student), cmpFuncGroups);
	double avg = 0.0;
	unsigned short count = 0;
	for (int i = 0; i < n; i++)
	{
		count++;
		avg += studArray[i].grade;
		if (studArray[i].num != studArray[i + 1].num)
		{
			cout << "Group: " << studArray[i].num << "\nAverage grade: " << avg / count << endl;
			avg = 0;
			count = 0;
		}
	}
}

void menu()
{
	unsigned short choice = 0;
	unsigned short n = 0;
	Student* studArray = nullptr;
	input(studArray, n);
	cout << "Choose an option: \n1. Sort by surnames alphabetically;\n2. Find a student in the array;\n";
	cout << "3. Sort by groups and then by surnames;\n4. Find average grade for every group.\n";
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		sortNames(studArray, n);
		break;
	}
	case 2:
	{
		findStudent(studArray, n);
		break;
	}
	case 3:
	{
		sortGroupsNames(studArray, n);
		break;
	}
	case 4:
	{
		calcGroupAvg(studArray, n);
		break;
	}
	default:
	{
		throw 10;
	}
	}
}