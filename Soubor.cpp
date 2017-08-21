#include "Soubor.hpp"
#include <string>
#include <iostream>
#include <sstream>
#include "Jidlo.hpp"
#include "SeznamJidel.hpp"
#include "Napoj.hpp"



int idJidlo =0;
int idNapoj = 0;
std::Soubor::Soubor()
{
}

std::Soubor::~Soubor()
{
}

std::Soubor::ulozDoSouboru()
{

    ofstream outFileJidlo("jidlo.csv", ios::out);
    ofstream outFileNapoje("napoj.csv", ios::out);

    if(!outFileJidlo || !outFileNapoje) {
        cout << "Chyba" << endl;
    } else {
        for(Jidlo* jidlo : seznamJidel) {
            outFileJidlo << jidlo->getId() << ";" << jidlo->getNazev() << ";" << jidlo->getCena() << ";"
                         << jidlo->getTrida() << ";" << jidlo->vypisIngredience() << ";" << jidlo->getObjem() << ";"
                         << endl;
        }
        outFileJidlo.close();

        for(Pokrm* napoj : seznamNapoju) {
            outFileNapoje << napoj->getId() << ";" << napoj->getNazev() << ";" << napoj->getCena() << ";"
                          << napoj->getTrida() << ";" << napoj->getIngredience() << ";" << napoj->getObjem() << ";"
                          << endl;
        }
        outFileNapoje.close();
    }
}

std::Soubor::nactiRadekSouboru(string* radka)
{
    string retezec = *radka;
    string oddelovac = ";";

    stringstream ss;

    int intId;
    string nazev;
    int intCena;
    int trida;
    string ingredience;
    int intObsah;

    size_t pozice = 0;
    string slovo;

    for(int i = 0; (pozice = retezec.find(oddelovac)) != string::npos; i++) {
        slovo = retezec.substr(0, pozice);
        switch(i) {
        case 0: {
            ss << slovo;
            ss >> intId;
            ss.clear();
            retezec.erase(0, pozice + oddelovac.length());
            break;
        }
        case 1: {
            ss << slovo;
            getline(ss, nazev);
            ss.clear();
            retezec.erase(0, pozice + oddelovac.length());
            break;
        }
        case 2: {
            ss << slovo;
            ss >> intCena;
            ss.clear();
            retezec.erase(0, pozice + oddelovac.length());
            break;
        }
        case 3: {
            ss << slovo;
            ss >> trida;
            ss.clear();
            retezec.erase(0, pozice + oddelovac.length());
            break;
        }
        case 4: {
            ss << slovo;
            getline(ss, ingredience);
            ss.clear();
            retezec.erase(0, pozice + oddelovac.length());
            break;
        }
        case 5: {
            ss << slovo;
            ss >> intObsah;
            ss.clear();
            retezec.erase(0, pozice + oddelovac.length());
            break;
        }
        }

        if(i == 5) {
            // Pokrm* pokrm;

            if(intObsah == 0) {
                Jidlo* jidlo;
                jidlo = new Jidlo(idJidlo, nazev, intCena, trida, ingredience);
                jidlo->ulozIngredience(ingredience);
                seznamJidel.push_back(jidlo);
                idJidlo++;

            } else {
                Napoj* napoj;
                napoj = new Napoj(idNapoj, nazev, intCena, trida, ingredience, intObsah);
                seznamNapoju.push_back(napoj);
                idNapoj++;
            }
        }
    }
}

std::Soubor::nacteniJidelZeSouboru()
{
    seznamJidel.clear(); // smazaní seznamu jidel
    idJidlo = 0;         // vynulování počtu jidel při načtení
    idNapoj = 0;
    ifstream inJidlo;
    ifstream inNapoj;
    inJidlo.open("jidlo.csv");

    for(string radka = ""; getline(inJidlo, radka);) {
        nactiRadekSouboru(&radka);
    }
    inJidlo.close();

    inNapoj.open("napoj.csv");
    for(string radka = ""; getline(inNapoj, radka);) {
        nactiRadekSouboru(&radka);
    }
    inNapoj.close();
}