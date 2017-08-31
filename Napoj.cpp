#include "Napoj.hpp"

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

double Napoj::getCena()
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
    cout << "Objem: " << Napoj::getObjem();
}