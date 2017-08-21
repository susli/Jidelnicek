

#include "Napoj.hpp"

Napoj::Napoj(int id, string nazev, int cena, int trida, string ingredience, int objem)
    : Jidlo(id, nazev, cena, trida, ingredience)
    , objem(objem)
{
}

Napoj::~Napoj()
{
}

Napoj::getId()
{
    return id;
}
Napoj::getNazev()
{
    return nazev;
}
Napoj::getPrice()
{
    return cena;
}
Napoj::getTrida()
{
    return trida;
}

Napoj::getIngredience()
{
    return ingredience;
}
Napoj::getObjem()
{
    return objem;
}

Napoj::vypis()
{
    Jidlo::vypis();
    cout << "Objem: " << objem;
}