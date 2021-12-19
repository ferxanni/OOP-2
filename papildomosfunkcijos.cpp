
#include "Funkcijos.h"
#include "libraries.h"

data::data()
{
    exam = 0;
    Vidurkis = 0;
    Mediana = 0;
    CorrectData = true;
}


void data::setName(std::string x) {
    Name = x;
}
std::string data::getName()const {
    return Name;
}


void data::setSurname(std::string x) {
    Surname = x;
}
std::string data::getSurname()const {
    return Surname;
}


void data::set_exam(int exam_mark) {
    exam = exam_mark;
}
int data::get_exam()const {
    return exam;
}

void data::set_StudSk(int sk) {
    StudSk = sk;
}
int data::get_StudSk()const {
    return StudSk;
}


void data::set_mark(double mark) {
    marks.push_back(mark);
}

int data::get_mark(int a) {
    return marks[a];
}

void data::Clearmarks() {
    marks.clear();
}

bool data::setCorrectData(bool x)
{
    return CorrectData = x;
}
bool data::getCorrectData()
{
    return CorrectData;
}

double data::getVidurkis()const {
    return Vidurkis;
}
double data::getMediana()const {
    return Mediana;
}

 
double data::Skaiciuojam_Vidurki()
{
    double s = 0, avr = 0;

    for (int i = 0; i < marks.size(); i++)
    {
        s = s + marks[i];
    }

    avr = s / marks.size();
    return Vidurkis = 0.4 * avr + 0.6 * exam;
}

double data::Skaiciuojam_Mediana()
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
   return Mediana = 0.4 * s + 0.6 * exam;
}

bool Lyginam_pagal_varda(const data& a, const data& b)
{
    return a.getName() < b.getSurname();
}

bool Lyginam_pagal_rezultatus(const data& a, const data& b)
{
    return a.getVidurkis() > b.getVidurkis();
}

bool Skirstom(data& a)
{
    return (a.getVidurkis() >= 5);
}

int randomMark()
{
    srand(time(0));


    for (int i = 0; i < 10; i++)
        return (rand() % 10) + 1;
}


int GetLongestString(list <data>& sze)
{
    int ln = 0, max = 0;
    for (auto& i : sze)
    {
        ln = i.getName().size();
        if (ln > max) max = ln;
    }
    for (auto& i : sze)
    {
        ln = i.getSurname().size();
        if (ln > max) max = ln;
    }
    return max;
}

unsigned int wordsinstring(std::string const& str)
{
    std::stringstream stream(str);
    return std::distance(std::istream_iterator<std::string>(stream), std::istream_iterator<std::string>());
}