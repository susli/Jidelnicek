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
    /*
    template <typename Iterator, typename NahodnyGenerator>
    Iterator nahodnyVyber(Iterator start, Iterator end, NahodnyGenerator& g);
    template <typename Iterator> Iterator nahodnyVyber(Iterator start, Iterator end);
*/
public:
    int idJidlo = 0;
    int idNapoj = 0;
    vector<Jidlo*> seznamJidel;
    void vlozPouzityPokrm(Jidlo* jidlo);
    void vlozPredchoziIngredience(Jidlo* jidlo);
    void vynulujPredchoziIngredience();
    void vlozJidlo(Jidlo* jidlo);
    void vlozNapoj(Napoj* napoj);
    void odstranJidlo(int id);
    void nahodneSerazeni();
    void vynulujSeznamJidel();
    void vynulujSeznamNapoju();
    Jidlo* vyberNahodneJidlo();
    vector<Jidlo*> getSeznamJidel();
    vector<Napoj*> getSeznamNapoju();
    vector<int> getPouzitePokrmy();
    vector<vector<string> > getPredchoziIngredience();
};