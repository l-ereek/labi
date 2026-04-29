#ifndef PROJECT_H
#define PROJECT_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

const double min_zarplata = 12000.0;
const int max_st = 50;


struct Nom_1
{
	string facultet;
	int d2023, d2024,d2025, sum;
};

struct Nom_2
{
	string fuo, gr;
	double sum, d;
	bool pr;
};


void chistka();
int prov(const string& str, int min, int max);
double provD(const string& str, double min, double max);
string getString(const string& str);
void Menu();

void CrF(Nom_1 f[], int n);
void vivod1(const Nom_1 f[], int n);
void MinMax(const Nom_1 f[], int n, string& minF, string& maxF, int& minS, int& maxS);
void res1();


void CrSt(Nom_2 s[], int n);
void vivod2(const Nom_2 s[], int n, const string str);
void Pr(const Nom_2 s[], int n, Nom_2 list[], int& cnt);
void res2();

#endif



