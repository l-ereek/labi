#include "dann.h"

void printArray(const vector<int>& arr, int maxDisplay = 20) {
    cout << "[";
    int displayCount = min((int)arr.size(), maxDisplay);
    for (int i = 0; i < displayCount; i++) {
        cout << arr[i];
        if (i < displayCount - 1) cout << ", ";
    }
    if (arr.size() > maxDisplay) cout << ", ...";
    cout << "] (размер: " << arr.size() << ")" << endl;
}

void demonstrateBarrierSearch() {
    cout << "\n========== 1. ПОИСК С БАРЬЕРОМ ==========" << endl;

    vector<int> arr;
    generateRandomArray(arr, 10);  // Создаем небольшой массив для демонстрации

    cout << "Массив: ";
    printArray(arr);

    int searchKey = arr[5];  // Ищем элемент, который точно есть в массиве
    cout << "\nИщем элемент: " << searchKey << " (находится на позиции 5)" << endl;

    int index = barrierSearch(arr, searchKey);
    cout << "Результат поиска с барьером: элемент найден на индексе " << index << endl;

    // Ищем несуществующий элемент
    searchKey = 9999;
    cout << "\nИщем элемент: " << searchKey << " (которого нет в массиве)" << endl;
    index = barrierSearch(arr, searchKey);
    cout << "Результат поиска с барьером: " << (index == -1 ? "не найден" : "найден") << endl;
}

void demonstrateBinarySearch() {
    cout << "\n========== 2. БИНАРНЫЙ ПОИСК ==========" << endl;

    vector<int> arr;
    generateSortedArray(arr, 15);

    cout << "Упорядоченный массив: ";
    printArray(arr);

    int searchKey = 51;  // 51 = 5*10 + 1, должно быть на позиции 5
    cout << "\nИщем элемент: " << searchKey << endl;

    int index = binarySearch(arr, searchKey);
    cout << "Результат бинарного поиска: элемент найден на индексе " << index << endl;

    // Ищем несуществующий элемент
    searchKey = 100;
    cout << "\nИщем элемент: " << searchKey << " (которого нет в массиве)" << endl;
    index = binarySearch(arr, searchKey);
    cout << "Результат бинарного поиска: " << (index == -1 ? "не найден" : "найден") << endl;
}

void demonstrateFakeCoinSearch() {
    cout << "\n========== 3. ПОИСК ФАЛЬШИВОЙ МОНЕТЫ ==========" << endl;

    // Создаем массив монет (вес нормальных монет = 10, фальшивой = 9)
    vector<int> coins(27, 10);  // 27 монет весом 10
    int fakePos = rand() % 27;  // Случайная позиция фальшивой монеты
    coins[fakePos] = 9;

    cout << "Всего монет: " << coins.size() << endl;
    cout << "Фальшивая монета (более легкая) находится на позиции " << fakePos << endl;
    cout << "\nНачинаем поиск:\n" << endl;

    int weighCount = 0;
    int foundFake = findFakeCoin(coins, weighCount);

    cout << "\nРезультат:" << endl;
    cout << "Фальшивая монета найдена на позиции " << foundFake << endl;
    cout << "Всего потребовалось взвешиваний: " << weighCount << endl;

    if (foundFake == fakePos) {
        cout << "✓ Поиск выполнен успешно!" << endl;
    }
    else {
        cout << "✗ Ошибка! Найдена не та монета." << endl;
    }
}

void compareEfficiency() {
    cout << "\n========== СРАВНЕНИЕ ЭФФЕКТИВНОСТИ ==========" << endl;

    vector<int> sizes = { 100, 1000, 10000, 50000, 100000 };

    cout << left << setw(12) << "Размер"
        << setw(25) << "Поиск с барьером (мкс)"
        << setw(25) << "Бинарный поиск (мкс)"
        << "Теоретическая сложность" << endl;
    cout << string(80, '-') << endl;

    for (int size : sizes) {
        // Создаем два одинаковых массива (один неупорядоченный, другой упорядоченный)
        vector<int> randomArr, sortedArr;
        generateRandomArray(randomArr, size);

        // Для упорядоченного массива сортируем случайный
        sortedArr = randomArr;
        sort(sortedArr.begin(), sortedArr.end());

        // Ищем элемент, который гарантированно есть в массиве
        int searchKey = randomArr[size / 2];

        // Замеряем время для каждого алгоритма
        long long timeBarrier = measureTime(barrierSearch, randomArr, searchKey);
        long long timeBinary = measureTime(binarySearch, sortedArr, searchKey);

        // Выводим результаты
        cout << left << setw(12) << size
            << setw(25) << timeBarrier
            << setw(25) << timeBinary;

        if (size <= 10000) {
            cout << "Барьерный: O(n), Бинарный: O(log n)";
        }
        else {
            cout << "Бинарный поиск значительно быстрее";
        }
        cout << endl;
    }

    cout << "\nОбъяснение эффективности:" << endl;
    cout << "1. Поиск с барьером - сложность O(n)" << endl;
    cout << "   - В худшем случае просматривает все элементы" << endl;
    cout << "   - Преимущество: не проверяет границы массива" << endl;
    cout << "   - Не требует упорядоченности массива" << endl;
    cout << endl;
    cout << "2. Бинарный поиск - сложность O(log n)" << endl;
    cout << "   - Экспоненциально быстрее для больших массивов" << endl;
    cout << "   - Недостаток: требует предварительной сортировки" << endl;
    cout << endl;
    cout << "3. Поиск фальшивой монеты - сложность O(log₃ n)" << endl;
    cout << "   - Оптимальный алгоритм для задачи взвешивания" << endl;
    cout << "   - Позволяет найти фальшивую монету за минимальное число взвешиваний" << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "ПРОГРАММА ДЛЯ ДЕМОНСТРАЦИИ АЛГОРИТМОВ ПОИСКА" << endl;
    cout << "=============================================" << endl;

    // Демонстрация работы каждого алгоритма
    demonstrateBarrierSearch();
    demonstrateBinarySearch();
    demonstrateFakeCoinSearch();

    // Сравнение эффективности
    compareEfficiency();

    cout << "\nНажмите Enter для завершения...";
    cin.get();

    return 0;
}