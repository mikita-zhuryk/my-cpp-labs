#include "Queue2.h"
#include <iostream>
#include <fstream>

int main()
{
	size_t qSize = 0;
	cin >> qSize;
	Queue<int> q(qSize);
	cin >> q;
	cout << q;
}