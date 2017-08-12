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
            for(int i; i < pondeli.size(); i++) {
                // cout << "pondeli" << endl;
                pondeli[i]->vypis();
                cout << endl;
            }
        }
        if(utery.size() != NULL) {
            cout << "Utery: " << endl;
            for(int i; i < utery.size(); i++) {
                // cout << "utery" << endl;
                utery[i]->vypis();
                cout << endl;
            }
        }
        if(streda.size() != NULL) {
            cout << "Streda: " << endl;
            for(int i; i < streda.size(); i++) {
                // cout << "streda" << endl;
                streda[i]->vypis();
                cout << endl;
            }
        }
        if(ctvrtek.size() != NULL) {
            cout << "Ctvrtek: " << endl;
            for(int i; i < ctvrtek.size(); i++) {
                // cout << "ctvrtek" << endl;
                ctvrtek[i]->vypis();
                cout << endl;
            }
        }
        if(patek.size() != NULL) {
            cout << "Patek: " << endl;
            for(int i; i < patek.size(); i++) {
                // cout << "patek" << endl;
                patek[i]->vypis();
                cout << endl;
            }
        }
    }
};

#endif // JIDELNICEK_H
