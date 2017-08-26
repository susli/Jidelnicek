#pragma once
#ifndef JIDELNICEK_H
#define JIDELNICEK_H
#include <vector>
#include <Jidlo.hpp>
#include <iostream>

using namespace std;

class Jidelnicek
{

public:
    vector<Pokrm*> pondeli;
    vector<Pokrm*> utery;
    vector<Pokrm*> streda;
    vector<Pokrm*> ctvrtek;
    vector<Pokrm*> patek;


int pocetGenerovaniJidelnicku = 0;
    vypis();

    vector<Pokrm*> generujJidelnicekproDen();
    void generujJidelnicek();
    void vytiskniJidelnicek();
    vector<Pokrm*> vytvorJidelnicekProDen();
    void vytvorJidelnicek();
    void vypisJidelnicek();
};

#endif // JIDELNICEK_H
