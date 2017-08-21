#include "SeznamJidel.hpp"
#include <string>
#include "Jidlo.h"

std::SeznamJidel::SeznamJidel(vector<Jidlo*> seznamJidel)
{
}

std::SeznamJidel::~SeznamJidel()
{
}

std::SeznamJidel::vlozJidlo(){
    Jidlo* jidlo = new Jidlo(int id, string nazev, int cena, int trida, string ingredience);
    seznamJidel.push_back(jidlo);
}


