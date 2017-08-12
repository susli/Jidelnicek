//#include <stdio.h>
#include <iostream>
#include <fstream>
//#include <ostream>
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
vector<Pokrm*> seznamJidel;
vector<Jidelnicek*> celyJidelnicek;

int idPokrm = 0;

template <typename Iter, typename RandomGenerator> Iter select_randomly(Iter start, Iter end, RandomGenerator& g)
{
    std::uniform_int_distribution<> dis(0, std::distance(start, end) - 1);
    std::advance(start, dis(g));
    return start;
}

template <typename Iter> Iter select_randomly(Iter start, Iter end)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    return select_randomly(start, end, gen);
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

    while(pokracovat) {

        cout << "chcete vytvorit dalsi pokrm? a/n " << endl;
        cin >> vytvoritJidlo;

        trida = 0;

        if(vytvoritJidlo == 'a') {

            cout << "je pokrm napoj? a/n " << endl;
            cin >> jeNapoj;
            cout << "-----------------------------------------------" << endl;

            if(jeNapoj == 'a') {
                cout << "zadejte nazev napoje: ";
                cin.ignore();
                getline(cin, nazev);

                cout << " zadejte cenu: ";
                cin >> cena;

                cout << " zadejte obsah: ";
                cin >> obsah;
                Napoj* napoj = new Napoj(idPokrm, nazev, cena, trida, obsah);
                seznamJidel.push_back(napoj);
                idPokrm++;
            } else if(jeNapoj == 'n') {
                cout << "zadejte nazev pokrmu: ";
                cin.ignore();
                getline(cin, nazev);

                cout << " zadejte cenu: ";
                cin >> cena;

                cout << " zadejte tridu: ";
                cin >> trida;

                Jidlo* pokrm = new Jidlo(idPokrm, nazev, cena, trida);
                seznamJidel.push_back(pokrm);
                idPokrm++;
            } else {
                cout << "spatne zadani";
            }

        } else {
            pokracovat = false;
        }
    }
}

vector<Pokrm*> vytvorJidelnicekproDen()
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
    int x = 0;
    char vytvoritJidelnicek = 0;
    char pridatJidlo = 0;
    string den = " ";
    bool pokracovat = true;
    Jidelnicek* jidelnicek = new Jidelnicek;
    Pokrm* pokrm;

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
            jidelnicek->pondeli = vytvorJidelnicekproDen();
        }
        if(den == "ut") {
            cout << "vytvarim jidelnicek pro utery" << endl;
            jidelnicek->utery = vytvorJidelnicekproDen();
        }
        if(den == "st") {
            cout << "vytvarim jidelnicek pro streda" << endl;
            jidelnicek->streda = vytvorJidelnicekproDen();
        }
        if(den == "ct") {
            cout << "vytvarim jidelnicek pro ctvrtek" << endl;
            jidelnicek->ctvrtek = vytvorJidelnicekproDen();
        }
        if(den == "pa") {
            cout << "vytvarim jidelnicek pro patek" << endl;
            jidelnicek->patek = vytvorJidelnicekproDen();
        }

        cout << "prejete si nastavit pokrmy pro dalsi den? a/n" << endl;
        char dalsiDen;
        cin >> dalsiDen;
        if(dalsiDen != 'a') {
            pokracovat = false;
        }
    }

    celyJidelnicek.push_back(jidelnicek);
    vytvorJidelnicek();
}

void vypisJidelnicek()
{
    for(Jidelnicek* jidelnicek : celyJidelnicek) {
        jidelnicek->vypis();
    }
}

void vypisJidlo()
{
    cout << "Dostupna jidla" << endl;
    for(Pokrm* pokrm : seznamJidel) {
        pokrm->vypis();
        cout << endl;
    }
}

void zapisJidelDoSouboru()
{

    ofstream outFile("jidlo.csv", ios::out);

    if(!outFile) {
        cout << "Chyba" << endl;
    } else {
        int size = seznamJidel.size();

        for(Pokrm*& pokrm : seznamJidel) {
            outFile << pokrm->getId() << ";" << pokrm->getNazev() << ";" << pokrm->getCena() << ";" << pokrm->getTrida()
                    << ";" << pokrm->getObjem() << ";" << endl;
        }
        outFile.close();
    }
}

nactiRadekSouboruJidlo(string* radka)
{
    string retezec = *radka;
    string oddelovac = ";";

    stringstream ss;

    int intId;
    string nazev;
    int intCena;
    int trida;
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
            ss >> nazev;
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
            ss >> intObsah;
            ss.clear();
            retezec.erase(0, pozice + oddelovac.length());
            break;
        }
        }

        if(i == 4) {
            Pokrm* pokrm;

            if(intObsah == 0) {
                pokrm = new Jidlo(idPokrm, nazev, intCena, trida);
                seznamJidel.push_back(pokrm);
                idPokrm++;

            } else {
                pokrm = new Napoj(idPokrm, nazev, intCena, trida, intObsah);
                seznamJidel.push_back(pokrm);
                idPokrm++;
            }
        }
    }
}

void nacteniJidelZeSouboru()
{
    seznamJidel.clear(); // smazaní seznamu jidel
    idPokrm = 0;         // vynulování počtu jidel při načtení
    ifstream inJidlo;
    inJidlo.open("jidlo.csv");

    for(string radka = " "; getline(inJidlo, radka);) {
        nactiRadekSouboruJidlo(&radka);
    }
    inJidlo.close();
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
    Pokrm* nahodneJidlo = *select_randomly(seznamJidel.begin(), seznamJidel.end());
    return nahodneJidlo;
}

vector<Pokrm*> generujJidelnicekproDen()
{

    vector<Pokrm*> den;
    bool pokracovat = true;

    int pocetJidel = 0;

    cout << "kolik jidel bude na den?" << endl;
    cin >> pocetJidel;
    cout << endl;

    while(pokracovat) {

        cout << endl;

        for(int i = 0; i < pocetJidel; ++i) {
            den.push_back(vyberNahodneJidlo());
        }

        pokracovat = false;
    }
    return den;
}

void generujJidelnicek()
{
    char generovatJidelnicek = 0;

    string den = " ";
    bool pokracovat = true;
    Jidelnicek* jidelnicek = new Jidelnicek;

    cout << "chcete vytvorit jidelnicek? a/n " << endl;
    cin >> generovatJidelnicek;

    if(generovatJidelnicek != 'a') {

        return;
    }

    while(pokracovat) {

        jidelnicek->pondeli = generujJidelnicekproDen();

        jidelnicek->utery = generujJidelnicekproDen();

        jidelnicek->streda = generujJidelnicekproDen();

        jidelnicek->ctvrtek = generujJidelnicekproDen();

        jidelnicek->patek = generujJidelnicekproDen();

        pokracovat = false;
    }

    celyJidelnicek.push_back(jidelnicek);
}