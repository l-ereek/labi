#include "dann.h"
#include <algorithm>  // для sort
#include <cmath>      // для log2

// Генерация случайного массива
void generateRandomArray(vector<int>& arr, int size) {
    arr.clear();
    arr.reserve(size);

    // Генерируем случайные числа от 1 до 1000
    srand(time(nullptr));
    for (int i = 0; i < size; i++) {
        arr.push_back(rand() % 1000 + 1);
    }
}

// Генерация упорядоченного массива (по возрастанию)
void generateSortedArray(vector<int>& arr, int size) {
    arr.clear();
    arr.reserve(size);

    for (int i = 0; i < size; i++) {
        arr.push_back(i * 10 + 1);  // 1, 11, 21, 31, ...
    }
}

// 1. ПОИСК С БАРЬЕРОМ
// Идея: ставим искомый элемент в конец массива, чтобы не проверять выход за границы
int barrierSearch(vector<int>& arr, int key) {
    int n = arr.size();
    int last = arr[n - 1];  // Сохраняем последний элемент

    arr[n - 1] = key;  // Ставим "барьер" - искомый элемент в конец

    int i = 0;
    while (arr[i] != key) {  // Теперь цикл точно закончится
        i++;
    }

    arr[n - 1] = last;  // Восстанавливаем последний элемент

    // Если нашли до последнего элемента или последний элемент был искомым
    if (i < n - 1 || arr[n - 1] == key) {
        return i;  // Возвращаем индекс найденного элемента
    }

    return -1;  // Элемент не найден
}

// 2. БИНАРНЫЙ ПОИСК В УПОРЯДОЧЕННОМ МАССИВЕ
// Идея: делим массив пополам и ищем в нужной половине
int binarySearch(vector<int>& arr, int key) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;  // Находим середину

        if (arr[mid] == key) {
            return mid;  // Нашли элемент
        }
        else if (arr[mid] < key) {
            left = mid + 1;  // Ищем в правой половине
        }
        else {
            right = mid - 1; // Ищем в левой половине
        }
    }

    return -1;  // Элемент не найден
}

// 3. ПОИСК ФАЛЬШИВОЙ МОНЕТЫ (более легкая)
// Алгоритм: делим монеты на 3 группы
int findFakeCoin(const vector<int>& coins, int& weighCount) {
    weighCount = 0;
    int n = coins.size();
    vector<bool> isFake(n, false);  // Для отметки проверенных монет

    // Создаем копию для работы (не изменяем оригинал)
    vector<int> currentCoins = coins;
    vector<int> indices(n);
    for (int i = 0; i < n; i++) {
        indices[i] = i;
    }

    while (indices.size() > 1) {
        weighCount++;
        int m = indices.size();

        // Делим монеты на три группы
        int groupSize = m / 3;

        if (m == 2) {
            // Всего 2 монеты - сравниваем их
            cout << "Взвешивание #" << weighCount << ": сравниваем монеты "
                << indices[0] << " и " << indices[1] << endl;

            if (currentCoins[indices[0]] < currentCoins[indices[1]]) {
                return indices[0];
            }
            else {
                return indices[1];
            }
        }

        // Формируем три группы
        vector<int> group1, group2, group3;

        for (int i = 0; i < groupSize; i++) {
            group1.push_back(indices[i]);
            group2.push_back(indices[i + groupSize]);
        }

        for (int i = 2 * groupSize; i < m; i++) {
            group3.push_back(indices[i]);
        }

        // Вычисляем вес групп
        int weight1 = 0, weight2 = 0;
        for (int idx : group1) weight1 += currentCoins[idx];
        for (int idx : group2) weight2 += currentCoins[idx];

        cout << "Взвешивание #" << weighCount << ": сравниваем группу 1 (";
        for (int idx : group1) cout << idx << " ";
        cout << ") и группу 2 (";
        for (int idx : group2) cout << idx << " ";
        cout << ")" << endl;

        // Определяем, в какой группе фальшивая монета
        if (weight1 == weight2) {
            // Фальшивая монета в третьей группе
            cout << "  Результат: группы равны -> фальшивая монета в третьей группе" << endl;
            indices = group3;
        }
        else if (weight1 < weight2) {
            // Фальшивая монета в первой группе (она легче)
            cout << "  Результат: первая группа легче -> ищем в первой группе" << endl;
            indices = group1;
        }
        else {
            // Фальшивая монета во второй группе (она легче)
            cout << "  Результат: вторая группа легче -> ищем во второй группе" << endl;
            indices = group2;
        }
    }

    return indices[0];
}

// Функция для замера времени выполнения
long long measureTime(int (*searchFunc)(vector<int>&, int), vector<int>& arr, int key) {
    auto start = chrono::high_resolution_clock::now();

    // Выполняем поиск 10000 раз для точности замера
    for (int i = 0; i < 10000; i++) {
        searchFunc(arr, key);
    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    return duration.count() / 10000;  // Возвращаем среднее время одного поиска
}