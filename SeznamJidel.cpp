#include "SeznamJidel.hpp"
#include "Napoj.hpp"
#include <string>
#include <vector>
#include "Jidlo.hpp"
#include <ctime>     // std::time
#include <cstdlib>   // std::rand, std::srand
#include <algorithm> // std::random_shuffle

using namespace std;

vector<Jidlo*> sJidel;
vector<Napoj*> sNapoju;
vector<int> pouzitePokrmy;

void SeznamJidel::vlozJidlo(Jidlo* jidlo)
{
    sJidel.push_back(jidlo);
}

void SeznamJidel::vlozNapoj(Napoj* napoj)
{
    sNapoju.push_back(napoj);
}

void SeznamJidel::odstranJidlo(int id)
{
}

void SeznamJidel::nahodneSerazeni()
{
    random_shuffle(sJidel.begin(), sJidel.end());
}

/*
// zatím nefunguje
Pokrm* SeznamJidel::vyberNahodneJidlo()
{
    Pokrm* nahodneJidlo = *nahodnyVyber(sJidel.begin(), sJidel.end());
    return nahodneJidlo;
}
*/
void SeznamJidel::vlozPouzityPokrm(Pokrm* pokrm)
{
    pouzitePokrmy.push_back(pokrm->getId());
}

void SeznamJidel::vynulujSeznamJidel()
{
    sJidel.clear();
}

void SeznamJidel::vynulujSeznamNapoju()
{
    sNapoju.clear();
}

vector<Jidlo*> SeznamJidel::getSeznamJidel()
{
    return sJidel;
}

vector<Napoj*> SeznamJidel::getSeznamNapoju()
{
    return sNapoju;
}

vector<int> SeznamJidel::getPouzitePokrmy()
{
    return pouzitePokrmy;
}