#include <iostream>
#include <cmath>
using namespace std;
int main()
{
		setlocale(LC_ALL, "RU");
		int n;
		while (true)
		{
			cout << "¬ведите целое положительное число: ";
			cin >> n;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "ќшибка! ¬ведите число." << endl;
				continue;
			}
			if (n <= 0)
			{
				cout << "ќшибка! ¬ведите целое ѕќЋќ∆»“≈Ћ№Ќќ≈ число." << endl;
				continue;
			}
			break;
		}
		while (n <= 0)
		{
			cout << "ќшибка! ¬ведите Ќј“”–јЋ№Ќќ≈ число (1, 2, 3...): " << endl;
			cin >> n;
		}
		double sum = 0;

		for (int i = 1; i <= n; i++)
		{
			sum += 1 + (1 / pow(i, 2));
		}
		cout << "¬ыражение равн€етс€: " << sum;
		return 0;
	}