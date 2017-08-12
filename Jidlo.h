#ifndef JIDLO_H
#define JIDLO_H
#include <string>
#include <sstream>
#include <iostream>
#include <Pokrm.h>

using namespace std;

class Jidlo : public Pokrm
{
public:
    Jidlo(int id, string nazev, int cena, int trida)
    {
        this->id = id;
        this->nazev = nazev;
        this->cena = cena;
        this->trida = trida;
    }
};

#endif // JIDLO_H
