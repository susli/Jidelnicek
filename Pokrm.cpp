#include "Pokrm.hpp"
#include "SeznamJidel.hpp"
#include <iostream>

template <typename Iterator, typename NahodnyGenerator>
Iterator nahodnyVyber(Iterator start, Iterator end, NahodnyGenerator& g)
{
    uniform_int_distribution<> dis(0, distance(start, end) - 1);
    advance(start, dis(g));
    return start;
}

template <typename Iterator> Iterator nahodnyVyber(Iterator start, Iterator end)
{
    static random_device rd;
    static mt19937 gen(rd());
    return nahodnyVyber(start, end, gen);
}

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
    SeznamJidel* seznam;
    if(seznam->seznamJidel.size() >= 15 && seznam->seznamJidel.size() < 25 && pocetGenerovaniJidelnicku == 4) {
    } else if(seznam->seznamJidel.size() < 15 && pocetGenerovaniJidelnicku == 2) {
        seznam->getPouzitePokrmy().clear();
        pocetGenerovaniJidelnicku = 0;
        for(int i = 0; i < seznam->getPouzitePokrmy().size(); ++i) {
            if(seznam->getPouzitePokrmy()[i] == nahodneJidlo->getId()) {
                return false;
            } else {
                return true;
            }
        }
    } else {
        for(int i = 0; i < seznam->getPouzitePokrmy().size(); ++i) {
            if(seznam->getPouzitePokrmy()[i] == nahodneJidlo->getId()) {
                return false;
            } else {
                return true;
            }
        }
    }
    return true;
}

Pokrm* Pokrm::vyberNahodneJidlo()
{
    SeznamJidel* seznam;
    Pokrm* nahodneJidlo = *nahodnyVyber(seznam->getSeznamJidel().begin(), seznam->getSeznamJidel().end());
    return nahodneJidlo;
}