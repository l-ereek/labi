#include <iostream>
#include <cmath>
int main()
{
	using namespace std;
	setlocale(LC_ALL, "RU");
	float M[10];
	float nach, kon;
	while (true)
	{
		cout << "Введите начало диапазона для генерации массива: ";
		cin >> nach;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Ошибка, введите ЧИСЛО.";
			continue;
		}
		break;
	}
	while (true)
	{
		cout << "Введите конец диапазона для генерации массива: ";
		cin >> kon;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Ошибка, введите ЧИСЛО.";
			continue;
		}
		if (nach >= kon)
		{
			cout << "Ошибка. Начало должно быть меньше концу." << endl;
			continue;
		}
		break;
	}
	cout << "Массив состоит из: ";
	for (int  i = 0; i < 10; i++)
	{
		*(M + i) = fmod(0.001*rand(), kon - nach) + nach;
		cout << *(M + i) << ' ';
	}
	cout << endl;
	float cnt = 1;
	for (int i = 0; i < 10; i++)
		if (*(M + i) > 0)
			cnt *= *(M + i);

	cout << "Произведение положительных элементов массива: " << cnt << endl;
}