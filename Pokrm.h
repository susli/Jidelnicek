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

    // virtual int getPrice(){};

    int getId()
    {
        return id;
    }

    string getNazev()
    {
        return nazev;
    }

    int getCena()
    {
        return cena;
    }
    int getTrida()
    {
        return trida;
    }

    virtual int getObjem()
    {
        return nic;
    }
    virtual void vypis()
    {
        cout << "Id: " << id << "    "
             << "Nazev Jidla: " << nazev << "   "
             << "Cena: " << cena << "   "
             << "Trida: " << trida << "   ";
    }
};

#endif // POKRM_H
