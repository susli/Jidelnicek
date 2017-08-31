#pragma once
#ifndef NAPOJ_H
#define NAPOJ_H
#include <Jidlo.hpp>
#include <Pokrm.hpp>

using namespace std;

class Napoj : public Jidlo
{
    int objem;

public:
    Napoj(int id, string nazev, double cena, int trida, string ingredience, int objem)
        : Jidlo(id, nazev, cena, trida, ingredience)
        , objem(objem){}; // inline definice - prazdne telo metody, zakoncene strednikem

    ~Napoj();

    int getId();
    string getNazev();
    double getCena();
    int getTrida();
    string getIngredience();
    int getObjem();
    virtual void vypis();
    void vypisNapoj();
};

#endif // NAPOJ_H