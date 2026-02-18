//#include <iostream>
//using namespace std;
//int main()
//{
//	setlocale(LC_ALL, "RU");
//	int n, cnt = 0, sum = 0;
//	while (true)
//	{
//		cout << "Введите целое положительное число: ";
//		cin >> n;
//		if (cin.fail())
//		{
//				cin.clear();
//				cin.ignore(1000000, '\n');
//				cout << "Ошибка! Введите число." << endl;
//				continue;
//		}
//		if (n <= 0)
//		{
//			std :: cout << "Ошибка! Введите целое ПОЛОЖИТЕЛЬНОЕ число." << endl;
//			cin.clear();
//			cin.ignore(1000000, '\n');
//			continue;
//		}
//		break;
//	}
//	while (n > 0)
//	{
//		sum += n % 10;
//		cnt++;
//		n /= 10;
//	}
//	cout << "Количество его цифр: " << cnt << endl;
//	cout << "Сумма его цифр: " << sum;
//	return 0;
//}