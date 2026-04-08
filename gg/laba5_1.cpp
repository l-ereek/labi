#include <iostream>
#include <random>
using namespace std;

int Size(string v)
{
	int n;
	while (true)
	{
		cout << v;
		cin >> n;
		if (!cin || n <=0 )
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Ошибка! Введите целое положительное число!"<< endl;
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
int Sum(int M[], int size)
{
	int sum = 0;
	int cnt = 0;
	for (int i = 0; i < size; i++)
		if (M[i] > 0)
		{
			cnt++;
			sum += M[i];
		}
	if (cnt == 0)
		return 0;
	else
		return sum / cnt;
}

int* Gen(const int size)
{
	int* M = new int[size];
	for (int i = 0; i < size; i++)
	{
		M[i] = rand() % 61 - 30;
	}
	return M;
}

void Mas(int M[], const int size)
{
	for (int i = 0; i < size; i++)
		cout << M[i] << " ";
}
 
int main()
{
	setlocale(LC_ALL, "RU");
	srand(time(0));
	int N = Size("Введите размер массива Х: ");
	int M = Size("Введите размер массива Y: ");
	int K = Size("Введите размер массива Z: ");

	int* X = Gen(N);
	int* Y = Gen(M);
	int* Z = Gen(K);

	cout << "Массив X равен: "; Mas(X, N); cout << endl;
	cout << "Сумма его положительных элементов равна:" << Sum(X, N) << endl;
	cout << endl;
	cout << "Массив Y равен: "; Mas(Y, M); cout << endl;
	cout << "Сумма его положительных элементов равна:" << Sum(Y, M) << endl;
	cout << endl;
	cout << "Массив Z равен: "; Mas(Z, K); cout << endl;
	cout << "Сумма его положительных элементов равна:" << Sum(Z, K) << endl;

	delete[]X;
	delete[]Y;
	delete[]Z;

}