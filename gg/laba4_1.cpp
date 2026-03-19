#include <iostream>
#include <string>

int main()
{
    using namespace std;
    setlocale(LC_ALL, "RU");

    char st[1000];
    int cnt = 0;
    bool inWord = false; 
    cout << "Введите предложение: ";
    cin.getline(st, 1000);
    for (int i = 0; st[i] != '\0'; i++)
    {
        if ( st[i] == ' ' || st[i] == ',' || st[i] == ';' || st[i] == '.')
            inWord = false; 
        else
        {
            if (!inWord)
            {
                cnt++;
                inWord = true; 
            }
        }
    }

    cout << "Количество слов в предложении: " << cnt << endl;
}