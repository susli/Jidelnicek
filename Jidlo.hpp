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

    int idJidloNove = 0;
    int idNapojNove = 0;
    int kontrola = 0;
    int poslednijidlo = NULL;
    void vypis();
    void vypisJidlo();
    void vytvorJidlo();
    void ulozIngredience(string ingredience);
    bool kontrolaPouzitiJidla(Jidlo* nahodneJidlo);
    bool kontrolaIngredienciJidla(Jidlo* nahodneJidlo);
    bool najdiShodu(int hledanyPrvek, vector<int> seznamPrvku);
    string vypisIngredience();
    vector<string> getIngredience1();
};

#endif // JIDLO_H
