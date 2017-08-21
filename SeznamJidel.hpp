#pragma once

#include <vector>
#include <string>

#include <Pokrm.hpp>
#include <Jidlo.hpp>

namespace std
{

class SeznamJidel
{

    vector<Jidlo*> seznamJidel;

public:
    SeznamJidel(vector<Jidlo*> seznamJidel);
    ~SeznamJidel();

    void vlozJidlo();
    void odstranJidlo();
    Jidlo* vyberNahodneJidlo();
};
}
