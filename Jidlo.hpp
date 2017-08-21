#ifndef JIDLO_H
#define JIDLO_H
#include <string>
#include <sstream>
#include <iostream>
#include <Pokrm.hpp>

using namespace std;

class Jidlo : public Pokrm
{
    vector<string> seznamIngredienci;
    string seznamIngr;

public:
    Jidlo(int id, string nazev, int cena, int trida, string ingredience);
    void ulozIngredience(string ingredience);
    string vypisIngredience();
    vector<string> getIngredience();
    void vypis();
};

#endif // JIDLO_H