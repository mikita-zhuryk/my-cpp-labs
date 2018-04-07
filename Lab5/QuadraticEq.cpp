#include "QuadraticEq.h"

QuadraticEq::~QuadraticEq() {
}

void QuadraticEq::solve(ostream& out) const {
	double discr = 0;
	double x1r, x2r, x1i, x2i;
	x1r = x2r = x1i = x2i = 0;
	bool complex = false;
	if (!c3) {
		((LinearEq)*this).solve(out);
	}
	else {
		discr = pow(c2, 2) - 4 * c3 * c1;
		if (discr < 0) {
			complex = true;
			discr = -discr;
		}
		x1r = (-c2) / (2 * c3);
		x1i = sqrt(discr) / (2 * c3);
		x2r = x1r;
		x2i = x1i;
		if (complex) {
			out << "Solution: x1 = " << x1r << " + " << x1i << 'i' << "; x2 = " << x2r << " - " << x2i << 'i' << ".\n";
		}
		else {
			out << "Solution: x1 = " << x1r + x1i << "; x2 = " << x2r - x2i << ".\n";
		}
	}
}

//istream& operator>>(istream& in, QuadraticEq<int>& obj) {
//	char* temp = new char[15];
//	in.getline(temp, 14);
//	int j;
//	bool c2Read = false;
//	int length = strlen(temp);
//	int rightSide = 0;
//	obj.c1 = obj.c2 = 0;
//	for (int i = 0; i < length; i++) {
//		if (temp[i] == 'x') {
//			j = i;
//			if (temp[i + 1] == '^') {
//				while ((temp[j] != '-') && (temp[j] != '+')) {
//					if (temp[j] != ' ') {
//						obj.c3 += (temp[j] - '0') * pow(10, i - j);
//					}
//					j--;
//				}
//				if (temp[j] == '-') {
//					obj.c3 = -obj.c3;
//				}
//			}
//			else {
//				while ((temp[j] != '-') && (temp[j] != '+')) {
//					if (temp[j] != ' ') {
//						obj.c2 += (temp[j] - '0') * pow(10, i - j);
//					}
//					j--;
//				}
//				if (temp[j] == '-') {
//					obj.c2 = -obj.c2;
//				}
//			}
//		}
//		if (temp[i] == '=') {
//			j = i;
//			while (temp[j]) {
//				if (temp[j] != ' ') {
//					obj.c1 += (temp[j] - '0') * pow(10, i - j);
//				}
//				j--;
//			}
//			if (temp[i] == '-') {
//				obj.c1 = -obj.c1;
//			}
//		}
//		if (temp[i + 1] == '\0') {
//			j = i;
//			while (temp[j] != '=') {
//				if (temp[j] != ' ') {
//					rightSide += (temp[j] - '0') * pow(10, i - j);
//				}
//				j--;
//			}
//			if (temp[i] == '-') {
//				rightSide = -rightSide;
//			}
//		}
//	}
//	obj.c1 -= rightSide;
//	delete[] temp;
//	return in;
//}

istream& operator>>(istream& in, QuadraticEq& obj) {
	if (!in || in.eof()) {
		throw bad_stream();
	}
	if (!(in >> obj.c3) || !(in >> obj.c2) || !(in >> obj.c1)) {
		throw bad_input();
	}
	return in;
}

ostream& operator<<(ostream& out, const QuadraticEq& obj) {
	if (!out) {
		throw bad_stream();
	}
	out << obj.c3 << "x^2 + " << obj.c2 << "x + " << obj.c3 << " = 0\n";
	return out;
}
