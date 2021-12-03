
#include "Funkcijos.h"
#include "libraries.h"


std::string ListNR;

void Studentu_grupes(list <data>& sze)
{
    sze.sort(Lyginam_pagal_rezultatus);
    //std::sort(A.begin(), A.end(), Compare_by_Results);

    list <data>::iterator it = std::stable_partition(sze.begin(), sze.end(), Skirstom);
    list <data> nuskriausti(it, sze.end());
    sze.erase(it, sze.end());

    std::ofstream write1("sarasas/studentai.txt");
    std::ofstream write2("sarasas/nuskriausti.txt");

    int num = 15;
    int num2 = 20;
    int num3 = 5;

    write1 << left << setfill(' ') << setw(num) << "Vardas";
    write1 << left << setfill(' ') << setw(num) << "Pavarde";
    write1 << left << setfill(' ') << setw(num2) << "vidurkis";
    write1 << left << setfill(' ') << setw(num2) << "mediana" << endl;

    write2 << left << setfill(' ') << setw(num) << "Vardas";
    write2 << left << setfill(' ') << setw(num) << "Pavarde";
    write2 << left << setfill(' ') << setw(num2) << "vidurkis";
    write2 << left << setfill(' ') << setw(num2) << "mediana" << endl;

    const std::string bruksnys(num * 4 + num3 * 5 + 14, '_');
    write1 << bruksnys << endl;
    write2 << bruksnys << endl;

    for (auto& u : sze)
    {
        write1 << left << setfill(' ') << setw(num) << u.getname();
        write1 << left << setfill(' ') << setw(num) << u.getsurn();
        write1 << left << setfill(' ') << setw(num2) << std::setprecision(2) << u.getvidurkis();
        write1 << left << setfill(' ') << setw(num2) << std::setprecision(2) << u.getmediana();
        write1 << endl;
    }


    for (auto& i : nuskriausti)
    {
        write2 << left << setfill(' ') << setw(num) << i.getname();
        write2 << left << setfill(' ') << setw(num) << i.getsurn();
        write2 << left << setfill(' ') << setw(num2) << std::setprecision(2) << i.getvidurkis();
        write2 << left << setfill(' ') << setw(num2) << std::setprecision(2) << i.getmediana();
        write2 << endl;
    }

    write1.close();
    write2.close();

    cout << endl;
}



void Skaitom_faila(list <data>& sze)
{
    string name;
    string surn;
    int mark;
    int exam;

    std::ifstream read("sarasas/studentai.txt");

    if (!read)
    {
        cout << "Cannot open the File!" << endl;
    }

    data z;

    while (!read.eof())
    {
        z.ClearMark();

        read >> name;
        z.setname(name);

        read >> surn;
        z.setsurn(surn);

        for (int j = 1; j <= 5; j++)
        {
            read >> mark;
            z.set_mark(mark);
        }

        read >> exam;
        z.set_exam(exam);


        z.Skaiciuojam_mediana();
        z.Skaiciuojam_vidurkis();
        sze.push_back(z);
    }

    sze.pop_back();
    read.close();
}

void Generuojam_sarasa(int StudSK)
{
    std::srand(std::time(NULL));
    int NR;
    cout << "kiek studentu noretumete sugeneruoti" << endl;
    cin >> NR;

    struct stat st;
    if (stat("/sarasas", &st) != 0)
    {
        const int dir_err = mkdir("/sarasas");
        if (-1 == dir_err)
        {
            printf("Error creating directory!n");
            exit(1);
        }
    }

    while (true)
    {
        std::string t = std::to_string(NR);

        std::ifstream check("sarasas/studentai.txt");
        if (check)
        {
            check.close();
            NR++;
        }
        if (!check)
        {
            check.close();
            break;
        }
    }

    string k = std::to_string(NR);
    string h = "sarasas/studentai" + k;
    char const* ca = h.c_str();
    const int fullDir = mkdir(ca);

    std::ofstream write("sarasas/studentai.txt");

    int num = 15; int num2 = 20; int num3 = 5;

    write << left << setfill(' ') << setw(num) << "Pavarde";
    write << left << setfill(' ') << setw(num) << "Vardas";
    write << left << setfill(' ') << setw(num3) << "ND1";
    write << left << setfill(' ') << setw(num3) << "ND2";
    write << left << setfill(' ') << setw(num3) << "ND3";
    write << left << setfill(' ') << setw(num3) << "ND4";
    write << left << setfill(' ') << setw(num3) << "ND5";
    write << left << setfill(' ') << setw(8) << "EGZ" << endl;

    const std::string bruksnys(num * 2 + num3 * 5 + 3.5, '_');
    write << bruksnys;

    for (int i = 0; i < StudSK; i++)
    {
        write << endl;
        std::string sk = std::to_string(i + 1);

        std::string vardas = "Vardas" + sk;
        std::string pavarde = "Pavarde" + sk;

        write << left << setfill(' ') << setw(num) << vardas;
        write << left << setfill(' ') << setw(num) << pavarde;

        for (int j = 0; j < 5; j++)
        {
            write << left << setfill(' ') << setw(num3) << rand() % 10 + 1;
        }

        write << std::fixed;
        write << left << setfill(' ') << setw(8) << rand() % 10 + 1;
    }
    write.close();
}