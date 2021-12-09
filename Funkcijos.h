#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H
#include "libraries.h"

class data
{
private:
    std::string Name;
    std::string Surname;
    int exam;
    vector <int> marks;
    bool CorrectData = true;
    double Total = 0;
    double Vidurkis;
    double Mediana;
    int StudSk;


public:
    data();

    void setName(std::string x);
    std::string getName()const;

    void setSurname(std::string x);
    std::string getSurname()const;

    void set_exam(int exam_mark);
    int get_exam()const;

    void set_StudSk(int sk);
    int get_StudSk()const;

    void set_mark(double mark);
    int get_mark(int a);
    void Clearmarks();

    double getVidurkis()const;
    double getMediana()const;

    double Skaiciuojam_Vidurki();
    double Skaiciuojam_Mediana();

    bool setCorrectData(bool x);
    bool getCorrectData();


   

};



bool Skirstom(const data& a);
void Studentu_grupes(list <data>& sze);
void  Skaitom_faila(list <data>& sze);
void Generuojam_Sarasa();



bool Lyginam_pagal_rezultatus(const data& a, const data& b);
bool Lyginam_pagal_varda(const data& a, const data& b);

int GetLongestString(list <data>& sze);
unsigned int wordsinstring(std::string const& str);




int randomMark();

void Input(list <data>& sze);
void Output(list <data>& sze);

void isprintinam_data(list <data> sze);
void Ivedimas(list <data>& sze);



#endif
