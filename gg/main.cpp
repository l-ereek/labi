#include "dann.h"

void Menu()
{
	cout << "\n" << string(60, '=') << endl;
	cout << "Задания: " << endl;
	cout << "1. Академические задолженности по факультетам" << endl;
	cout << "2. Очередность предоставления мест в общежитии" << endl;
	cout << "3. Выход" << endl;
}

int main()
{
	setlocale(LC_ALL, "RU");
	Menu();
	int ch = prov("Выберите пункт меню (1-3): ", 1, 3);
	while (ch != 3)
	{
		if (ch == 1)
		{
			res1();
			break;
		}
		if (ch == 2)
		{
			res2();
			break;
		}

	}
	cout << "Работа программы завершена." << endl;
}