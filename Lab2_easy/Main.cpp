#include "Queue2_easy.h"
#include <iostream>

using namespace std;

void state(Queue& q)
{
	cout << "Current queue state is: \n" << q << endl;
}

int main()
{
	size_t length = 0;
	int elem = 0;
	size_t pos = -1;
	try {
		cout << "Input queue length.\n";
		cin >> length;
		Queue q(length);
		//cout << "Input queue elements.\n";
		cin >> q;
		cin.clear();
		state(q);
		cout << "Input element to add.\n";
		cin >> elem;
		q.add(elem);
		state(q);
		//q.remove();
		//state(q);
		q.addToPos(7, 5);
		for (int i = 0; i < 10; i++)
		{
			q.removeFromPos(1);
		}
		state(q);
	}
	catch (int code)
	{
		switch (code)
		{
		case 1:
			{
				cout << "Incorrect position.\n";
				break;
			}
		case 2:
			{
				cout << "Couldn't open output file.\n";
				break;
			}
		case 3:
			{
				cout << "Couldn't open input file.\n";
				break;
			}
		case 4:
			{
				cout << "Input file is empty (reached end of file).\n";
				break;
			}
		case 5:
			{
				cout << "Allocation error.\n";
				break;
			}
		default:
			{
				cout << "Unhandled exception #" << code << ".\n";
			}
		}
	}
	catch (OutOfBounds out)
	{
		cout << "Exceeded array limits.\n";
	}
	system("pause");
	return 0;
}