#include "dann.h"

void Chistka()
{
    cin.clear();
    cin.ignore(1000, '\n');
}

bool PodStr(const string& filename, const string& podstr)
{
    if (Prov(filename))
    {
        ifstream fout(filename);
        string l;
        while (getline(fout, l))
            if (l.find(podstr) != string::npos)
                return true;
        fout.close();
        return false;
    }
    return false;
}

void FvG(const string& inputF, const string& outputF, const string& podstr)
{
    if (!Prov(inputF))
    {
        cout << "Ошибка: файл '" << inputF << "' не существует или пуст." << endl;
        return;
    }

    ifstream inFile(inputF);
    ofstream outFile(outputF);
    if (!outFile)
    {
        cout << "Ошибка: не удалось создать файл '" << outputF << "'" << endl;
        return;
    }

    string l;
    bool found = false;
    while (getline(inFile, l))
    {
        if (l.find(podstr) != string::npos)
        {
            outFile << l << '\n';
            found = true;
        }
    }
    inFile.close();
    outFile.close();

    if (!found)
    {
        cout << "В файле '" << inputF << "' нет ни одной строки, содержащей подстроку '" << podstr << "'" << endl;
        remove(outputF.c_str());
    }
    else
        cout << "Готово! Строки, содержащие '" << podstr << "', сохранены в '" << outputF << "'" << endl;
}

bool Vopros()
{
    char ans;
    cout << "Повторить ввод? (y - да, n - завершить): ";

    while (true)
    {
        cin >> ans;
        Chistka();
        if (ans == 'y' || ans == 'Y')
            return true;
        else if (ans == 'n' || ans == 'N')
            return false;
        else
            cout << "Ошибка! Введите 'y' для повтора или 'n' для завершения: ";
    }
}

string VvodPodstr()
{
    string s;
    cout << "Введите подстроку для поиска: ";
    getline(cin, s);
    return s;
}