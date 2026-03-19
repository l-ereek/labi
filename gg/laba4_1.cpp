#include <iostream>
#include <string>

int main()
{
    using namespace std;
    setlocale(LC_ALL, "RU");
    string st;
    int cnt = 0;
    cout << "Введите предложение: ";
    getline(cin, st);
    bool w = false;
    for (char c : st)
    {
        if (c == ' ' || c == ':' || c == ';')
            w = false;
        else if (!w)
        {
            cnt++;
            w = true;
        }
    }

    cout << "Количество слов в предложении: " << cnt << endl;

    return 0;
}