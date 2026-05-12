#ifndef DANN_H
#define DANN_H

#include <iostream>
#include <string>
#include <fstream>
#include <set>

using namespace std;


const string Nom1_Input_FileName = "text.txt";
const string Nom1_Output_FileName = "res.txt";
const string Nom2_Input_FileName = "F.txt";
const string Nom2_Output_FileName = "G.txt";

bool Prov(const string& filename);
string Read(const string& filename);
string Perebor(const string& text);
void vivod1(const string& inputF, const string& outputF);

void Chistka();
bool PodStr(const string& filename, const string& podstr);
void FvG(const string& inputF, const string& outputF, const string& podstr);
bool Vopros();
string VvodPodstr();

#endif