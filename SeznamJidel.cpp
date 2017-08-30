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
vector<vector<string> > predchoziIngredience;

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

Jidlo* SeznamJidel::vyberNahodneJidlo()
{
    Jidlo* nahodneJidlo = *nahodnyVyber(sJidel.begin(), sJidel.end());
    return nahodneJidlo;
}

void SeznamJidel::vlozPouzityPokrm(Jidlo* jidlo)
{
    pouzitePokrmy.push_back(jidlo->getId());
}

void SeznamJidel::vlozPredchoziIngredience(Jidlo* jidlo)
{
    predchoziIngredience.push_back(jidlo->getIngredience1());
}

void SeznamJidel::vynulujPredchoziIngredience()
{
    predchoziIngredience.clear();
}

void SeznamJidel::vynulujPouzitePokrmy()
{
    cout << "Nuluji pouzite pokrmy." << endl;
    pouzitePokrmy.clear();
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

vector<vector<string> > SeznamJidel::getPredchoziIngredience()
{
    return predchoziIngredience;
}

void SeznamJidel::vypisPouzitePokrmy()
{
    for(int i = 0; i < pouzitePokrmy.size(); ++i) {
        cout << "PoP: " << pouzitePokrmy[i] << ", ";
    }
    cout << endl;
}
