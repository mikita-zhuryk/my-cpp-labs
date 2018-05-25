#include "CONTAINER.h"
#include <fstream>

int main() {
	std::ofstream fout("output.bin", std::ios::binary);
	CONTAINER<Container1> cont1 = { Container1("Vasya", "Pushkina"), Container1("Petya", "Vaskina") };
	CONTAINER<Container2> cont2 = { Container2("Vasya", "02.03.2004"), Container2("Valentin", "15.03.2009") };
	CONTAINER<Container3> cont3 = { Container3("Vasya", "Pushkina", 3.5), Container3("Petya", "Vaskina", 5.6) };
	fout << cont1 << cont2 << cont3;
	system("pause");
	return 0;
}