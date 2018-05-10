#include "Car.h"
#include "Sportcar.h"
#include "Truck.h"
#include "Pickup.h"
#include "MV_Train.h"
#include <iostream>

using namespace std;

int main() {
	try {
		Truck tr = { "Ford F150", 5, 13.5, 91, 340, 4 };
		Sportcar sp = { "Ferrari F150", 8, 12, 65, 321.8 };
		Car** arr = new Car*[2];
		arr[0] = &tr;
		arr[1] = &sp;
		for (size_t i = 0; i < 2; i++) {
			arr[i]->print(cout);
			cout << endl;
		}
	}
	catch (bad_alloc ba) {
		cout << ba.what() << endl;
	}
	catch (invalid_argument ia) {
		cout << ia.what() << endl;
	}
	catch (...) {
		cout << "Unhandled exception\n";
	}
	system("pause");
	return 0;
}