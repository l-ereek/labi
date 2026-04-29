#include "dann.h"

void chistka()
{
    cin.clear();
    cin.ignore(1000, '\n');
}

int prov(const string& str, int min, int max)
{
    int n;
    while (true)
    {
        cout << str;
        cin >> n;
        if (cin.fail() || n < min || n > max) {
            chistka();
            cout << "Ошибка! Введите число от " << min << " до " << max << ": ";
        }
        else {
            return n;
        }
    }
}

double provD(const string& str, double min, double max)
{
    double n;
    while (true)
    {
        cout << str;
        cin >> n;
        if (cin.fail() || n < min || n > max) {
            cout << "Ошибка! Введите число от " << min << " до " << max << ": ";
            chistka();
        }
        else
            return n;
    }
}

void CrF(Nom_1 f[], int n)
{
    string name[] = {"Факультет информатики", "Факультет экономики",
        "Факультет математики", "Юридический факультет",
        "Факультет психологии", "Факультет филологии",
        "Медицинский факультет", "Инженерный факультет" };

    for (int i = 0; i < n; i++)
    {
        f[i].facultet = name[i];
        f[i].d2023 = rand() % 100;
        f[i].d2024 = rand() % 100;
        f[i].d2025 = rand() % 100;
        f[i].sum = f[i].d2023 + f[i].d2024 + f[i].d2025;
    }
}
void vivod1(const Nom_1 f[], int n)
{
    cout << "Информация о задолженностях по факультетам:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << f[i].facultet << endl;
        cout << "2021: " << f[i].d2023 << endl;
        cout << "2022: " << f[i].d2024 << endl;
        cout << "2023: " << f[i].d2025 << endl;
        cout << "Всего: " << f[i].sum << endl << endl;
    }
}

void MinMax(const Nom_1 f[], int n, string& minF, string& maxF, int& minS, int& maxS)
{
    minS = f[0].sum;
    maxS = f[0].sum;
    minF = f[0].facultet;
    maxF = f[0].facultet;
    for (int i = 0; i < n; i++)
    {
        if (f[i].sum < minS)
        {
            minS = f[i].sum;
            minF = f[i].facultet;
        }
        if (f[i].sum > maxS)
        {
            maxS = f[i].sum;
            maxF = f[i].facultet;
        }
    }
 }
void res1()
{
    srand(time(0));
    cout << "1.АКАДЕМИЧЕСКИЕ ЗАДОЛЖЕННОСТИ" << endl;
    int n = prov("Введите количество факультетов (от 1 до 8): ", 1, 8);
    Nom_1 f[8];
    CrF(f, n);
    vivod1(f,n);
    string minF, maxF;
    int minS, maxS;
    MinMax(f, n, minF, maxF, minS, maxS);
    cout << "РЕЗУЛЬТАТЫ" << endl;
    cout << "Факультет с МИНИМАЛЬНЫМ количеством задолженностей (" << minS << "): " << minF << endl;
    cout << "Факультет с МАКСИМАЛЬНЫМ количеством задолженностей (" << maxS << "): " << maxF << endl;
}