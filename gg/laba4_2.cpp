//#include <iostream>
//#include <string>
//using namespace std;
//
//float Znach(string v)
//{
//	float n;
//	cout << v;
//	cin >> n;
//	while (true)
//	{
//		if (cin.fail() || n != floor(n))
//		{
//			cin.clear();
//			cin.ignore(1000, '\n');
//			cout << "Ошибка! Нужно вещественное число" << endl;
//			continue;
//		}
//		break;
//	}
//	return n;
//}
//float Obmen(float A, float B, float C)
//{
//	float m = A;
//	A = B;
//	B = C;
//	C = m;
//	return A, B, C;
//}
//int main()
//{
//	setlocale(LC_ALL, "RU");
//
//	float A1 = Znach("Введите значение для А1: ");
//	float B1 = Znach("Введите значение для В1: ");
//	float C1 = Znach("Введите значение для А1: ");
//	float A2 = Znach("Введите значение для А2: ");
//	float B2 = Znach("Введите значение для В2: ");
//	float C2 = Znach("Введите значение для С2: ");
//
//	cout << ""<< Obmen(A1, B1, C1)<< endl;
//	cout << ""<< Obmen(A2, B2, C2);
//}