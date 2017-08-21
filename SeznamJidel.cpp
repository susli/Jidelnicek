#include "SeznamJidel.hpp"
#include <string>
#include "Jidlo.hpp"
#include <ctime>     // std::time
#include <cstdlib>   // std::rand, std::srand
#include <algorithm> // std::random_shuffle

std::SeznamJidel::SeznamJidel(vector<Jidlo*> seznamJidel)
{
}

std::SeznamJidel::~SeznamJidel()
{
}

std::SeznamJidel::vlozJidlo()
{
    Jidlo* jidlo = new Jidlo(int id, string nazev, int cena, int trida, string ingredience);
    seznamJidel.push_back(jidlo);
}
