#include "Funkcijos.h"
#include "libraries.h"



void Studentu_grupes(list <data>& sze)
{
    auto start = std::chrono::high_resolution_clock::now();
    auto st = start;

    list<data> nuskriausti;
    list <data> kietiakai;

    for (auto& l : sze)
    {


        if (l.getVidurkis() >= 5) kietiakai.push_back(l);
        else if (l.getVidurkis() < 5) nuskriausti.push_back(l);
    }

    nuskriausti.sort(Lyginam_pagal_rezultatus);
    kietiakai.sort(Lyginam_pagal_rezultatus);

    std::ofstream write1("sarasas/kietiakai.txt");
    std::ofstream write2("sarasas/nuskriausti.txt");

    int num = 15;
    int num2 = 20;
    int num3 = 5;

    write1 << left << setfill(' ') << setw(num) << "Pavarde";
    write1 << left << setfill(' ') << setw(num) << "Vardas";
    write1 << left << setfill(' ') << setw(num2) << "vidurkis";
    write1 << left << setfill(' ') << setw(num2) << "mediana" << endl;

    write2 << left << setfill(' ') << setw(num) << "Pavarde";
    write2 << left << setfill(' ') << setw(num) << "Vardas";
    write2 << left << setfill(' ') << setw(num2) << "vidurkis";
    write2 << left << setfill(' ') << setw(num2) << "mediana" << endl;

    const std::string bruksnys(num * 4 + num3 * 5 + 14, '_');
    write1 << bruksnys << endl;
    write2 << bruksnys << endl;

    for (auto& u : kietiakai)
    {
        write1 << left << setfill(' ') << setw(num) << u.getName();
        write1 << left << setfill(' ') << setw(num) << u.getSurname();
        write1 << left << setfill(' ') << setw(num2) << std::setprecision(2) << u.getVidurkis();
        write1 << left << setfill(' ') << setw(num2) << std::setprecision(2) << u.getMediana();
        write1 << endl;
    }


    for (auto& i : nuskriausti)
    {
        write2 << left << setfill(' ') << setw(num) << i.getName();
        write2 << left << setfill(' ') << setw(num) << i.getSurname();
        write2 << left << setfill(' ') << setw(num2) << std::setprecision(2) << i.getVidurkis();
        write2 << left << setfill(' ') << setw(num2) << std::setprecision(2) << i.getMediana();
        write2 << endl;
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Failo rusiavimas ir isvedimas i dvi grupes su (list) uztruko : " << diff.count() << " s\n";



    write1.close();
    write2.close();

    kietiakai.clear();
    nuskriausti.clear();

}


void  Skaitom_faila(list <data>& sze)
{
    string Name;
    string Surname;
    int pazymys;
    int exam;


    std::ifstream read("sarasas/studentai100000.txt");

    if (!read)
    {
        cout << "Negalime atidaryti failo!" << endl;
    }

    read.ignore(std::numeric_limits<std::streamsize>::max(), read.widen('\n'));
    read.ignore(std::numeric_limits<std::streamsize>::max(), read.widen('\n'));

    int inputNd;
    data z;


    while (!read.eof())
    {
        z.Clearmarks();
        read >> Name;
        z.setName(Name);

        read >> Surname;
        z.setSurname(Surname);

        for (int j = 1; j <= 5; j++)
        {
            read >> pazymys;
            z.set_mark(pazymys);
        }
        read >> exam;
        z.set_exam(exam);

        z.Skaiciuojam_Vidurki();
        z.Skaiciuojam_Mediana();
        sze.push_back(z);
    }


    sze.pop_back();
    read.close();
}

void Generuojam_Sarasa()
{
    std::srand(std::time(NULL));

    int NR;
    std::cout << "iveskite, kiek studentu noretumete sugeneruoti(1000, 10 000, 100 000, 1 000 000, 10 000 000):" << std::endl;
    std::cin >> NR;

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

    for (int i = 0; i < NR; i++)
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



void Input(list <data>& sze)
{
    std::ifstream read("studentai10000.txt");

    if (!read)
    {
        cout << "Negalima atidaryti failo! Isitikinkite, kad failas uzvadintas teisinkai studentai.txt " << endl;
    }

    string Name;
    string Surname;
    int exam;
    double Vidurkis;
    double Mediana;
    int pazymys;

    data z;

    while (!read.eof())
    {
        z.Clearmarks();

        read >> Name;
        z.setName(Name);
        read >> Surname;
        z.setSurname(Surname);

        bool CorrectND = true;
        bool CorrectEGZ = true;

        for (int j = 1; j <= 5; j++)
        {
            read >> pazymys;
            if (read.fail())
            {
                read.clear();
                read.ignore(256, ' ');
                pazymys = 1;
                CorrectND = false;
            }
            else if (pazymys <= 0 || pazymys > 10) CorrectND = false;

            z.set_mark(pazymys);
        }
        read >> exam;
        z.set_exam(exam);

        if (read.fail())
        {
            read.clear();
            read.ignore(256, ' ');
            z.set_exam(1);
            CorrectEGZ = false;
        }
        else if (z.get_exam() <= 0 || z.get_exam() > 10)
        {
            CorrectEGZ = false;
        }
        else CorrectEGZ = true;

       

        if (CorrectEGZ == false || CorrectND == false) z.setCorrectData(false);
        else z.setCorrectData(true);

        z.Skaiciuojam_Vidurki();
        z.Skaiciuojam_Mediana();

        sze.push_back(z);
    }
    read.close();
    isprintinam_data(sze);
}

void Output(list <data>& sze)
{
   
  
    list <data> studenciokai;
   studenciokai.sort(Lyginam_pagal_rezultatus);
   

    std::ofstream write1("kursiokai.txt");
  

    int num = 15;
    int num2 = 20;
    int num3 = 5;

    write1 << left << setfill(' ') << setw(num) << "Pavarde";
    write1 << left << setfill(' ') << setw(num) << "Vardas";
    write1 << left << setfill(' ') << setw(num2) << "vidurkis";
    write1 << left << setfill(' ') << setw(num2) << "mediana" << endl;

    const std::string bruksnys(num * 4 + num3 * 5 + 14, '_');
    write1 << bruksnys << endl;
    for (auto& u : studenciokai)
    {
        write1 << left << setfill(' ') << setw(num) << u.getName();
        write1 << left << setfill(' ') << setw(num) << u.getSurname();
        write1 << left << setfill(' ') << setw(num2) << std::setprecision(2) << u.getVidurkis();
        write1 << left << setfill(' ') << setw(num2) << std::setprecision(2) << u.getMediana();
        write1 << endl;
    }

    write1.close();

}




void isprintinam_data(list <data> sze)
{
    int num = 0; int num2 = 20; bool co = true;
    num = GetLongestString(sze) + 7;

    sze.sort(Lyginam_pagal_varda);
    //std::sort(A.begin(), A.end(), Compare_by_FirstName);

    cout << endl;
    cout << left << setfill(' ') << setw(num) << "Pavarde";
    cout << left << setfill(' ') << setw(num) << "Vardas";
    cout << left << setfill(' ') << setw(num2) << "Galutinis (Vid.)";
    cout << left << setfill(' ') << setw(num2) << "Galutinis (Med.)" << endl;

    const std::string bruksnys(num + num + 20 + 17, '_');
    cout << bruksnys << endl;
    for (auto& i : sze)
    {
        cout << left << setfill(' ') << setw(num) << i.getName();
        cout << left << setfill(' ') << setw(num) << i.getSurname();
        cout << left << setfill(' ') << setw(num2) << std::setprecision(2) << i.getVidurkis();
        cout << left << setfill(' ') << setw(num2) << std::setprecision(2) << i.getMediana();
        cout << endl;
    }
}


void Ivedimas(list <data>& sze)
{

    int Sk;

    data z;

    string Name;
    string Surname;
    int pazymys;
    int exam;

    cout << "Iveskite mokiniu skaiciu: ";
    cin >> Sk;
    cout << endl;


    for (int i = 1; i <= Sk; i++)
    {
        z.Clearmarks();

        cout << "Iveskite " << i << "-ojo mokinio duomenis" << endl;

        cout << "Vardas: ";
        cin >> Name;
        z.setName(Name);

        cout << "Pavarde: ";
        cin >> Surname;
        z.setSurname(Surname);
        cout << endl;

        cout << "Pradekite vesti mokinio pazymius. Kai baigsite iveskite 0. " << endl;
        int j = 1;

        while (true)
        {
            cout << j << "-uju namu darbu rezultatas: ";
            cin >> pazymys;

            if (pazymys == 0) break;
            else
            {
                z.set_mark(pazymys);
                j++;
            }
        }

        cout << "Egzamino rezultatai: ";
        cin >> exam;
        z.set_exam(exam);
        cout << endl;

       

        z.Skaiciuojam_Vidurki();
        z.Skaiciuojam_Mediana();

       

        cout << endl;
        cout << endl;
        sze.push_back(z);
    }

    isprintinam_data(sze);
}
