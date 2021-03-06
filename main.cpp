//#include <stdio.h>
#include <iostream>
#include <fstream>
#include <istream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <iterator>

#include <Pokrm.h>
#include <Jidlo.h>
#include <Napoj.h>
#include <Jidelnicek.h>

#include <ctime>     // std::time
#include <cstdlib>   // std::rand, std::srand
#include <algorithm> // std::random_shuffle

using namespace std;

void moznostiPokrmu();
void vytvorJidlo();
void vypisJidlo();
void zapisJidelDoSouboru();
void nacteniJidelZeSouboru();
void vytvorJidelnicek();
void generujJidelnicek();
void vypisJidelnicek();
void vytiskniJidelnicek();
void generujJidelnicekDen();
vector<Jidlo*> seznamJidel;
vector<Napoj*> seznamNapoju;
vector<Jidelnicek*> celyJidelnicek;
vector<int> pouzitePokrmy;
int pocetGenerovaniJidelnicku = 0;

int idJidlo = 0;
int idNapoj = 0;

template <typename Iterator, typename NahodnyGenerator>
Iterator nahodnyVyber(Iterator start, Iterator end, NahodnyGenerator& g)
{
    uniform_int_distribution<> dis(0, distance(start, end) - 1);
    advance(start, dis(g));
    return start;
}

template <typename Iterator> Iterator nahodnyVyber(Iterator start, Iterator end)
{
    static random_device rd;
    static mt19937 gen(rd());
    return nahodnyVyber(start, end, gen);
}

int main(int argc, char** argv)
{
    nacteniJidelZeSouboru();
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
    // cout << "Zadej 8, po nahodne serazeni seznamu jidel" << endl;
    cout << "Zadej 9, pro vygenerovani jidelnicku na tyden" << endl;
    cout << "Zadej Q, pro konec programu" << endl;
    cin >> volba;

    switch(volba) {
    case '1': {
        vytvorJidlo();
        moznostiPokrmu();
        break;
    }
    case '2': {
        vypisJidlo();
        moznostiPokrmu();
        break;
    }
    case '3': {
        vytvorJidelnicek();
        moznostiPokrmu();
        break;
    }
    case '4': {
        vypisJidelnicek();
        moznostiPokrmu();
        break;
    }
    case '5': {
        zapisJidelDoSouboru();
        moznostiPokrmu();
        break;
    }
    case '6': {
        nacteniJidelZeSouboru();
        moznostiPokrmu();
        break;
    }
    case '7': {
        vytiskniJidelnicek();
        moznostiPokrmu();
        break;
    }
    case '8': {

        moznostiPokrmu();
        break;
    }
    case '9': {

        generujJidelnicek();
        moznostiPokrmu();
        break;
    }
    case 'Q': {
        zapisJidelDoSouboru();
        break;
    }
    default:
        cout << " Byl zadan spatny vyber. Vyber znovu.\n";
        moznostiPokrmu();
        break;
    }
}

