#include <iostream>
#include <limits>
#include <cmath>
using namespace std;
int main()
{
	setlocale(LC_ALL, "RU");
	float n, cnt = 0, sum = 0;
	while (true)
	{
		cout << "Введите целое положительное число: ";
		cin >> n;
		if (cin.fail())
		{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Ошибка! Введите число." << endl;
				continue;
		}
		if (n <= 0.0f || fmod(n, 1.0f) != 0.0)
		{
			cout << "Ошибка! Введите ЦЕЛОЕ ПОЛОЖИТЕЛЬНОЕ число." << endl;
			continue;
		}
		break;
	}
	while (n > 0)
	{
		sum += fmod(n, 10);
		cnt++;
		n /= 10;
	}
	cout << "Количество его цифр: " << cnt << endl;
	cout << "Сумма его цифр: " << sum;
	return 0;
}