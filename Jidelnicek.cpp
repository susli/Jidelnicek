#include "Jidelnicek.hpp"
#include "CelyJidelnicek.hpp"
#include "SeznamJidel.hpp"
#include "Pokrm.hpp"
#include "Jidlo.hpp"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

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

vector<Pokrm*> Jidelnicek::generujJidelnicekproDen()
{
    vector<Pokrm*> den;

    int pocetJidel = 0;
    cout << "kolik jidel bude na den?" << endl;
    cin.clear();
    cin >> pocetJidel;
    cout << endl;
    bool pokracovat = true;
    while(pokracovat) {
        cout << endl;
        for(int i = 0; i < pocetJidel; ++i) {
            Pokrm* ulozJidlo;
            for(int i=0;i<3;i++){
            ulozJidlo = seznamJidel->vyberNahodneJidlo();
            if(pokrm->kontrolaPouzitiPokrmu(ulozJidlo) == true) {
                den.push_back(ulozJidlo);
                seznamJidel->vlozPouzityPokrm(ulozJidlo);
               // break;
            
            } else {

                continue;
            }
        }
        }
        pokracovat = false;
    }

    return den;
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
    cout << "Zadej pocet jidel na Pondeli" << endl;
    jidelnicek->pondeli = generujJidelnicekproDen();
    cout << "Zadej pocet jidel na Utery" << endl;
    jidelnicek->utery = generujJidelnicekproDen();
    cout << "Zadej pocet jidel na Stredu" << endl;
    jidelnicek->streda = generujJidelnicekproDen();
    cout << "Zadej pocet jidel na Ctvrtek" << endl;
    jidelnicek->ctvrtek = generujJidelnicekproDen();
    cout << "Zadej pocet jidel na Patek" << endl;
    jidelnicek->patek = generujJidelnicekproDen();
    celyJidelnicek->vlozJidelnicek(jidelnicek);
    pocetGenerovaniJidelnicku++;
    cout << endl << "vygenerovan tydenni jidelnicek" << pocetGenerovaniJidelnicku << endl;
}

void Jidelnicek::vytiskniJidelnicek()
{
    stringstream ss;
    ofstream outFile("jidelnicek.txt");
    if(!outFile) {
        cout << "Chyba" << endl;
    } else {
        for(Jidelnicek* jidelnicek : celyJidelnicek->getCelyJidelnicek()) {
            outFile << jidelnicek->vypis();
        }
        outFile.close();
    }
}

vector<Pokrm*> Jidelnicek::vytvorJidelnicekProDen()
{
    int x = 0;
    int velikostVectoru = seznamJidel->getSeznamJidel().size();
    vector<Pokrm*> den;
    bool pokracovat = true;
    char dalsi = 0;
    while(pokracovat) {
        jidlo->vypisJidlo();
        cout << endl;
        cout << "zadejte Id jidla" << endl;
        cin >> x;
        if(x >= velikostVectoru) {
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
    celyJidelnicek->vlozJidelnicek(jidelnicek); // celyJidelnicek.push_back(jidelnicek);
}