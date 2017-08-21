#include "Pokrm.hpp"

Pokrm::getId()
{
    return id;
}

Pokrm::getNazev()
{
    return nazev;
}
Pokrm::getCena()
{
    return cena;
}

Pokrm::getTrida()
{
    return trida;
}

Pokrm::getIngredience()
{
    return ingredience;
}
Pokrm::getObjem()
{
    return nic;
}

Pokrm::vypis()
{
    cout << "Id: " << id << "    "
         << "Nazev Jidla: " << nazev << "   "
         << "Cena: " << cena << "   "
         << "Trida: " << trida << "   ";
    //       << "Ingredience: " << "--------" << " ";
}