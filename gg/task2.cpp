#include "dann.h"
#include "task1.cpp"

void Chistka()
{
    cin.clear();
    cin.ignore(1000, '\n');
}

bool PodStr(const string& filename, const string& podstr)
{
    if (!Prov(filename))
        return false;
    ifstream file(filename);
    string l;
    while (getline(file, l))
    {
        if (l.find(podstr) != string::npos)
        {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}


void FvG(const string& inputF, const string outputF, const string& podstr)
{
    if (!Prov(inputF))
    {
        cout << "Ошибка: файл '" << inputF << "' не существует или пуст.";
        return;
    }
    ifstream inF(inputF);
    ofstream outF(outputF);
    if (!outF)
    {
        cout << "Ошибка: не удалось создать файл '" << outputF << "'" << endl;
        return;
    }
    string l;
    bool naxod = false;
    while (getline(inF, l))
        if (l.find(podstr) != string::npos)
        {
            outF << l << endl;
            naxod = true;
        }
    inF.close();
    outF.close();

    if (!naxod)
    {
        cout << "В файле '" << inputF << "' нет ни одной строки, содержащей подстроку '" << podstr << "'" << endl;
        remove(outputF.c_str());
    }
    else
    {
        cout << "Готово! Строки, содержащие '" << podstr << "', сохранены в '" << outputF << endl;
    }
}

bool Vopros()
{
    cout << "Подстрока не найдена в файле G (он создан, но пуст или подстроки нет)." << endl;
    cout << "Повторить ввод? (y - да, n - завершить): ";
    char otv;
    cin >> otv;
    Chistka();
    return (otv == 'y' || otv == 'Y');
}


string VvodPodstr()
{
    string s;
    cout << "Введите подстроку для поиска: ";
    getline(cin, s);
    return s;
}
