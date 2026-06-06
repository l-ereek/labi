#ifndef DANN_H
#define DANN_H

#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <algorithm>

using namespace std;

// Функция для генерации случайного массива
void generateRandomArray(vector<int>& arr, int size);

// Функция для генерации упорядоченного массива
void generateSortedArray(vector<int>& arr, int size);

// 1. Поиск с барьером в неупорядоченном массиве
int barrierSearch(vector<int>& arr, int key);

// 2. Бинарный поиск в упорядоченном массиве
int binarySearch(vector<int>& arr, int key);

// 3. Поиск фальшивой монеты (задача на взвешивание)
int findFakeCoin(const vector<int>& coins, int& weighCount);

// Функция для замера времени выполнения
long long measureTime(int (*searchFunc)(vector<int>&, int), vector<int>& arr, int key);

#endif