void vytvorJidlo()
{
    char vytvoritJidlo;
    bool pokracovat = true;
    char jeNapoj;

    string nazev;
    int obsah;
    double cena;
    int trida;
    string ingredience;
    string vstup;


    trida = 0;
    ingredience = "";

    while(pokracovat) {

        cout << "chcete vytvorit dalsi pokrm? a/n " << endl;
        cin >> vytvoritJidlo;

        if(vytvoritJidlo == 'a') {

            cout << "je pokrm napoj? a/n " << endl;
            cin >> jeNapoj;
            cout << "-----------------------------------------------" << endl;

            if(jeNapoj == 'a') {
                cout << "zadejte nazev napoje: ";
                cin.ignore();
                getline(cin, nazev);

                cout << " zadejte cenu: ";
                
                
      bool chyba;
      do{
          cin >> vstup;
          chyba =!cin;
          if(chyba){
              cout << "chybne zadani, zadejte znovu: ";
              cin.clear();
              cin.ignore(100,'\n');
          }
      }
      
      while(chyba);

/*
                while (cin >> vstup){
        stringstream ss (vstup);
        if(ss>> cena){
            break;
        } else {
            cout << "wrong";
        }
                }

*/
            
                /*
                try
                {
                        cin >> vstup;
                        cena = stod(vstup);
                        break;
                }
                catch (invalid_argument& exception)
                {
                        cout << "Nebylo zadano cislo" << endl;
                }
                catch (out_of_range& exception)
                {
                        cout << "Cislo je prilis velke (nebo prilis male)" << endl;
                }

                */

                cout << " zadejte obsah: ";
                cin >> obsah;
                Napoj* napoj = new Napoj(idNapoj, nazev, cena, trida, ingredience, obsah);
                // seznamJidel.push_back(napoj);
                seznamNapoju.push_back(napoj);
                // idJidlo++;
                idNapoj++;
            } else if(jeNapoj == 'n') {
                cout << "zadejte nazev pokrmu: ";
                cin.ignore();
                getline(cin, nazev);

                cout << " zadejte cenu: ";
                cin >> cena;

                cout << " zadejte tridu: ";
                cin >> trida;

                cout << "zadejte zakladni ingredience oddelene carkou: ";
                cin.ignore();
                getline(cin, ingredience);

                Jidlo* jidlo = new Jidlo(idJidlo, nazev, cena, trida, ingredience);
                jidlo->ulozIngredience(ingredience);
                seznamJidel.push_back(jidlo);
                idJidlo++;
            } else {
                cout << "spatne zadani";
            }

        } else {
            pokracovat = false;
        }
    }
}

vector<Pokrm*> vytvorJidelnicekProDen()
{
    int x = 0;
    int velikostVectoru = seznamJidel.size();
    vector<Pokrm*> den;
    bool pokracovat = true;
    char dalsi = 0;

    while(pokracovat) {
        vypisJidlo();
        cout << endl;
        cout << "zadejte Id jidla" << endl;

        cin >> x;
        if(x >= velikostVectoru) {
            cout << "jidlo neexistuje" << endl;
            cout << "zadejte spravne Id pokrmu" << endl;
            continue;
        }
        den.push_back(seznamJidel[x]);
        cout << "prejete si zadat dalsi pokrm? a/n" << endl;
        cin >> dalsi;
        if(dalsi != 'a') {
            pokracovat = false;
        }
    }
    return den;
}

void vytvorJidelnicek()
{

    char vytvoritJidelnicek = 0;

    string den = "";
    bool pokracovat = true;
    Jidelnicek* jidelnicek = new Jidelnicek;

    cout << "chcete vytvorit jidelnicek? a/n " << endl;
    cin >> vytvoritJidelnicek;

    if(vytvoritJidelnicek != 'a') {

        return;
    }

    while(pokracovat) {

        cout << "Pro jaky den si prejete jidelnicek vytvorit?" << endl;
        cout << "pro vyber dne zadejte prvni dve pismena dne" << endl;
        cin >> den;

        if(den == "po") {
            cout << "vytvarim jidelnicek pro pondeli" << endl;
            jidelnicek->pondeli = vytvorJidelnicekProDen();
        }
        if(den == "ut") {
            cout << "vytvarim jidelnicek pro utery" << endl;
            jidelnicek->utery = vytvorJidelnicekProDen();
        }
        if(den == "st") {
            cout << "vytvarim jidelnicek pro streda" << endl;
            jidelnicek->streda = vytvorJidelnicekProDen();
        }
        if(den == "ct") {
            cout << "vytvarim jidelnicek pro ctvrtek" << endl;
            jidelnicek->ctvrtek = vytvorJidelnicekProDen();
        }
        if(den == "pa") {
            cout << "vytvarim jidelnicek pro patek" << endl;
            jidelnicek->patek = vytvorJidelnicekProDen();
        }

        cout << "prejete si nastavit pokrmy pro dalsi den? a/n" << endl;
        char dalsiDen;
        cin >> dalsiDen;
        if(dalsiDen != 'a') {
            pokracovat = false;
        }
    }

    celyJidelnicek.push_back(jidelnicek);
}

