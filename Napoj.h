#ifndef NAPOJ_H
#define NAPOJ_H
#include <Jidlo.h>
#include <Pokrm.h>

using namespace std;

class Napoj : public Jidlo
{
    int objem;

public:
    Napoj(int id, string nazev, int cena, int trida, string ingredience, int objem)
        : Jidlo(id, nazev, cena, trida, ingredience)
        , objem(objem)
    {
    }
    int getId()
    {
        return id;
    }
    string getNazev()
    {
        return nazev;
    }
    int getPrice()
    {
        return cena;
    }
    int getTrida()
    {
        return trida;
    }
    int getObjem()
    {
        return objem;
    }

    ~Napoj()
    {
    }

    virtual void vypis()
    {
        Jidlo::vypis();
        cout << "Objem: " << objem;
    }
};

#endif // NAPOJ_H
