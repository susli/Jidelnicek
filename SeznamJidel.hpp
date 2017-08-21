#pragma once

#include <vector>
#include <string>

#include <Pokrm.hpp>
#include <Jidlo.hpp>
#include <ctime>     // std::time
#include <cstdlib>   // std::rand, std::srand
#include <algorithm> // std::random_shuffle

namespace std
{

class SeznamJidel
{

    vector<Jidlo*> seznamJidel;
    vector<int> pouzitePokrmy;

public:
    

    void vlozJidlo(Jidlo* jidlo);
    void odstranJidlo(int id);
    Jidlo* vyberNahodneJidlo();
};
}
