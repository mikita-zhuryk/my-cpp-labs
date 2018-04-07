#include "LinearEq.h"

LinearEq::~LinearEq() {
}

void LinearEq::solve(ostream& out) const {
	if (!c2) {
		if (!c1) {
			out << "Solution consists of all numbers (0x + 0 = 0).\n";
		}
		else {
			out << "No solutions (0x + b = 0, b not equal to 0).\n";
		}
	}
	else {
		out << "x1 = " << -c1 / c2 << ".\n";
	}
}

//istream& operator>>(istream& in, LinearEq<int>& obj) {
//	char* temp = new char[15];
//	in.getline(temp, 14);
//	int j;
//	int length = strlen(temp);
//	int rightSide = 0;
//	obj.c1 = obj.c2 = 0;
//	for (int i = 0; i < length; i++) {
//		if (temp[i] == 'x') {
//			j = i;
//			while ((temp[j] != '-') && (temp[j] != '+')) {
//				if (temp[j] != ' ') {
//					obj.c2 += (temp[j] - '0') * pow(10, i - j);
//				}
//				j--;
//			}
//			if (temp[j] == '-') {
//				obj.c2 = -obj.c2;
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

istream& operator>>(istream& in, LinearEq& obj) {
	if (!in || in.eof()) {
		throw bad_stream();
	}
	if (!(in >> obj.c2) || !(in >> obj.c1)) {
		throw bad_input();
	}
	return in;
}

ostream& operator<<(ostream& out, const LinearEq& obj) {
	if (!out) {
		throw bad_stream();
	}
	out << obj.c2 << "x + " << obj.c2 << " = 0\n";
	return out;
}
