#include "dann.h"

bool Prov(const string& filename)
{
    ifstream fout(filename);
    if (fout.is_open())
    {
        fout.seekg(0, ios::end);
        bool pusto = (fout.tellg() == 0);
        fout.close();
        return !pusto;
    }
    return false;
}

string Read(const string& filename)
{
    ifstream file(filename);
    string l, text;
    while (getline(file, l))
        text += l + '\n';
    if (!text.empty() && text.back() == '\n')
        text.pop_back();
    return text;
}

string Perebor(const string& text)
{
    string res;
    set<char> seen;
    for (char ch : text)
        if (seen.find(ch) == seen.end())
        {
            seen.insert(ch);
            res += ch;
        }
    return res;
}

void vivod1(const string& inputF, const string& outputF)
{
    if (!Prov(inputF))
    {
        cerr << "Ошибка: файл '" << inputF << "' не существует или пуст." << endl;
        return;
    }

    string text = Read(inputF);
    string per = Perebor(text);

    ofstream outFile(outputF);
    if (!outFile)
    {
        cerr << "Ошибка: не удалось создать файл '" << outputF << "'" << endl;
        return;
    }

    outFile << per;
    outFile.close();

    cout << "Готово! Уникальные символы (в порядке появления) сохранены в '" << outputF << "'" << endl;
    cout << "Содержимое: \"" << per << "\"" << endl;
}