#include "Spusteni.hpp"

Soubor* soubor1;
Jidlo* tridajidlo1;
Jidelnicek* jidelnicek1;
CelyJidelnicek* ceJidelnicek1;
SeznamJidel* seznam1;

void Spusteni::moznostiPokrmu()
{
    char volba;
    cout << "Volby Pokrmu" << endl;
    cout << endl;
    cout << "Zadej 1, pro vytvoreni jidel" << endl;
    cout << "Zadej 2, pro vypsani seznamu Jidel" << endl;
    cout << "Zadej 3, pro rucni vytvoreni Jidelnicku" << endl;
    cout << "Zadej 4, pro vypsani Jidelnicku" << endl;
    cout << "Zadej 5, pro ulozeni seznamu Jidel" << endl;
    cout << "Zadej 6, pro nacteni seznamu jidel ze souboru" << endl;
    cout << "Zadej 7, pro vytisknuti Jidelnicku" << endl;
    cout << "Zadej 8, pro odstraneni jidla ze seznamu" << endl;
    cout << "Zadej 9, pro vygenerovani jidelnicku na tyden" << endl;
    cout << "Zadej Q, pro konec programu" << endl;
    cin >> volba;

    switch(volba) {
    case '1': {
        tridajidlo1->vytvorJidlo();
        moznostiPokrmu();
        break;
    }
    case '2': {
        tridajidlo1->vypisJidlo();
        tridajidlo1->vypisNapoje();
        moznostiPokrmu();
        break;
    }
    case '3': {
        jidelnicek1->vytvorJidelnicek();
        moznostiPokrmu();
        break;
    }
    case '4': {
        ceJidelnicek1->vypisCelyJidelnicek();
        moznostiPokrmu();
        break;
    }
    case '5': {
        soubor1->ulozDoSouboru();
        moznostiPokrmu();
        break;
    }
    case '6': {
        soubor1->nacteniJidelZeSouboru();
        moznostiPokrmu();
        break;
    }
    case '7': {
        soubor1->vytiskniJidelnicek();
        moznostiPokrmu();
        break;
    }
    case '8': {
        seznam1->odstranJidlo();
        moznostiPokrmu();
        break;
    }
    case '9': {
        jidelnicek1->generujJidelnicek();
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