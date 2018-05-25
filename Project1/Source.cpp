#include <fstream>
#include <iostream>

using namespace std;

int main() {
	fstream fs("input.bin", ios::in | ios::out | ios::binary);
	/*fs.write("Vitalik", 7);*/
	char* temp = new char[8];
	temp[7] = '\0';
	fs.read(temp, 7);
	cout << temp;
	system("pause");
	return 0;
}