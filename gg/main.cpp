#include "dann.h"


int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "Задание 1" << endl;
    cout << "Нажмите Enter, чтобы продолжить...";
    cin.get();

    vivod1(Nom1_Input_FileName, Nom1_Output_FileName);

    cout << "Задание 2" << endl;
    cout << "Нажмите Enter, чтобы продолжить...";
    cin.get();

    if (!Prov(Nom2_Input_FileName))
    {
        cout << "Файл 'F.txt' не существует или пуст. Завершение работы." << endl;
        return 1;
    }

    string podstr;
    bool prov = true;

    while (prov)
    {
        podstr = VvodPodstr();

        if (!PodStr(Nom2_Input_FileName, podstr))
            cout << "Подстрока ' " << podstr << " ' не найдена в файле F." << endl;

        FvG(Nom2_Input_FileName, Nom2_Output_FileName, podstr);

        if (PodStr(Nom2_Output_FileName, podstr))
        {
            cout << "Проверка: подстрока присутствует в файле G. Задание выполнено.\n";
            prov = false;
        }
        else {
            prov = Vopros();
        }
    }

    cout << "Программа завершена.";
}
