#pragma once

#include <vector>
#include <string>

#include <Pokrm.h>
#include <Jidlo.h>


namespace std
{

class SeznamJidel
{
    
    vector<Jidlo*> seznamJidel;
    
    
public:
    SeznamJidel(vector<Jidlo*> seznamJidel);
    ~SeznamJidel();
    
    void vlozJidlo();
    void odstranJidlo();
    Jidlo* vyberNahodneJidlo();
    
    

};

}

