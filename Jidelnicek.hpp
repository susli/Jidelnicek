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

    vypis();
    vector<Pokrm*> generujJidelnicekProDen();
    void generujJidelnicek();
    void vytiskniJidelnicek();
    vector<Pokrm*> vytvorJidelnicekProDen();
    void vytvorJidelnicek();
    vector<Pokrm*> getPondeli();
    vector<Pokrm*> getUtery();
    vector<Pokrm*> getStreda();
    vector<Pokrm*> getCtvrtek();
    vector<Pokrm*> getPatek();
    // void vypisJidelnicek();
};

#endif // JIDELNICEK_H