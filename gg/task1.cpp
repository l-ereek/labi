#include "dann.h"

bool Prov(const string& failename)
{
    fstream f(failename);
    if (!f.is_open())
        return false;
    f.seekg(0, ios::end);
    bool empty = (f.tellg() == 0);
    f.close();
    return !empty;
}

string Read(const string& failename)
{
    fstream file(failename);
    string l, text;
    while (getline(file, l))
    {
        text += l + '\n';
    }
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
    cout << "";
    if (!Prov(inputF))
    {
        cout << "" << inputF << "" << endl;
        return;
    }
    string text = Read(inputF), per = Perebor(text);

    ofstream Sozd(outputF);
    if (!Sozd)
    {
        cout << "" << outputF << endl;
        return;
    }
    Sozd << per;
    Sozd.close();

    cout << "Готово! Уникальные символы (в порядке появления) сохранены в '" << outputF << "'" << endl;
    cout << "Содержимое: '" << per << "'";
}
