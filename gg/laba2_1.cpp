//#include <iostream>
//using namespace std;
//int main()
//{
//	setlocale(LC_ALL, "RU");
//	int n, cnt = 0, sum = 0;
//	cout << "Введите целое положительное число: ";
//	cin >> n;
//	while (n <= 0)
//	{
//		cout <<  "Ошибка! Введите целое ПОЛОЖИТЕЛЬНОЕ число: ";
//		cin >> n;
//	}
//	while (n > 0)
//	{
//		sum += n % 10;  //остаток
//		cnt++; //+1
//		n /= 10; //целое деление
//	}
//	cout << "Количество его цифр: " << cnt << endl;
//	cout << "Сумма его цифр: " << sum;
//	return 0;
//}