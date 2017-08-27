#include "SeznamJidel.hpp"
#include "Napoj.hpp"
#include <string>
#include <vector>
#include "Jidlo.hpp"
#include <ctime>     // std::time
#include <cstdlib>   // std::rand, std::srand
#include <algorithm> // std::random_shuffle

using namespace std;

/*
template <typename Iterator, typename NahodnyGenerator>
Iterator nahodnyVyber(Iterator start, Iterator end, NahodnyGenerator& g)
{
    uniform_int_distribution<> dis(0, distance(start, end) - 1);
    advance(start, dis(g));
    return start;
}

template <typename Iterator> Iterator nahodnyVyber(Iterator start, Iterator end)
{
    static random_device rd;
    static mt19937 gen(rd());
    return nahodnyVyber(start, end, gen);
}
*/

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
void SeznamJidel::vynulujSeznamNapoju(){
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
