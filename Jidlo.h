#ifndef JIDLO_H
#define JIDLO_H
#include <string>
#include <sstream>
#include <iostream>
#include <Pokrm.h>

using namespace std;

class Jidlo : public Pokrm
{
    vector<string> seznamIngredienci;
    string seznamIngr;
public:

    Jidlo(int id, string nazev, int cena, int trida, string ingredience)
    {
        this->id = id;
        this->nazev = nazev;
        this->cena = cena;
        this->trida = trida;
        this->ingredience = ingredience;
    }

    void ulozIngredience(string ingredience)
    {
        cout << "ukladani ingredienci v tride Jidlo" << endl;

        string retezec = ingredience;
        string oddelovac = ",";

        stringstream ss;

        size_t pozice = 0;
        string slovo;

        for(int i = 0; (pozice = retezec.find(oddelovac)) != string::npos; i++) {
            cout << "for cyklus pruchod: " << i << endl;
            slovo = retezec.substr(0, pozice);
            seznamIngredienci.push_back(slovo);
            cout << "Vložena ingredience: " << slovo << endl;
            retezec.erase(0, pozice + oddelovac.length());
        }
    }

    string vypisIngredience()
    {
        stringstream ss;
        string ingred;
        for(auto i = seznamIngredienci.begin(); i != seznamIngredienci.end(); ++i) {
            ss << *i << ',';
        }

        ss >> ingred;
        //cout << ingred;
        seznamIngr=ingred;
        return ingred;
    }

    vector<string> getIngredience()
    {
        return seznamIngredienci;
    }
    virtual void vypis()
    {
        Pokrm::vypis();
        cout << "Ingredience: " << vypisIngredience() << "    ";
    }
};

#endif // JIDLO_H
