#pragma once
#ifndef JIDLO_H
#define JIDLO_H
#include <string>
#include <sstream>
#include <iostream>
#include <Pokrm.hpp>
#include <vector>

using namespace std;

class Jidlo : public Pokrm
{
    vector<string> seznamIngredienci;
    string seznamIngr;

public:
    Jidlo(int id, string nazev, double cena, int trida, string ingredience);
    ~Jidlo();
    void ulozIngredience(string ingredience);
    string vypisIngredience();
    vector<string> getIngredience1();
    void vypis();
    void vypisJidlo();
    void vypisNapoje();
    void vytvorJidlo();
    bool kontrolaPouzitiJidla(Jidlo* nahodneJidlo);
    bool kontrolaIngredienciJidla(Jidlo* nahodneJidlo);
    bool najdiShodu(int hledanyPrvek, vector<int> seznamPrvku);
};

#endif // JIDLO_H
