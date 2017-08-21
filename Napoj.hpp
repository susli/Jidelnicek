#ifndef NAPOJ_H
#define NAPOJ_H
#include <Jidlo.hpp>
#include <Pokrm.hpp>

using namespace std;

class Napoj : public Jidlo
{
    int objem;

public:
    Napoj(int id, string nazev, int cena, int trida, string ingredience, int objem)
        : Jidlo(id, nazev, cena, trida, ingredience)
    {
    }
    /*
    {
        this->objem=objem;
    }
      */
    //, objem(objem);

    ~Napoj();

    int getId();

    string getNazev();

    int getPrice();

    int getTrida();

    string getIngredience();

    int getObjem();

    virtual void vypis();
};

#endif // NAPOJ_H
