#ifndef FILE_TASKS_H
#define FILE_TASKS_H

#include "task1.cpp"
#include "task2.cpp"

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <set>



using namespace std;
const string Nom1_Input_FileName = "text.txt", Nom1_Output_FileName = "res.txt";
const string Nom2_Input_FileName = "F.txt", Nom2_Output_FileName = "G.txt";

bool Prov(const string& failename);
string Read(const string& failename);
string Perebor(const string& text);
void vivod1(const string& inputF, const string& outputF);

void Chistka();
bool PodStr(const string& filename, const string& podstr);
void FvG(const string& inputF, const string outputF, const string& podstr);
bool Vopros();
string VvodPodstr();

#endif