#include "Jidlo.hpp"
#include "SeznamJidel.hpp"
#include "Soubor.hpp"
using namespace std;

SeznamJidel* seznamJidel2;
Soubor* tridaSoubor;

Jidlo::Jidlo(int id, string nazev, int cena, int trida, string ingredience)
{
    this->id = id;
    this->nazev = nazev;
    this->cena = cena;
    this->trida = trida;
    this->ingredience = ingredience;
}

Jidlo::~Jidlo()
{
}

int idJidloNove = 0;
int idNapojNove = 0;

void Jidlo::ulozIngredience(string ingredience)
{
    string retezec = ingredience;
    string oddelovac = ",";
    string ulozIngredience;
    size_t pozice = 0;
    string slovo;

    for(int i = 0; (pozice = retezec.find(oddelovac)) != string::npos; i++) {
        slovo = retezec.substr(0, pozice);
        seznamIngredienci.push_back(slovo);
        retezec.erase(0, pozice + oddelovac.length());
    }
}

string Jidlo::vypisIngredience()
{
    stringstream ss;
    string ingred;
    for(auto i = seznamIngredienci.begin(); i != seznamIngredienci.end(); ++i) {
        ss << *i << ',';
    }

    getline(ss, ingred); // načtení ingrediencí s mezerou
    seznamIngr = ingred;
    return ingred;
}

vector<string> Jidlo::getIngredience1()
{
    return seznamIngredienci;
}

void Jidlo::vypis()
{
    Pokrm::vypis();
    cout << "Ingredience: " << vypisIngredience() << "    ";
}

void Jidlo::vypisJidlo()
{
    cout << "Dostupna jidla" << endl << "--------------------------------" << endl;
    for(Jidlo* jidlo : seznamJidel2->getSeznamJidel()) {
        jidlo->vypis();
        cout << endl;
    }
    cout << "Dostupne napoje" << endl << "--------------------------------" << endl;
    for(Napoj* napoj : seznamJidel2->getSeznamNapoju()) {
        napoj->vypis();
        cout << endl;
    }
}

void Jidlo::vytvorJidlo()
{
    idJidloNove = seznamJidel2->getSeznamJidel().size();
    idNapojNove = seznamJidel2->getSeznamNapoju().size();
    char vytvoritJidlo;
    bool pokracovat = true;
    char jeNapoj;
    string nazev;
    int obsah;
    double cena;
    int trida;
    string ingredience;
    string vstup;
    bool chyba = true;
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
                while(chyba) {
                    try {
                        cin >> vstup;
                        cena = stod(vstup);
                        chyba = false;
                    } catch(invalid_argument& exception) {
                        cout << "Nebylo zadano cislo" << endl;
                    } catch(out_of_range& exception) {
                        cout << "Cislo je prilis velke (nebo prilis male)" << endl;
                    }
                }
                cout << " zadejte obsah: ";
                chyba = true;
                while(chyba) {
                    try {
                        cin >> vstup;
                        obsah = stoi(vstup);
                        chyba = false;
                    } catch(invalid_argument& exception) {
                        cout << "Nebylo zadano cislo" << endl;
                    } catch(out_of_range& exception) {
                        cout << "Cislo je prilis velke (nebo prilis male)" << endl;
                    }
                }
                Napoj* napoj = new Napoj(idNapojNove, nazev, cena, trida, ingredience, obsah);
                seznamJidel2->vlozNapoj(napoj);
                idNapojNove++;
            } else if(jeNapoj == 'n') {
                cout << "zadejte nazev pokrmu: ";
                cin.ignore();
                getline(cin, nazev);
                cout << " zadejte cenu: ";
                chyba = true;
                while(chyba) {
                    try {
                        cin >> vstup;
                        cena = stod(vstup);
                        chyba = false;
                    } catch(invalid_argument& exception) {
                        cout << "Nebylo zadano cislo" << endl;
                    } catch(out_of_range& exception) {
                        cout << "Cislo je prilis velke (nebo prilis male)" << endl;
                    }
                }
                cout << " zadejte tridu: ";
                chyba = true;
                while(chyba) {
                    try {
                        cin >> vstup;
                        trida = stoi(vstup);
                        chyba = false;
                    } catch(invalid_argument& exception) {
                        cout << "Nebylo zadano cislo" << endl;
                    } catch(out_of_range& exception) {
                        cout << "Cislo je prilis velke (nebo prilis male)" << endl;
                    }
                }
                cout << "zadejte zakladni ingredience oddelene carkou: ";
                cin.ignore();
                getline(cin, ingredience);
                Jidlo* jidlo = new Jidlo(idJidloNove, nazev, cena, trida, ingredience);
                jidlo->ulozIngredience(ingredience);
                seznamJidel2->vlozJidlo(jidlo);
                idJidloNove++;
            } else {
                cout << "spatne zadani";
            }
        } else {
            pokracovat = false;
        }
    }
}

bool Jidlo::kontrolaPouzitiJidla(Jidlo* nahodneJidlo)
{
        for(int i = 0; i < seznamJidel2->getPouzitePokrmy().size(); ++i) {
            
            if(seznamJidel2->getPouzitePokrmy()[i] != nahodneJidlo->getId()) {
                
                return true;
            } else {
                return false;
            }
            
        }
    
    
    //return true;
}
bool Jidlo::kontrolaIngredienciJidla(Jidlo* nahodneJidlo, int predchoziPocetJidel){
    for(int i = 0;i < predchoziPocetJidel; ++i){
       // seJidel->getPredchoziIngredience()
       
       /*
       string retezec = ingredience;
    string oddelovac = ",";
    string ulozIngredience;
    size_t pozice = 0;
    string slovo;

    for(int i = 0; (pozice = retezec.find(oddelovac)) != string::npos; i++) {
        slovo = retezec.substr(0, pozice);
        seznamIngredienci.push_back(slovo);
        retezec.erase(0, pozice + oddelovac.length());
    }
    */
    }
}
