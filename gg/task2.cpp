#include "dann.h"
void CrSt(Nom_2 s[], int n)
{
    string f[] = { "Скребцов", "Дзейтов", "Новикова", "Лободина", "Казыханова", "Работнова", "Бурдюгов"};
    string u[] = { " Илья", " Саид", " Юлия", " Виктория", " Ольга", " Валерия", " Дарья"};
    string o[] = { " Олегович", " Абабукарович", " Игоревна", " Владимировна", " Станиславовна", " Алексеевна", " Сергеевич"};
    string g[] = { " ВПР11"," ВПР12", " ВПР13", " ВПР14", " ВПР15", " ВПР16", " ВПР17" };
    for (int i = 0; i < n; i++)
    {
        s[i].fuo = f[rand() % 7] + u[rand()%7] + o[rand() % 7];
        s[i].gr = g[rand() % 7];
        s[i].sum = 3.0 + (rand() % 300) / 100.0;
        s[i].d = 5000 + (rand() % 30000);
        s[i].pr = s[i].d < (2 * min_zarplata);
    }
}

void vivod2(const Nom_2 s[], int n, const string str)
{
    cout << str << endl << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ". " << endl;
        cout << s[i].fuo << endl;
        cout << "Группа: " << s[i].gr << "\n";
        cout << "Средний балл: " << s[i].sum << "\n";
        cout << "Доход: " << s[i].d << "\n";
        cout << "Приоритет: " << s[i].pr << "\n"<< endl << endl ;
    }
}

void Pr(const Nom_2 s[], int n, Nom_2 list[], int& cnt)
{
    Nom_2 prSt[max_st];
    Nom_2 regSt[max_st];
    int prCnt = 0;
    int regCnt = 0;

    for (int i = 0; i < n; i++)
        if (s[i].pr)
        {
            prSt[prCnt] = s[i];
            prCnt++;
        }
        else
        {
            regSt[regCnt] = s[i];
            regCnt++;
        }

    for ( int i = 0; i < prCnt - 1; i++)
        for (int j = 0;j < prCnt - 1 - i; j++)
            if (prSt[j].sum < prSt[j + 1].sum)
            {
                Nom_2 mesto = prSt[j];
                prSt[j] = prSt[j + 1];
                prSt[j + 1] = mesto;
            }

    for(int i = 0; i < regCnt - 1; i ++)
        for (int j = 0; j < regCnt - 1 - i; j ++)
            if (regSt[j].sum < regSt[j + 1].sum)
            {
                Nom_2 temp = regSt[j];
                regSt[j] = regSt[j + 1];
                regSt[j + 1] = temp;
            }
    cnt = 0;
    for(int i = 0; i < prCnt; i++)
    {
        list[cnt] = prSt[i];
        cnt++;
    }
    for (int i = 0; i < regCnt; i++)
    {
        list[cnt] = regSt[i];
        cnt++;
    }

}
void res2()
{
    srand(time(0));

    cout << "2.ОЧЕРЕДНОСТЬ В ОБЩЕЖИТИЕ" << endl;
    cout << "Минимальная зарплата (МРОТ): " << min_zarplata << " руб"<< endl;
    cout << "Приоритет имеют студенты с доходом на члена семьи < " << 2 * min_zarplata << " руб" << endl;
    int n = prov("Введите количество студентов (от 1 до 50): ", 1, 50);
    Nom_2 s[max_st];
    Nom_2 list[max_st];
    CrSt(s, n);
    vivod2(s, n, "ИСХОДНЫЙ СПИСОК СТУДЕНТОВ");
    int cnt;
    Pr(s, n, list, cnt);
    vivod2(list, cnt, "ОЧЕРЁДНОСТЬ ПРЕДОСТАВЛЕНИЯ МЕСТ В ОБЩЕЖИТИЕ") ;
    int prCnt = 0;
    for (int i = 0; i < n; i++)
        if (s[i].pr)
            prCnt++;


    cout << "РЕЗУЛЬТАТ" << endl;
    cout << "Всего студентов: " << n << endl;
    cout << "Приоритетных (доход < 2*МРОТ): " << prCnt  << endl;
    cout << "Обычных: " << n - prCnt << endl;
}

