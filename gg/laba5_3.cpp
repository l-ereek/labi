#include <iostream>
using namespace std;
const int M = 20;
int yacheika[M + 1][M + 1];

int Combin2(int n, int k)
{
	if (k<0 || k > n)
		return 0;
	if (k == 0 || k == n)
		return 1;
	if (yacheika[n][k] != -1)
		return yacheika[n][k];
	yacheika[n][k] = Combin2(n - 1, k) + Combin2(n - 1, k - 1);
	return yacheika[n][k];
}
int main()
{
	setlocale(LC_ALL, "RU");
	int n;
	for (int n = 0; n <= M; n++)
		for (int k = 0; k <= M; k++)
			yacheika[n][k] = -1;

	while (true)
	{
		cout << "Введите N: ";
		cin >> n;
		if (!cin || n > 20)
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Ошибка! Введите целое число меньше 20: " << endl;
			continue;
		}
		cin.ignore(1000, '\n');
		if (cin.gcount() > 1)
		{
			cout << "После числа были введены дополнительные данные!" << endl;
			continue;
		}
		break;
	}
	for (int i = 1; i <= 5; i++)
	{
		int k;
		while (true)
		{
		cout << "Введите K: " << i << "-й раз" << endl;
		cin >> k;
		if (!cin || k < 0 || k > n)
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Ошибка! Введите целое число от 0 до N: " << endl;
			continue;
		}
		cin.ignore(1000, '\n');
		if (cin.gcount() > 1)
		{
			cout << "После числа были введены дополнительные данные!" << endl;
			continue;
		}
		break;
		}
		cout << "C(" << n << ", " << k << ") = " << Combin2(n, k) << endl;
	}
	return 0;
}