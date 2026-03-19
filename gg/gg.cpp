//#include <iostream>
//#include <string>
//
//int main()
//{
//    using namespace std;
// 
//    string st;
//    int cnt = 0;
//    cout << "Введите предложение: ";
//    getline(cin, st);
//    bool inWord = false;
//    for (char c : st)
//    {
//        if (c == ' ' || c == ':' || c == ';')
//        {
//            inWord = false;
//        }
//        else if (!inWord)
//        {
//            cnt++;
//            inWord = true;
//        }
//    }
//
//    cout << "Количество слов в предложении: " << cnt << endl;
//
//    return 0;
//}