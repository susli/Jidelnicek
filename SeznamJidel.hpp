#pragma once

#include <vector>
#include <string>

#include <Pokrm.hpp>
#include <Jidlo.hpp>
#include <Napoj.hpp>
#include <ctime>     // std::time
#include <cstdlib>   // std::rand, std::srand
#include <algorithm> // std::random_shuffle

using namespace std;


class SeznamJidel
{

    template <typename Iterator, typename NahodnyGenerator>
    Iterator nahodnyVyber(Iterator start, Iterator end, NahodnyGenerator& g);

    template <typename Iterator> Iterator nahodnyVyber(Iterator start, Iterator end);

    

public:
    vector<Jidlo*> seznamJidel;
    vector<Napoj*> seznamNapoju;
    vector<int> pouzitePokrmy;
    void vlozJidlo(Jidlo* jidlo);
    void odstranJidlo(int id);
    void nahodneSerazeni();
    Pokrm* vyberNahodneJidlo();
    vector<Jidlo*> getSeznamJidel;
    vector<Napoj*> getSeznamNapoju;
    vector<int> getPouzitePokrmy;
};

