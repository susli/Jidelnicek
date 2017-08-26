#pragma once
#include <string>
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
};
}
