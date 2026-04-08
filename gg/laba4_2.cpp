#include <iostream>
#include <string>
using namespace std;

float Znach(string v)
{
	float n;
	while (true)
	{
		cout << v;
		cin >> n;
		if (!cin)
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Ошибка! Введите вещественное число!"<< endl;
			continue;
		}
		cin.ignore(1000, '\n');
		if (cin.gcount() > 1)
		{
			cout << "После числа были введены дополнительные данные!" << endl;
			continue;
		}
		return n;
	
	}
}
void Obmen(float& A, float& B, float& C)
{
	float m = C;
	C = B;
	B = A;
	A = m;
}

int main()
{
	setlocale(LC_ALL, "RU");

	float A1 = Znach("Введите значение для А1: ");
	float B1 = Znach("Введите значение для В1: ");
	float C1 = Znach("Введите значение для C1: ");

	cout << "Было: " << A1 << " " << B1 << " " << C1 << endl;

	Obmen(A1, B1, C1);

	cout << "Стало:" << A1 << " " << B1 << " " << C1 << endl;

	float A2 = Znach("Введите значение для А2: ");
	float B2 = Znach("Введите значение для В2: ");
	float C2 = Znach("Введите значение для С2: ");

	cout << "Было: " << A2 << " " << B2 << " " << C2 << endl;

	Obmen(A2, B2, C2);

	cout << "Стало: " << A2 << " " << B2 << " " << C2 << endl;

}