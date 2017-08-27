#pragma once
#include <vector>
#include "Jidelnicek.hpp"

using namespace std;

class CelyJidelnicek
{
public:
    
    vector<Jidelnicek*> getCelyJidelnicek();
    void vlozJidelnicek(Jidelnicek* jidelnicek);
};
