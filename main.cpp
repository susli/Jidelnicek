//#include <stdio.h>
#include <iostream>

#include <istream>
#include <string>
#include <vector>
#include <random>
#include <iterator>

#include "Pokrm.hpp"
#include "Jidlo.hpp"
#include "Napoj.hpp"
#include "Jidelnicek.hpp"
#include "CelyJidelnicek.hpp"
#include "SeznamJidel.hpp"
#include "Soubor.hpp"

/* SeznamJidel
#include <ctime>     // std::time
#include <cstdlib>   // std::rand, std::srand
#include <algorithm> // std::random_shuffle
*/
using namespace std;

void moznostiPokrmu();
void vytvorJidlo();

int idJidlo2 = 0;
int idNapoj2 = 0;

Soubor* soubor;
SeznamJidel* sezJidel;
Jidlo* tridajidlo;
Jidelnicek* jidelnicek;
CelyJidelnicek* ceJidelnicek;
Pokrm* pok;

int main(int argc, char** argv)
{
    soubor->nacteniJidelZeSouboru();
    moznostiPokrmu();
    return 0;
}

void moznostiPokrmu()
{
    char volba;
    cout << "Volby Pokrmu" << endl;
    cout << endl;
    cout << "Zadej 1, pro vytvoreni jidel" << endl;
    cout << "Zadej 2, pro vypsani seznamu Jidel" << endl;
    cout << "Zadej 3, pro vytvoreni Jidelnicku" << endl;
    cout << "Zadej 4, pro vypsani Jidelnicku" << endl;
    cout << "Zadej 5, pro ulozeni seznamu Jidel" << endl;
    cout << "Zadej 6, pro nacteni jidel ze souboru" << endl;
    cout << "Zadej 7, po vytisknuti Jidelnicku" << endl;
    cout << "Zadej 8, po nahodne serazeni seznamu jidel" << endl;
    cout << "Zadej 9, pro vygenerovani jidelnicku na tyden" << endl;
    cout << "Zadej Q, pro konec programu" << endl;
    cin >> volba;

    switch(volba) {
    case '1': {
        tridajidlo->vytvorJidlo();
        // vytvorJidlo();
        moznostiPokrmu();
        break;
    }
    case '2': {
        tridajidlo->vypisJidlo();
        moznostiPokrmu();
        break;
    }
    case '3': {
        jidelnicek->vytvorJidelnicek();
        moznostiPokrmu();
        break;
    }
    case '4': {
        ceJidelnicek->vypisCelyJidelnicek();
        moznostiPokrmu();
        break;
    }
    case '5': {
        soubor->ulozDoSouboru();
        // zapisJidelDoSouboru();
        moznostiPokrmu();
        break;
    }
    case '6': {
        soubor->nacteniJidelZeSouboru();
        moznostiPokrmu();
        break;
    }
    case '7': {
        // vytiskniJidelnicek();
        moznostiPokrmu();
        break;
    }
    case '8': {
        // nahodneSerazeni();
        moznostiPokrmu();
        break;
    }
    case '9': {
        jidelnicek->generujJidelnicek();
        moznostiPokrmu();
        break;
    }
    case 'Q': {
        // zapisJidelDoSouboru();
        break;
    }
    default:
        cout << " Byl zadan spatny vyber. Vyber znovu.\n";
        moznostiPokrmu();
        break;
    }
}
