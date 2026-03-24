//#include <iostream>
//#include <string>
//
//int main()
//{
//    using namespace std;
//    setlocale(LC_ALL, "RU");
//    char st[1000];
//    int cnt = 0;
//    bool w = false;
//    while (true)
//    {
//        cout << "Введите предложение: ";
//        cin.getline(st, 1000);
//        if (strlen(st) == 0)
//        {
//            cout << "Ошибка! Предложение не может быть пустым!" << endl;
//            continue;
//        }
//
//        break;
//    }
//
//    for (int i = 0; st[i] != '\0'; i++)
//    {
//        if (st[i] == ' ' || st[i] == ',' || st[i] == ';' || st[i] == '.')
//            w = false;
//        else
//            if (!w)
//            {
//                cnt++;
//                w = true; 
//            }
//    }
//
//    cout << "Количество слов в предложении: " << cnt << endl;
//}