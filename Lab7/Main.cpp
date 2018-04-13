#include "IntList.h"
#include "DoubleList.h"

using namespace std;

int main() {
	try {
		int arr[3] = { 3, 5, 6 };
		IntList il(arr, 3);
		double arrD[3] = { 36.1234, 3.14159265358979, 2.781828182845904523536 };
		DoubleList dl(arrD, 3);
		List** listArray = new List*[2];
		listArray[0] = &il;
		listArray[1] = &dl;
		for (int i = 0; i < 2; i++) {
			listArray[i]->print(cout);
		}
	}
	catch (invalid_argument ia) {
		cout << "Invalid argument: " << ia.what() << endl;
	}
	catch (bad_alloc ba) {
		cout << ba.what() << endl;
	}
	catch (...) {
		cout << "Unhandled exception.\n";
	}
	system("pause");
	return 0;
}