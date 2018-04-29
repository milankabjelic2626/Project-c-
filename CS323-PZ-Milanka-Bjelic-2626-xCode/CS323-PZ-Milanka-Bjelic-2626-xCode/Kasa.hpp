#pragma once
#include <vector>
#include "Stavka.hpp"
#include "Magacin.hpp"
class Kasa
{
public:
    Kasa(void);
    ~Kasa(void);
    
    void dodajStavku(Magacin&);
    void prikaziRacun(Magacin&);
    
private:
    vector<Stavka> stavke;
};
