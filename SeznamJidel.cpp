#include "SeznamJidel.hpp"
#include <string>
#include "Jidlo.hpp"
#include <ctime>     // std::time
#include <cstdlib>   // std::rand, std::srand
#include <algorithm> // std::random_shuffle

using namespace std;

template <typename Iterator, typename NahodnyGenerator>
Iterator SeznamJidel::nahodnyVyber(Iterator start, Iterator end, NahodnyGenerator& g)
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

    seznamJidel.push_back(jidlo);
}
void SeznamJidel::odstranJidlo(int id)
{
}

void SeznamJidel::nahodneSerazeni()
{
    random_shuffle(seznamJidel.begin(), seznamJidel.end());
}

Pokrm* SeznamJidel::vyberNahodneJidlo()
{
    Pokrm* nahodneJidlo = *nahodnyVyber(seznamJidel.begin(), seznamJidel.end());
    return nahodneJidlo;
}