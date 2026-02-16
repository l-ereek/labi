
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
		setlocale(LC_ALL, "RU");
		int n;
		cout << "Введите натуральное число: " << endl;
		cin >> n;
		while (n <= 0)
		{
			cout << "Ошибка! Введите НАТУРАЛЬНОЕ число (1, 2, 3...): " << endl;
			cin >> n;
		}
		double sum = 0;

		for (int i = 1; i <= n; i++)
		{
			sum += 1 + (1 / pow(i, 2));
		}
		cout << "Выражение равняется: " << sum;
		return 0;
	}