void vypisJidelnicek()
{
    for(Jidelnicek* jidelnicek : celyJidelnicek) {
        jidelnicek->vypis();
        cout << endl << endl << endl;
    }
}

void vypisJidlo()
{
    cout << "Dostupna jidla" << endl << "--------------------------------" << endl;
    for(Jidlo* jidlo : seznamJidel) {
        jidlo->vypis();

        cout << endl;
    }
    cout << "Dostupne napoje" << endl << "--------------------------------" << endl;
    for(Napoj* napoj : seznamNapoju) {
        napoj->vypis();
        cout << endl;
    }
}

void zapisJidelDoSouboru()
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

nactiRadekSouboru(string* radka)
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

void nacteniJidelZeSouboru()
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

void vytiskniJidelnicek()
{

    stringstream ss;
    ofstream outFile("jidelnicek.txt");

    if(!outFile) {
        cout << "Chyba" << endl;
    } else {

        for(Jidelnicek* jidelnicek : celyJidelnicek) {
            outFile << jidelnicek->vypis();
            // ss >>outFile;
        }

        outFile.close();
    }
}

Pokrm* vyberNahodneJidlo()
{
    Pokrm* nahodneJidlo = *nahodnyVyber(seznamJidel.begin(), seznamJidel.end());
    return nahodneJidlo;
}

bool kontrolaPokrmu(Pokrm* nahodneJidlo)
{
    if(seznamJidel.size() >= 15 && seznamJidel.size() < 25 && pocetGenerovaniJidelnicku == 4) {
        goto provedGenerovani;
    } else if(seznamJidel.size() < 15 && pocetGenerovaniJidelnicku == 2) {
    provedGenerovani:
        pouzitePokrmy.clear();
        pocetGenerovaniJidelnicku = 0;

        for(int i = 0; i < pouzitePokrmy.size(); ++i) {
            if(pouzitePokrmy[i] == nahodneJidlo->getId()) {
                return false;

            } else {
                return true;
            }
        }
    }

    else {

        for(int i = 0; i < pouzitePokrmy.size(); ++i) {
            if(pouzitePokrmy[i] == nahodneJidlo->getId()) {
                return false;
            } else {
                return true;
            }
        }
    }

    return true;
}
vector<Pokrm*> generujJidelnicekproDen()
{

    vector<Pokrm*> den;
    bool pokracovat = true;

    int pocetJidel = 0;
    Pokrm* ulozJidlo;

    cout << "kolik jidel bude na den?" << endl;
    cin >> pocetJidel;
    cout << endl;

    while(pokracovat) {

        cout << endl;

        for(int i = 0; i < pocetJidel; ++i) {
            ulozJidlo = vyberNahodneJidlo();
            if(kontrolaPokrmu(ulozJidlo) == true) {
                den.push_back(ulozJidlo);
                pouzitePokrmy.push_back(ulozJidlo->getId());

            } else {
                continue;
            }
        }

        pokracovat = false;
    }
    return den;
}

void generujJidelnicek()
{
    char generovatJidelnicek = 0;

    string den = " ";
    //bool pokracovat = true;
    Jidelnicek* jidelnicek = new Jidelnicek;

    cout << "chcete vytvorit jidelnicek? a/n " << endl;
    cin >> generovatJidelnicek;

    if(generovatJidelnicek != 'a') {

        return;
    }

    //while(pokracovat) {

        jidelnicek->pondeli = generujJidelnicekproDen();

        jidelnicek->utery = generujJidelnicekproDen();

        jidelnicek->streda = generujJidelnicekproDen();

        jidelnicek->ctvrtek = generujJidelnicekproDen();

        jidelnicek->patek = generujJidelnicekproDen();

    //    pokracovat = false;
    //}

    celyJidelnicek.push_back(jidelnicek);
    pocetGenerovaniJidelnicku++;
    cout << endl << "vygenerovan tydenni jidelnicek" << pocetGenerovaniJidelnicku << endl;
}