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

int kontrola = 0;
int poslednijidlo = NULL;
bool Jidlo::kontrolaPouzitiJidla(Jidlo* nahodneJidlo)
{
    bool proslo = false;
    if(seznamJidel2->getPouzitePokrmy().size() == seznamJidel2->getSeznamJidel().size()){
        poslednijidlo = seznamJidel2->getPouzitePokrmy().back();
        seznamJidel2->vynulujPouzitePokrmy();
    }
    if (seznamJidel2->getPouzitePokrmy().size() == NULL){
       cout << "prazdny seznam pouzitych jidel: vracim true(pouzij jidlo)" << endl;
       proslo = true;
    } else {
        for( int i = 0; i < seznamJidel2->getPouzitePokrmy().size(); ++i) {
            
       
    cout << "iterator pouzitych pokrmu je: " << i <<endl;    
        cout<< "porovnavam: " << seznamJidel2->getPouzitePokrmy()[i] << " a " << nahodneJidlo->getId() << endl;

        if(seznamJidel2->getPouzitePokrmy()[i] != nahodneJidlo->getId() && poslednijidlo != nahodneJidlo->getId()) {
            poslednijidlo = NULL;
            

            return true;
        } else {
            continue;
        }
        return proslo;
    }
    return false;
    }
        
    

    // return true;
}
bool Jidlo::kontrolaIngredienciJidla(Jidlo* nahodneJidlo, int predchoziPocetJidel)
{
    bool znovu = true;
    // bool pravda = false;
    int nepravda = 0;
    vector<vector<string> > ingredienceNahodnehoJidla;
    vector<vector<string> > ingrediencePredchozihoJidla;

    ingredienceNahodnehoJidla.push_back(nahodneJidlo->getIngredience1());
    for(unsigned int i = 0; i < seznamJidel2->getPredchoziIngredience().size(); ++i) {
        cout << endl << "zkopirovani do vectoru, prvni forcyklus" << endl;
        ingrediencePredchozihoJidla.push_back(seznamJidel2->getPredchoziIngredience()[i]);

        /*
        vector<string>::const_iterator first = seznamJidel2->getPredchoziIngredience()[i].end() - predchoziPocetJidel;
        vector<string>::const_iterator last = seznamJidel2->getPredchoziIngredience()[i].end();
        vector<string> newVec(first, last);
         */

        for(auto it1 = ingredienceNahodnehoJidla.cbegin(); it1 != ingredienceNahodnehoJidla.cend(); ++it1) {
            cout << "druhy forcyklus" << endl;
            auto it2 = find(ingrediencePredchozihoJidla.cbegin(), ingrediencePredchozihoJidla.cend(), *it1);
            if(it2 != ingrediencePredchozihoJidla.cend()) {
                cout << "podminka if" << endl;
                // pravda = true;
                nepravda++;
                return true;
            }
        }
    }


ingredienceNahodnehoJidla.clear();
ingrediencePredchozihoJidla.clear();

cout << "Kontrola ingredienci prosla: " << nepravda << " krat" << endl;
kontrola++;
if(kontrola == 2) {
    seznamJidel2->vynulujPredchoziIngredience();
}

// return false;

/*
for (auto it1 = v1.cbegin(); it1 != v1.cend(); ++it1)
{
    auto it2 = find(v2.cbegin(), v2.cend(), *it1);
    if (it2 != v2.cend())
    {
        matches.push_back(make_pair(it1 - v1.cbegin(), it2 - v2.cbegin()));
    }
}
*/
}
