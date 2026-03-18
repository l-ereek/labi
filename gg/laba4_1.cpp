#include <iostream>
#include <string>
int main()
{
	using namespace std;
	setlocale(LC_ALL, "RU");
	char st[1000];
	char* p = st;
	int cnt = 0;
	cout << "Введите предложение: ";
	cin.getline(st, sizeof(st));
	cout << st;
	
	for (int i = 0; i < sizeof(st); i++)
		if (*(p + i) != ' ' && (*(p + i+1) == ' '|| *(p+i+1)=='\0'))
		{
			cnt++;
			i++;
		}
	cout << "Количество слов в предложении: " << cnt;
 }