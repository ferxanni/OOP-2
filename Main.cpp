#include "Funkcijos.h"
#include "libraries.h"


int main()

{



   

    list<data> sze;

    std::cout << "Pasirinkite!" << std::endl;

    std::cout << "1. Noriu ikelti studentu duomenis is failo" << std::endl;

    std::cout << "2. Noriu ivesti studentu duomenis pats" << std::endl;
    std::cout << "3. Noriu generuoti studentu faila automatiskai" << std::endl;
    std::cout << "Jusu pasirinkimas:\n" << std::endl;


    std::string choice;
    std::cin >> choice;

    do

    {

        if (choice == "1")

        {
            
            Input(sze);           
            
          

        }

        else if (choice == "2")

        {
           
            Ivedimas(sze);
           
        }

        else if (choice == "3")
        {

            char repeat;
            do           {
                
                Generuojam_Sarasa();      
                
                Skaitom_faila(sze);
                Studentu_grupes(sze); 
                

                cout << "Jeigu norite generuoti nauja sarasa spauskite N \n";
                std::cin >> repeat;

            } while (repeat == 'N');


        }
      
    } while (choice != "1" && choice != "2" && choice != "3");


    return 0;
}