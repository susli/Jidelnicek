#ifndef POKRM_H
#define POKRM_H
#include <sstream>
using namespace std;

class Pokrm
{

    int nic = 0;

public:
    int id;
    string nazev;
    int cena;
    int trida;
    string ingredience;

    int getId();

    string getNazev();

    int getCena();

    int getTrida();

    string getIngredience();

    virtual int getObjem();

    virtual void vypis();
};

#endif // POKRM_H
