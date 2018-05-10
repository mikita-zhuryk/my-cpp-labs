#include "..\Lab4\Queue.h"
#include <iostream>
#pragma warning(disable: 4996)

using namespace std;

struct incorrect_input {};

int menu()
{
	Queue q;
	bool loop = true;
	int option = -1;
	while (loop) {
		cout << "Choose an option:\n 1. Show queue state.\n 2. Add an element.\n 3. Delete an element.\n 4. Exit.\n";
		cin >> option;
		cin.ignore(1);
		switch (option) {
		case 1: {
			q.show();
			break;
		}
		case 2: {
			char temp[255];
			cout << "Enter street.\n";
			cin.getline(temp, 255);
			int house;
			cout << "Enter house.\n";
			if (!(cin >> house)) {
				throw invalid_argument("Incorrect input");
			}
			int building;
			cout << "Enter building.\n";
			if (!(cin >> building)) {
				throw invalid_argument("Incorrect input");
			}
			int flat;
			cout << "Enter flat.\n";
			if (!(cin >> flat)) {
				throw invalid_argument("Incorrect input");
			}
			Address tempA(temp, house, building, flat);
			q.add(tempA);
			break;
		}
		case 3: {
			//cout << "Deleted: " << 
			q.pop();
			break;
		}
		case 4: {
			loop = false;
			break;
		}
		default: {
			throw incorrect_input();
		}
		}
	}
	return 0;
}

int main() {
	try {
		menu();
	}
	catch (bad_alloc err)
	{
		cout << "Allocation error: " << err.what() << endl;
	}
	catch (incorrect_input err)
	{
		cout << "Incorrect input.\n";
	}
	catch (invalid_argument ia) {
		cout << ia.what() << endl;
	}
	system("pause");
	return 0;
}