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
        if(pondeli.size() > 0) {
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
};

#endif // JIDELNICEK_H
