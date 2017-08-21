#include "Jidlo.hpp"

Jidlo::Jidlo(int id, string nazev, int cena, int trida, string ingredience)
{

    this->id = id;
    this->nazev = nazev;
    this->cena = cena;
    this->trida = trida;
    this->ingredience = ingredience;
}

Jidlo::~Jidlo()
{
}

Jidlo::ulozIngredience(string ingredience)
{

    string retezec = ingredience;
    string oddelovac = ",";
    string ulozIngredience;

    size_t pozice = 0;
    string slovo;

    for(int i = 0; (pozice = retezec.find(oddelovac)) != string::npos; i++) {
        slovo = retezec.substr(0, pozice);
        seznamIngredienci.push_back(slovo);
        retezec.erase(0, pozice + oddelovac.length());
    }
}

Jidlo::vypisIngredience()
{
    stringstream ss;
    string ingred;
    for(auto i = seznamIngredienci.begin(); i != seznamIngredienci.end(); ++i) {
        ss << *i << ',';
    }

    getline(ss, ingred); // načtení ingrediencí s mezerou
    seznamIngr = ingred;
    return ingred;
}

Jidlo::getIngredience()
{
    return seznamIngredienci;
}

Jidlo::vypis()
{
    Pokrm::vypis();
    cout << "Ingredience: " << vypisIngredience() << "    ";
}