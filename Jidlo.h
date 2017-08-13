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
vector<string> seznamIngredienci;

void ulozIngredience(string ingredience)
    {

        string retezec = ingredience;
        string oddelovac = ",";

        stringstream ss;

        size_t pozice = 0;
        string slovo;

        for(int i = 0; (pozice = retezec.find(oddelovac)) != string::npos; i++) {
            slovo = retezec.substr(0, pozice);
            seznamIngredienci.push_back(slovo);
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
        return ingred;
    }
    Jidlo(int id, string nazev, int cena, int trida, string ingredience)
    {
        this->id = id;
        this->nazev = nazev;
        this->cena = cena;
        this->trida = trida;
        this->ingredience = ingredience;
    }
    
    vector<string> getIngredience()
        {
            return seznamIngredienci;
        }
};

#endif // JIDLO_H
