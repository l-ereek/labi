#include <iostream>
#include <cmath>
int main()
{
	setlocale(LC_ALL, "RU");
	int x, y, z;
	std::cout << "Введите переменную Z:";
	std::cin >> z;
	std::cout << "Введите переменную Y:";
	std::cin >> y;
	std::cout << "Число X равняется: " << - pow(z, y) + pow(y, z);
	return 0;
}