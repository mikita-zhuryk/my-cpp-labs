#pragma once
#include <fstream>

using namespace std;

struct Student;

int findNumStud(ifstream& fin);

int cmpStringAlphabetically(const void* s1, const void* s2);

int cmpFuncAlphabetically(const void* e1, const void* e2);

int cmpSearchFunc(const void* key, const void* elem);

int cmpFuncGroups(const void* e1, const void* e2);

void inline printStudent(ostream& out, Student stud);

void printArray(ostream& out, Student* studArray, unsigned short n);

void readArray(Student* studArray, unsigned short n);

void readArray(ifstream& in, Student* studArray, unsigned short n);

void sortGroupsAlpha(Student* studArray, unsigned short n);

void input(Student*& studArray, unsigned short& n);

void sortNames(Student* studArray, unsigned short n);

void findStudent(Student* studArray, unsigned short n);

void sortGroupsNames(Student* studArray, unsigned short n);

void calcGroupAvg(Student* studArray, unsigned short n);

void menu();