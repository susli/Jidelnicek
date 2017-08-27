#include "CelyJidelnicek.hpp"

vector<Jidelnicek*> cJidelnicek;
vector<Jidelnicek*> CelyJidelnicek::getCelyJidelnicek()
{
    return cJidelnicek;
}
void CelyJidelnicek::vlozJidelnicek(Jidelnicek* jidelnicek){
    cJidelnicek.push_back(jidelnicek);
}
