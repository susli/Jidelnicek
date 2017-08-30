#include "Pokrm.hpp"
#include "SeznamJidel.hpp"
#include <iostream>
#include <ctime>     // std::time
#include <cstdlib>   // std::rand, std::srand
#include <algorithm> // std::random_shuffle
#include <iterator>

SeznamJidel* seJidel;

int Pokrm::getId()
{
    return id;
}

string Pokrm::getNazev()
{
    return nazev;
}

int Pokrm::getCena()
{
    return cena;
}

int Pokrm::getTrida()
{
    return trida;
}

string Pokrm::getIngredience()
{
    return ingredience;
}

int Pokrm::getObjem()
{
    return nic;
}

void Pokrm::vypis()
{
    cout << "Id: " << Pokrm::getId() << "    "
         << "Nazev Jidla: " << Pokrm::getNazev() << "   "
         << "Cena: " << Pokrm::getCena() << "   "
         << "Trida: " << Pokrm::getTrida() << "   ";
}

bool Pokrm::kontrolaPouzitiPokrmu(Pokrm* nahodneJidlo)
{
        for(int i = 0; i < seJidel->getPouzitePokrmy().size(); ++i) {
            
            if(seJidel->getPouzitePokrmy()[i] != nahodneJidlo->getId()) {
                
                return true;
            } else {
                return false;
            }
            
        }
    
    
    //return true;
}
bool Pokrm::kontrolaIngredienciPokrmu(Pokrm* nahodneJidlo, int predchoziPocetJidel){
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
