#include "dann.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");

    cout << "=Задание 1" << endl;
    cout << "Убедитесь, что файл '" << Nom1_Input_FileName << "' существует в папке с программой." << endl;
    cout << "Нажмите Enter, чтобы продолжить...";
    cin.get();

    vivod1(Nom1_Input_FileName, Nom1_Output_FileName);

    cout << "Задание 2" << endl;
    cout << "Убедитесь, что файл '" << Nom2_Input_FileName << "' существует в папке с программой." << endl;
    cout << "Нажмите Enter, чтобы продолжить...";
    cin.get();

    if (!Prov(Nom2_Input_FileName))
    {
        cout << "Файл '" << Nom2_Input_FileName << "' не существует или пуст. Завершение работы." << endl;
        return 1;
    }

    string podstr;
    bool prov = true;

    while (prov)
    {
        podstr = VvodPodstr();
        FvG(Nom2_Input_FileName, Nom2_Output_FileName, podstr);
        PodStr(Nom2_Output_FileName, podstr);
        prov = Vopros();
    }

    cout << "\nПрограмма завершена." << endl;
    return 0;
}