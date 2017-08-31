#pragma once
#include <vector>
#include <string>
#include <Napoj.hpp>
#include <ctime>     // std::time
#include <cstdlib>   // std::rand, std::srand
#include <algorithm> // std::random_shuffle

using namespace std;

class SeznamJidel
{
public:
    int idJidlo = 0;
    int idNapoj = 0;
    vector<Jidlo*> seznamJidel;
    void vlozPouzityPokrm(Jidlo* jidlo);
    void vlozPredchoziIngredience(Jidlo* jidlo);
    void vynulujPredchoziIngredience();
    void vynulujPouzitePokrmy();
    void vlozJidlo(Jidlo* jidlo);
    void vlozNapoj(Napoj* napoj);
    void odstranJidlo(int id);
    void nahodneSerazeni();
    void vynulujSeznamJidel();
    void vynulujSeznamNapoju();
    void vypisPouzitePokrmy();
    Jidlo* vyberNahodneJidlo();
    vector<Jidlo*> getSeznamJidel();
    vector<Napoj*> getSeznamNapoju();
    vector<int> getPouzitePokrmy();
    vector<vector<string> > getPredchoziIngredience();
};