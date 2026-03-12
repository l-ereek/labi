#include <iostream>
#include <cmath>
int main()
{
	using namespace std;
	srand(time(0));
	setlocale(LC_ALL, "RU");
	float U[7], D[7], V[7];
	for (int i = 0; i < 7; i++)
	{
		*(U + i) = (fmod(0.01 * rand(), 40 - (-40)) + (-40));
		*(D + i) = (fmod(0.01 * rand(), 40 - (-40)) + (-40));
		*(V + i) = (fmod(0.01 * rand(), 40 - (-40)) + (-40));
	}
	cout << "Утреня температура: ";
	for (int i = 0; i < 7; i++)
		cout << *(U + i)<< "\t";
	cout << endl;
	cout << "Дневная температура: ";
	for (int i = 0; i < 7; i++)
		cout << *(D + i) << "\t";
	cout << endl;
	cout << "Вечерняя температура: ";
	for (int i = 0; i < 7; i++)
		cout << *(V + i)<< "\t";
	cout << endl;

	float SP[7];
	for (int i = 0; i < 7; i++) {
		*(SP + i) = (*(U + i) + *(D + i) + *(V + i)) / 3;
		cout << *(SP + i) << '\t';
	}
}