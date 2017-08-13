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
    Jidlo(int id, string nazev, int cena, int trida, string ingredience)
    {
        this->id = id;
        this->nazev = nazev;
        this->cena = cena;
        this->trida = trida;
        this->ingredience = ingredience;
    }
};

#endif // JIDLO_H
