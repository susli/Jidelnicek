#include "Pokrm.hpp"
#include "SeznamJidel.hpp"
#include <iostream>
#include <ctime>     // std::time
#include <cstdlib>   // std::rand, std::srand
#include <algorithm> // std::random_shuffle
#include <iterator>

SeznamJidel* seJidel;

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
    cout << "Id: " << Pokrm::getId() << "    "
         << "Nazev Jidla: " << Pokrm::getNazev() << "   "
         << "Cena: " << Pokrm::getCena() << "   "
         << "Trida: " << Pokrm::getTrida() << "   ";
}

bool Pokrm::kontrolaPokrmu(Pokrm* nahodneJidlo)
{
        for(int i = 0; i < seJidel->getPouzitePokrmy().size(); ++i) {
            
            if(seJidel->getPouzitePokrmy()[i] != nahodneJidlo->getId()) {
                return true;
            } else {
                return false;
            }
            
        }
    
    
    //return true;
}

/*
Pokrm* Pokrm::vyberNahodneJidlo()
{
    // SeznamJidel* seznam;
    //Pokrm* nahodneJidlo = seJidel->getSeznamJidel()[1];
    Pokrm* nahodneJidlo = *nahodnyVyber(seJidel->getSeznamJidel().begin(), seJidel->getSeznamJidel().end());
    return nahodneJidlo;
}
*/
