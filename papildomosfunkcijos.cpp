#include "Funkcijos.h"
#include "libraries.h"


data::data()
{
    exam = 0;
    vidurkis = 0;
    mediana = 0;
    CorrectData = true;
}

void data::setname(std::string x) {
    name = x;
}
std::string data::getname()const {
    return name;
}


void data::setsurn(std::string x) {
    surn = x;
}
std::string data::getsurn()const {
    return surn;
}


void data::set_exam(int exam_mark) {
    exam = exam_mark;
}
int data::get_exam()const {
    return exam;
}


void data::set_mark(double mark) {
    marks.push_back(mark);
}

int data::get_mark(int a) {
    return marks[a];
}

void data::ClearMark() {
    marks.clear();
}

bool data::setCorrectData(bool x)
{
    CorrectData = x;
}
bool data::getCorrectData()
{
    return CorrectData;
}

double data::getvidurkis()const {
    return vidurkis;
}
double data::getmediana()const {
    return mediana;
}




double data::Skaiciuojam_vidurkis()
{
    double s = 0, avr = 0;

    for (int i = 0; i < marks.size(); i++)
    {
        s = s + marks[i];
    }

    avr = s / marks.size();
    vidurkis = 0.4 * avr + 0.6 * exam;
}


double data::Skaiciuojam_mediana()
{
    std::sort(marks.begin(), marks.end());  //sorting an array in ascending order

    double s = 0;
    if (marks.size() % 2 == 0)
    {
        s = (double)((marks[marks.size() / 2] + marks[marks.size() / 2]) / 2);
    }
    else
    {
        s = (double)marks[marks.size() / 2];
    }
    mediana = 0.4 * s + 0.6 * exam;
}


bool Lyginam_pagal_varda(const data& a, const data& b)
{
    return a.getname() < b.getsurn();
}

bool Lyginam_pagal_rezultatus(const data& a, const data& b)
{
    return a.getvidurkis() > b.getvidurkis();
}

bool Skirstom(data& a)
{
    return (a.getvidurkis() >= 5);
}

