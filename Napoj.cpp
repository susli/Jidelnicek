

#include "Napoj.hpp"

Napoj::Napoj(id, nazev, cena, trida, ingredience, objem)
    : Jidlo(id, nazev, cena, trida, ingredience)
{
    this->objem = objem;
}

Napoj::~Napoj()
{
}

int Napoj::getId()
{
    return id;
}
string Napoj::getNazev()
{
    return nazev;
}
int Napoj::getPrice()
{
    return cena;
}
int Napoj::getTrida()
{
    return trida;
}

string Napoj::getIngredience()
{
    return ingredience;
}
int Napoj::getObjem()
{
    return objem;
}
void Napoj::vypis()
{
    Jidlo::vypis();
    cout << "Objem: " << objem;
}
