//#include <iostream>
//#include <string>
//#include <cstdlib>
//using namespace std;
//
//int main()
//{
//	setlocale(LC_ALL, "Russian");
//	system("chcp 1251");
//	int i = 0;
//	string res, st, A, B;
//	while (true)
//	{
//		cout << "Введите предложение: " << endl;
//		getline(cin, st);
//		if (st.empty())
//		{
//			cout << "Ошибка! Строка не может быть пустой." << endl;
//			continue;
//		}
//
//		int pr = 0;
//		for (int i = 0; i != st.length(); i++)
//			if (st[i] == ' ')
//				pr++;
//		if (pr == st.length())
//		{
//			cout << "Ошибка! Слово не может состоять только из пробелов." << endl;
//			continue;
//		}
//		break;
//	}
//
//	while (true)
//	{
//		cout << "Введите слово, которое хотите заменить: " << endl;
//		cin >> A;
//		if (st.find(A) == A.npos)
//		{
//			cout << "Такого слова нет!" << endl;
//			continue;
//		}
//		break;
//	}
//
//	while (true)
//	{
//		cout << "Введите слово, которым хотите заменить предыдущее: " << endl;
//		cin >> B;
//		if (A == B)
//		{
//			cout << "A не может совпадать с B!" << endl;
//			continue;
//		}
//		break;
//	}
//	while (i < st.length())
//	{
//		if (st[i] == ' ')
//		{
//			i++;
//			res += st[i];
//			continue;
//		}
//		int nach = i;
//		while (i < st.length() && st[i] != ' ')
//			i++;
//		string w = st.substr(nach, i - nach);
//		if (w == A)
//			res += B;
//		else
//			res += w
//	}
//
//cout << "Результат: " << res << endl;
//}