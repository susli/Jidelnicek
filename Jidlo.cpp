#include "Jidlo.hpp"
#include "SeznamJidel.hpp"
using namespace std;

SeznamJidel* seznamjidel;

//public:
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

void Jidlo::ulozIngredience(string ingredience)
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

string Jidlo::vypisIngredience()
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

vector<string> Jidlo::getIngredience()
{
    return seznamIngredienci;
}

void Jidlo::vypis()
{
    Pokrm::vypis();
    cout << "Ingredience: " << vypisIngredience() << "    ";
}

void Jidlo::vypisJidlo()
{
    cout << "Dostupna jidla" << endl << "--------------------------------" << endl;
    for(Jidlo* jidlo : seznamjidel->getSeznamJidel()) {
        jidlo->vypis();

        cout << endl;
    }
    cout << "Dostupne napoje" << endl << "--------------------------------" << endl;
    for(Napoj* napoj : seznamjidel->getSeznamNapoju()) {
        napoj->vypis();
        cout << endl;
    }
}