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
			cout << "Ошибка! Строка не может быть пустой: " << endl;
			getline(cin, st);
			continue;
		}
		cout << "Введи слово, которое хотите заменить: " << endl;
		cin >> A;
		if (A.empty() )
		{
			cout << "Ошибка! Cлово не может быть пустым: " << endl;
			cin >> A;
			continue;
		}
		cout << "Введи слово, которым хотите заменить предыдущее: " << endl;
		cin >> B;
		if (B.empty())
		{
			cout << "Ошибка! Cлово не может быть пустым: " << endl;
			cin >> B;
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
	cout << "Результат: " << res;
}