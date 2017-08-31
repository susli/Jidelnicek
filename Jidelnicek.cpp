#include "Jidelnicek.hpp"
#include "CelyJidelnicek.hpp"
#include "Spusteni.hpp"
#include "SeznamJidel.hpp"
#include "Pokrm.hpp"
#include "Jidlo.hpp"
#include <iostream>
#include <vector>

using namespace std;

Spusteni spusteni;
Pokrm* pokrm;
SeznamJidel* seznamJidel;
Jidlo* jidlo;
CelyJidelnicek* celyJidelnicek;

int pocetGenerovaniJidelnicku = 0;

Jidelnicek::vypis()
{
    string jidelnicek = " ";
    if(pondeli.size() != 0) {
        cout << "Pondeli: " << endl;
        for(unsigned int i = 0; i < pondeli.size(); i++) {
            pondeli[i]->vypis();
            cout << endl;
        }
    }
    if(utery.size() > 0) {
        cout << "Utery: " << endl;
        for(unsigned int i = 0; i < utery.size(); i++) {
            utery[i]->vypis();
            cout << endl;
        }
    }
    if(streda.size() > 0) {
        cout << "Streda: " << endl;
        for(unsigned int i = 0; i < streda.size(); i++) {
            streda[i]->vypis();
            cout << endl;
        }
    }
    if(ctvrtek.size() > 0) {
        cout << "Ctvrtek: " << endl;
        for(unsigned int i = 0; i < ctvrtek.size(); i++) {
            ctvrtek[i]->vypis();
            cout << endl;
        }
    }
    if(patek.size() > 0) {
        cout << "Patek: " << endl;
        for(unsigned int i = 0; i < patek.size(); i++) {
            patek[i]->vypis();
            cout << endl;
        }
    }
}

vector<Pokrm*> Jidelnicek::generujJidelnicekProDen()
{
    vector<Pokrm*> den;

    int pocetJidel = 0;
    cout << "kolik jidel bude na den?" << endl;
    cin.clear();
    // cin >> pocetJidel;
    bool chyba = true;
    string vstup = "";
    while(chyba) {
        try {
            cin >> vstup;
            pocetJidel = stoi(vstup);
            chyba = false;
        } catch(invalid_argument& exception) {
            cout << "Nebylo zadano cislo" << endl;
        } catch(out_of_range& exception) {
            cout << "Cislo je prilis velke (nebo prilis male)" << endl;
        }
    }
    cout << endl;

    bool pokracovat = true;
    while(pokracovat) {
        cout << endl;
        for(int i = 0; i < pocetJidel; ++i) {
            Jidlo* ulozJidlo;
            ulozJidlo = seznamJidel->vyberNahodneJidlo();
            if(jidlo->kontrolaPouzitiJidla(ulozJidlo) == true && jidlo->kontrolaIngredienciJidla(ulozJidlo) == true) {
                den.push_back(ulozJidlo);
                seznamJidel->vlozPouzityPokrm(ulozJidlo);
            } else {
                ulozJidlo = seznamJidel->vyberNahodneJidlo();
                if(jidlo->kontrolaPouzitiJidla(ulozJidlo) == true &&
                    jidlo->kontrolaIngredienciJidla(ulozJidlo) == true) {
                    den.push_back(ulozJidlo);
                    seznamJidel->vlozPouzityPokrm(ulozJidlo);
                }
            }
        }
        pokracovat = false;
    }
    return den;

    seznamJidel->vypisPouzitePokrmy();
}

void Jidelnicek::generujJidelnicek()
{
    char generovatJidelnicek = 0;
    string den = " ";
    Jidelnicek* jidelnicek = new Jidelnicek;
    cout << "chcete vytvorit jidelnicek? a/n " << endl;
    cin >> generovatJidelnicek;
    if(generovatJidelnicek != 'a') {
        return;
    }
    if(seznamJidel->getSeznamJidel().size() != 0) {

        cout << "Zadej pocet jidel na Pondeli" << endl;
        jidelnicek->pondeli = generujJidelnicekProDen();
        cout << "Zadej pocet jidel na Utery" << endl;
        jidelnicek->utery = generujJidelnicekProDen();
        cout << "Zadej pocet jidel na Stredu" << endl;
        jidelnicek->streda = generujJidelnicekProDen();
        cout << "Zadej pocet jidel na Ctvrtek" << endl;
        jidelnicek->ctvrtek = generujJidelnicekProDen();
        cout << "Zadej pocet jidel na Patek" << endl;
        jidelnicek->patek = generujJidelnicekProDen();
        celyJidelnicek->vlozJidelnicek(jidelnicek);
        pocetGenerovaniJidelnicku++;
        cout << endl << "vygenerovan tydenni jidelnicek" << pocetGenerovaniJidelnicku << endl;
    } else {
        cout << "Seznam jidel je prazdy, nelze vytvorit jidelnicek." << endl;
    }
}

vector<Pokrm*> Jidelnicek::getPondeli()
{
    return pondeli;
}
vector<Pokrm*> Jidelnicek::getUtery()
{
    return utery;
}
vector<Pokrm*> Jidelnicek::getStreda()
{
    return streda;
}
vector<Pokrm*> Jidelnicek::getCtvrtek()
{
    return ctvrtek;
}
vector<Pokrm*> Jidelnicek::getPatek()
{
    return patek;
}

vector<Pokrm*> Jidelnicek::vytvorJidelnicekProDen()
{
    int x = 0;
    int velikostVectoru = seznamJidel->getSeznamJidel().size();
    vector<Pokrm*> den;
    bool pokracovat = true;
    char dalsi = 0;
    if(seznamJidel->getSeznamJidel().size() != 0) {

        while(pokracovat) {
            jidlo->vypisJidlo();
            cout << endl;
            cout << "zadejte Id jidla" << endl;
            // cin >> x;
            bool chyba = true;
            string vstup = "";
            while(chyba) {
                try {
                    cin >> vstup;
                    x = stoi(vstup);
                    chyba = false;
                } catch(invalid_argument& exception) {
                    cout << "Nebylo zadano cislo" << endl;
                } catch(out_of_range& exception) {
                    cout << "Cislo je prilis velke (nebo prilis male)" << endl;
                }
            }
            if(x > velikostVectoru) {
                cout << "jidlo neexistuje" << endl;
                cout << "zadejte spravne Id pokrmu" << endl;
                continue;
            }
            den.push_back(seznamJidel->getSeznamJidel()[x]);
            cout << "prejete si zadat dalsi pokrm? a/n" << endl;
            cin >> dalsi;
            if(dalsi != 'a') {
                pokracovat = false;
            }
        }

        return den;
    }
    cout << "Seznam jidel neobsahuje zadne jidla. Nejdrive vytvorte jidlo. " << endl;
}

void Jidelnicek::vytvorJidelnicek()
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
    if(seznamJidel->getSeznamJidel().size() != 0) {
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
        celyJidelnicek->vlozJidelnicek(jidelnicek);
    }
    cout << "Seznam jidel neobsahuje zadne jidla. Nejdrive vytvorte jidlo. " << endl;
}