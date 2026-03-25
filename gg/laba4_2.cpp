#include <iostream>
#include <string>
int main()
{
	using namespace std;
	setlocale(LC_ALL, "Russian");
	int sizeT, i = 0;
	string res, st, A, B;
	while (true)
	{
		cout << "Введите предложение: " << endl;
		getline(cin, st);
		if (st.empty())
		{
			cout << "Ошибка! Строка не может быть пустой." << endl;
			continue;
		}

		int pr = 0;
		for (int i = 0; i != st.length(); i++)
			if (st[i] == ' ')
				pr++;
		if (pr == st.length())
		{
			cout << "Ошибка! Слово не может состоять только из пробелов." << endl;
			continue;
		}
		break;
	}

	while (true)
	{
		cout << "Введите слово, которое хотите заменить: " << endl;
		cin >> A;
		if (st.find(A) == A.npos)
		{
			cout << "Такого слова нет!" << endl;
			continue;
		}

		if (A.empty())
		{
			cout << "Ошибка! Cлово не может быть пустым." << endl;
			continue;
		}

		int pr1 = 0;
		for (int i = 0; i != A.length(); i++)
			if (A[i] == ' ')
				pr1++;
		if (pr1 == A.length())
		{
			cout << "Ошибка! Слово не может состоять только из пробелов." << endl;
			continue;
		}
		break;
	}

	while(true)
	{
		cout << "Введите слово, которым хотите заменить предыдущее: " << endl;
		cin >> B;
		if (B.empty())
		{
			cout << "Ошибка! Cлово не может быть пустым." << endl;
			continue;
		}

		int pr2 = 0;
		for (int i = 0; i != B.length(); i++)
			if (B[i] == ' ')
				pr2++;
		if (pr2 == B.length())
		{
			cout << "Ошибка! Слово не может состоять только из пробелов." << endl;
			continue;
		}
		break;
	}
	sizeT = st.length();
	while (i < sizeT)
	{
		if (st[i] == ' ')
		{
			res += st[i];
			i++;
			continue;
		}
		int nach = i;
		while (i < sizeT && st[i] != ' ')
			i++;
		string w = st.substr(nach, i - nach);
		if (w == A)
			res += B;
		else
			res += w;
	}
	cout << "Результат: " << res << endl;;
}