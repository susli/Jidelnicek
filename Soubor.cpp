#include "Soubor.hpp"

int IDJidlo = 0;
int IDNapoj = 0;
SeznamJidel* seznam;

Soubor::Soubor()
{
}

Soubor::~Soubor()
{
}

void Soubor::ulozDoSouboru()
{
    ofstream outFileJidlo("jidlo.csv", ios::out);
    ofstream outFileNapoje("napoj.csv", ios::out);
    if(!outFileJidlo || !outFileNapoje) {
        cout << "Chyba" << endl;
    } else {
        for(Jidlo* jidlo : seznam->getSeznamJidel()) {
            outFileJidlo << jidlo->getId() << ";" << jidlo->getNazev() << ";" << jidlo->getCena() << ";"
                         << jidlo->getTrida() << ";" << jidlo->vypisIngredience() << ";" << jidlo->getObjem() << ";"
                         << endl;
        }
        outFileJidlo.close();
        for(Pokrm* napoj : seznam->getSeznamNapoju()) {
            outFileNapoje << napoj->getId() << ";" << napoj->getNazev() << ";" << napoj->getCena() << ";"
                          << napoj->getTrida() << ";" << napoj->getIngredience() << ";" << napoj->getObjem() << ";"
                          << endl;
        }
        outFileNapoje.close();
    }
}

Soubor::nactiRadekSouboru(string* radka)
{
    string retezec = *radka;
    string oddelovac = ";";
    stringstream ss;
    int intId;
    string nazev;
    double intCena;
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
            if(intObsah == 0) {
                Jidlo* jidlo;
                jidlo = new Jidlo(IDJidlo, nazev, intCena, trida, ingredience);
                jidlo->ulozIngredience(ingredience);
                seznam->vlozJidlo(jidlo);
                IDJidlo++;
            } else {
                Napoj* napoj;
                napoj = new Napoj(IDNapoj, nazev, intCena, trida, ingredience, intObsah);
                seznam->vlozNapoj(napoj);
                IDNapoj++;
            }
        }
    }
}

void Soubor::nacteniJidelZeSouboru()
{
    seznam->vynulujSeznamJidel(); // smazaní seznamu jidel
    seznam->vynulujSeznamNapoju();
    IDJidlo = 0; // vynulování počtu jidel při načtení
    IDNapoj = 0;
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