#include "SeznamJidel.hpp"
#include <string>
#include "Jidlo.hpp"
#include <ctime>     // std::time
#include <cstdlib>   // std::rand, std::srand
#include <algorithm> // std::random_shuffle

void SeznamJidel::vlozJidlo(Jidlo* jidlo)
{
    
    seznamJidel.push_back(jidlo);
}
void SeznamJidel::odstranJidlo(int id)
{
}
Jidlo* SeznamJidel::vyberNahodneJidlo()
{
}