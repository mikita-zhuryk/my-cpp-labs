#include "..\Lab4\Queue.h"
#include <iostream>

using namespace std;

struct incorrect_input {};

int menu()
{
	Queue q;						//TODO: Add Elem->Delete Elem->Show State->CRASH
	bool loop = true;
	int option = -1;
	while (loop) {
		cout << "Choose an option:\n 1. Show queue state.\n 2. Add an element.\n 3. Delete an element.\n 4. Exit.\n";
		cin >> option;
		cin.ignore(1);
		switch (option) {
		case 1: {
			q.showState();
			break;
		}
		case 2: {
			char temp[255];
			cout << "Enter street.\n";
			cin.getline(temp, 255);
			int house;
			cout << "Enter house.\n";
			cin >> house;
			int building;
			cout << "Enter building.\n";
			cin >> building;
			int flat;
			cout << "Enter flat.\n";
			cin >> flat;
			q.addElem(temp, house, building, flat);
			break;
		}
		case 3: {
			//cout << "Deleted: " << 
			q.popElem();
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
	system("pause");
	return 0;
}