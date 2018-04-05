#include "QuadraticEq.h"

QuadraticEq::~QuadraticEq() {
}

void QuadraticEq::solve(ostream& out) const {
	double discr = 0;
	double x1 = 0;
	double x2 = 0;
	if (!c3) {
		((LinearEq)*this).solve(out);
	}
	else {
		discr = pow(c2, 2) - 4 * c3 * c1;
		x1 = (-c2 + sqrt(discr)) / (2 * c3);
		x2 = (-c2 - sqrt(discr)) / (2 * c3);
		out << "Solution: x1 = " << x1 << "; x2 = " << x2 << ".\n";
	}
}

istream& operator>>(istream& in, QuadraticEq& obj) {
	char* temp = new char[15];
	in.getline(temp, 14);
	int j;
	bool c2Read = false;
	int length = strlen(temp);
	int rightSide = 0;
	obj.c1 = obj.c2 = 0;
	for (int i = 0; i < length; i++) {
		if (temp[i] == 'x') {
			j = i;
			if (temp[i + 1] == '^') {
				while ((temp[j] != '-') && (temp[j] != '+')) {
					if (temp[j] != ' ') {
						obj.c3 += (temp[j] - '0') * pow(10, i - j);
					}
					j--;
				}
				if (temp[j] == '-') {
					obj.c3 = -obj.c3;
				}
			}
			else {
				while ((temp[j] != '-') && (temp[j] != '+')) {
					if (temp[j] != ' ') {
						obj.c2 += (temp[j] - '0') * pow(10, i - j);
					}
					j--;
				}
				if (temp[j] == '-') {
					obj.c2 = -obj.c2;
				}
			}
		}
		/*if (temp[i] == '-' || temp[i] == '+') {
			if (c2Read) {
				j = i;
				while (temp[j] != '=') {
					if (temp[j] != ' ') {
						obj.c1 += (temp[j] - '0') * pow(10, i - j);
					}
					j++;
				}
				if (temp[i] == '-') {
					obj.c1 = -obj.c1;
				}
			}
			else {
				j = i;
				while ((temp[j] != '-') && (temp[j] != '+')) {
					if (temp[j] != ' ') {
						obj.c1 += (temp[j] - '0') * pow(10, i - j);
					}
					j--;
				}
				if (temp[j] == '-') {
					obj.c1 = -obj.c1;
				}
			}
		}*/
		if (temp[i] == '=') {
			j = i;
			while (temp[j]) {
				if (temp[j] != ' ') {
					obj.c1 += (temp[j] - '0') * pow(10, i - j);
				}
				j--;
			}
			if (temp[i] == '-') {
				obj.c1 = -obj.c1;
			}
		}
		if (temp[i + 1] == '\0') {
			j = i;
			while (temp[j] != '=') {
				if (temp[j] != ' ') {
					rightSide += (temp[j] - '0') * pow(10, i - j);
				}
				j--;
			}
			if (temp[i] == '-') {
				rightSide = -rightSide;
			}
		}
	}
	obj.c1 -= rightSide;
	delete[] temp;
	return in;
}

ostream& operator<<(ostream& out, const QuadraticEq& obj) {
	out << obj.c3 << "x^2 + " << obj.c2 << "x + " << obj.c3 << " = 0\n";
	return out;
}
