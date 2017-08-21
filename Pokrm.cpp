#include "Pokrm.hpp"
#include "SeznamJidel.hpp"
#include <iostream>

int Pokrm::getId()
{
    return id;
}

string Pokrm::getNazev()
{
    return nazev;
}
int Pokrm::getCena()
{
    return cena;
}

int Pokrm::getTrida()
{
    return trida;
}

string Pokrm::getIngredience()
{
    return ingredience;
}
int Pokrm::getObjem()
{
    return nic;
}

void Pokrm::vypis()
{
    cout << "Id: " << id << "    "
         << "Nazev Jidla: " << nazev << "   "
         << "Cena: " << cena << "   "
         << "Trida: " << trida << "   ";
    //       << "Ingredience: " << "--------" << " ";
}

bool Pokrm::kontrolaPokrmu(Pokrm* nahodneJidlo)
{
    if(seznamJidel.size() >= 15 && seznamJidel.size() < 25 && pocetGenerovaniJidelnicku == 4) {
        // goto provedGenerovani;
    } else if(seznamJidel.size() < 15 && pocetGenerovaniJidelnicku == 2) {
        // provedGenerovani:
        pouzitePokrmy.clear();
        pocetGenerovaniJidelnicku = 0;

        for(int i = 0; i < pouzitePokrmy.size(); ++i) {
            if(pouzitePokrmy[i] == nahodneJidlo->getId()) {
                return false;

            } else {
                return true;
            }
        }
    }

    else {

        for(int i = 0; i < pouzitePokrmy.size(); ++i) {
            if(pouzitePokrmy[i] == nahodneJidlo->getId()) {
                return false;
            } else {
                return true;
            }
        }
    }

    return true;
}