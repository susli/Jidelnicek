#pragma once
#include <fstream>
#include "SeznamJidel.hpp"

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