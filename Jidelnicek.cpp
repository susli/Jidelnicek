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

Jidelnicek::vypis()
{
    string jidelnicek = " ";
    if(pondeli.size() != 0) {
        cout << "Pondeli: " << endl;
        for(int i = 0; i < pondeli.size(); i++) {
            pondeli[i]->vypis();
            cout << endl;
        }
    }
    if(utery.size() > 0) {
        cout << "Utery: " << endl;
        for(int i = 0; i < utery.size(); i++) {
            utery[i]->vypis();
            cout << endl;
        }
    }
    if(streda.size() > 0) {
        cout << "Streda: " << endl;
        for(int i = 0; i < streda.size(); i++) {
            streda[i]->vypis();
            cout << endl;
        }
    }
    if(ctvrtek.size() > 0) {
        cout << "Ctvrtek: " << endl;
        for(int i = 0; i < ctvrtek.size(); i++) {
            ctvrtek[i]->vypis();
            cout << endl;
        }
    }
    if(patek.size() > 0) {
        cout << "Patek: " << endl;
        for(int i = 0; i < patek.size(); i++) {
            patek[i]->vypis();
            cout << endl;
        }
    }
}

/* přesunuto do CelyJidelnicek
void Jidelnicek::vypisJidelnicek()
{
    for(Jidelnicek* jidelnicek : celyJidelnicek->getCelyJidelnicek()) {
        jidelnicek->vypis();
        cout << endl << endl << endl;
    }
}
*/
vector<Pokrm*> Jidelnicek::generujJidelnicekproDen()
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
            ulozJidlo = seznamJidel->vyberNahodneJidlo();
            if(pokrm->kontrolaPokrmu(ulozJidlo) == true) {
                den.push_back(ulozJidlo);
                seznamJidel->vlozPouzityPokrm(ulozJidlo);

            } else {
                continue;
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
    // bool pokracovat = true;
    Jidelnicek* jidelnicek = new Jidelnicek;

    cout << "chcete vytvorit jidelnicek? a/n " << endl;
    cin >> generovatJidelnicek;

    if(generovatJidelnicek != 'a') {

        return;
    }

    // while(pokracovat) {

    jidelnicek->pondeli = generujJidelnicekproDen();

    jidelnicek->utery = generujJidelnicekproDen();

    jidelnicek->streda = generujJidelnicekproDen();

    jidelnicek->ctvrtek = generujJidelnicekproDen();

    jidelnicek->patek = generujJidelnicekproDen();

    //    pokracovat = false;
    //}

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
            // ss >>outFile;
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
