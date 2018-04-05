#include "Equation.h"
#include "LinearEq.h"
#include "QuadraticEq.h"
#include "LinearEq.cpp"
#include <iostream>

using namespace std;

int main() {
	LinearEq lEq1(0.0, 0.0);
	cout << "Enter coefficients";
	cin >> lEq1;
	lEq1.solve(cout);
	QuadraticEq qEq1(0.0, 0.0, 0.0);
	cout << "Enter coefficients";
	cin >> qEq1;
	qEq1.solve(cout);
	system("pause");
	return 0;
}