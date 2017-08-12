#ifndef JIDELNICEK_H
#define JIDELNICEK_H
#include <vector>
#include <Jidlo.h>

using namespace std;

class Jidelnicek
{

public:
    vector<Pokrm*> pondeli;
    vector<Pokrm*> utery;
    vector<Pokrm*> streda;
    vector<Pokrm*> ctvrtek;
    vector<Pokrm*> patek;

    vypis()
    {
        string jidelnicek = " ";
        if(pondeli.size() != NULL) {
            cout << "Pondeli: " << endl;
            for(unsigned int i; i < pondeli.size(); i++) {
                pondeli[i]->vypis();
                cout << endl;
            }
        }
        if(utery.size() != NULL) {
            cout << "Utery: " << endl;
            for(unsigned int i; i < utery.size(); i++) {
                utery[i]->vypis();
                cout << endl;
            }
        }
        if(streda.size() != NULL) {
            cout << "Streda: " << endl;
            for(unsigned int i; i < streda.size(); i++) {
                streda[i]->vypis();
                cout << endl;
            }
        }
        if(ctvrtek.size() != NULL) {
            cout << "Ctvrtek: " << endl;
            for(unsigned int i; i < ctvrtek.size(); i++) {
                ctvrtek[i]->vypis();
                cout << endl;
            }
        }
        if(patek.size() != NULL) {
            cout << "Patek: " << endl;
            for(unsigned int i; i < patek.size(); i++) {
                patek[i]->vypis();
                cout << endl;
            }
        }
    }
};

#endif // JIDELNICEK_H
