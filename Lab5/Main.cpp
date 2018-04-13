#include "Equation.h"
#include "LinearEq.h"
#include "QuadraticEq.h"
#include <iostream>

using namespace std;

int main() {
	try {
		LinearEq lEq1(0.0, 0.0);
		cout << "Enter coefficients in ax + b = 0, left to right\n";
		cin >> lEq1;
		QuadraticEq qEq1(0.0, 0.0, 0.0);
		cout << "Enter coefficients in ax^2 + bx + c = 0, left to right\n";
		cin >> qEq1;
		Equation* eqArr[2] = { &lEq1, &qEq1 };
		for (int i = 0; i < 2; i++) {
			eqArr[i]->solve(cout);
		}
	}
	catch (bad_stream bs) {
		cout << "Stream is corrupt.\n";
	}
	catch (bad_input bi) {
		cout << "Input was incorrect.\n";
	}
	system("pause");
	return 0;
}