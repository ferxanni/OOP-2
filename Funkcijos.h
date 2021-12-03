#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "libraries.h"


#include <iostream>
#include <vector>
#include <algorithm>

class data
{
private:
    std::string name;
    std::string surn;
    std::vector <int> marks;
    int exam;
    double vidurkis;
    double mediana;
    bool CorrectData;

public:
    data();

    void setname(std::string x);
    std::string getname()const;

    void setsurn(std::string x);
    std::string getsurn()const;

    void set_exam(int exam_mark);
    int get_exam()const;

    void set_mark(double mark);
    int get_mark(int a);
    void ClearMark();

    double getvidurkis()const;
    double getmediana()const;

    double Skaiciuojam_vidurkis();
    double Skaiciuojam_mediana();

    bool setCorrectData(bool x);
    bool getCorrectData();

};

bool Lyginam_pagal_rezultatus(const data& a, const data& b);
bool Lyginam_pagal_varda(const data& a, const data& b);
bool Skirstom(data& a);
void Studentu_grupes(list <data>& sze);
void Skaitom_faila(list <data>& sze);
void Generuojam_sarasa(int StudSK);
// int GetLongestString(list <student>& A);


#endif
