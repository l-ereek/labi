#include <iostream>
#include <cmath>
int main()
{
	setlocale(LC_ALL, "RU");
	int x, y, z;
	std::cout << "¬ведите переменную Z:";
	std::cin >> z;
	std::cout << "¬ведите переменную Y:";
	std::cin >> y;
	std::cout << "„исло X равн€етс€: " << -pow(z, y) + pow(y, z);
	return 0;
}