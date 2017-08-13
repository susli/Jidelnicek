#ifndef POKRM_H
#define POKRM_H
#include <sstream>
using namespace std;

class Pokrm
{

    int nic = 0;

public:
    int id;
    string nazev;
    int cena;
    int trida;
    string ingredience;
    //vector<string> seznamIngredienci;

    // virtual int getPrice(){};
/*
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
    */

    int getId()
    {
        return id;
    }

    string getNazev()
    {
        return nazev;
    }

    int getCena()
    {
        return cena;
    }
    int getTrida()
    {
        return trida;
    }
    string getIngredience()
    {
        return ingredience;
    }

    /*
        vector<string> getIngredience()
        {
            return seznamIngredienci;
        }
    */

    virtual int getObjem()
    {
        return nic;
    }
    virtual void vypis()
    {
        cout << "Id: " << id << "    "
             << "Nazev Jidla: " << nazev << "   "
             << "Cena: " << cena << "   "
             << "Trida: " << trida << "   "
             << "Ingredience: " << /*vypisIngredience()*/ ingredience << " ";
    }
};

#endif // POKRM_H
