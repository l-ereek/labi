#include <iostream>
#include <cmath>
int main()
{
	int x;
	setlocale(LC_ALL, "RU");
	std::cout << "Введите Х:";
	std::cin >> x;
	if (x < -2)
	{
		std::cout << "Y = " << ((2 + cos(pow(x, 3) + 3)) / (4 + pow(x, 2)));

	}
	if (x >= -2 && x < 3)
	{
		std::cout << "Y = " << ((2 - exp(-2 * x)) / (2 * pow(x, 2) + pow(x, 3)));
	}
	if (x >= 3)
	{
		std::cout << "Y = " << ((cos(pow(x, 2) + 5 * x)) / (5 * pow(x, 2) - 2));
	}
	return 0;
}