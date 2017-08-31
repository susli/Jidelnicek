#include "Jidlo.hpp"
#include "SeznamJidel.hpp"
#include "Soubor.hpp"
using namespace std;

SeznamJidel* seznamJidel2;
Soubor* tridaSoubor;

Jidlo::Jidlo(int id, string nazev, double cena, int trida, string ingredience)
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
}
void Jidlo::vypisNapoje()
{
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
                cout << "zadejte zakladni ingredience oddelene carkou a zakoncene carkou: ";
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

bool Jidlo::najdiShodu(int hledanyPrvek, vector<int> seznamPrvku)
{
    for(auto i = seznamPrvku.begin(); i != seznamPrvku.end(); ++i) {
        cout << "Porovnavam: " << hledanyPrvek << " a " << seznamPrvku[*i] << endl;
        if(hledanyPrvek == seznamPrvku[*i]) {
            return true;
        }
    }
    return false;
}

int kontrola = 0;
int poslednijidlo = 0;

bool Jidlo::kontrolaPouzitiJidla(Jidlo* nahodneJidlo)
{
    if(seznamJidel2->getPouzitePokrmy().size() == seznamJidel2->getSeznamJidel().size()) {
        poslednijidlo = seznamJidel2->getPouzitePokrmy().back();
        seznamJidel2->vynulujPouzitePokrmy();
    }
    if(seznamJidel2->getPouzitePokrmy().size() == 0) {
        if(poslednijidlo != nahodneJidlo->getId()) {
            cout << "prazdny seznam pouzitych jidel: vracim true(pouzij jidlo)" << endl;
            return true;
        } else {
            if(najdiShodu(nahodneJidlo->getId(), seznamJidel2->getPouzitePokrmy()) == false) {
                return true;
            }
        } 

    } else {

        if(najdiShodu(nahodneJidlo->getId(), seznamJidel2->getPouzitePokrmy()) == false) {
            return true;
        }
        return false;
    }
    return false;
}
bool Jidlo::kontrolaIngredienciJidla(Jidlo* nahodneJidlo)
{
    int nepravda = 0;
    vector<vector<string> > ingredienceNahodnehoJidla;
    vector<vector<string> > ingrediencePredchozihoJidla;

    ingredienceNahodnehoJidla.push_back(nahodneJidlo->getIngredience1());
    for(unsigned int i = 0; i < seznamJidel2->getPredchoziIngredience().size(); ++i) {
        cout << endl << "zkopirovani do vectoru, prvni forcyklus" << endl;
        ingrediencePredchozihoJidla.push_back(seznamJidel2->getPredchoziIngredience()[i]);

        for(auto it1 = ingredienceNahodnehoJidla.cbegin(); it1 != ingredienceNahodnehoJidla.cend(); ++it1) {
            cout << "druhy forcyklus" << endl;
            auto it2 = find(ingrediencePredchozihoJidla.cbegin(), ingrediencePredchozihoJidla.cend(), *it1);
            if(it2 != ingrediencePredchozihoJidla.cend()) {
                cout << "podminka if" << endl;
                nepravda++;
                seznamJidel2->vlozPredchoziIngredience(nahodneJidlo);
                return true;
            }else{
                continue;
            }
            continue;
        }
    }

    ingredienceNahodnehoJidla.clear();
    ingrediencePredchozihoJidla.clear();

    cout << "Kontrola ingredienci prosla: " << nepravda << " krat" << endl;
    kontrola++;
    
    if(kontrola == 2) {
        seznamJidel2->vynulujPredchoziIngredience();
    }
     
}
