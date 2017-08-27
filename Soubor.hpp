#pragma once
#include <string>
#include <fstream>
//#include <string>
#include <iostream>
#include <sstream>

#include "Jidlo.hpp"
#include "SeznamJidel.hpp"
#include "Napoj.hpp"
namespace std
{

class Soubor
{
public:
    Soubor();
    ~Soubor();

    void ulozDoSouboru();
    nactiRadekSouboru(string* radka);
    void nacteniJidelZeSouboru();
    int getIdJidlo();
    int getIdNapoj();
};
}
