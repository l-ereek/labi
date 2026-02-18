//#include <iostream>
//using namespace std;
//int main()
//{
//	setlocale(LC_ALL, "RU");
//	int k = 1;
//	float p, s = 10;
//	while(true)
//	{
//		cout << "Введите увеличение длины пробега от 0 до 50: ";
//		cin >> p;
//		if (cin.fail())
//		{
//			cin.clear();
//			cin.ignore(1000, '\n');
//			cout << "Ошибка! Введите число." << endl;
//			continue;
//		}
//		if (p <= 0 || p >= 50)
//		{
//			cout << "Ошибка! Введите от 0 до 50." << endl;
//			continue;
//		}
//		break;
//	}
//	while (s <= 200)
//	{
//		s += 1 + p / 100;
//		k++;
//	}
//	cout << "Количество дней: " << k << endl;
//	cout << "Суммарный пробег: " << s;
//	return 0;
//}