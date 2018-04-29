#pragma once
#include "Artikal.hpp"

class Stavka : public Artikal
{
    // Stavku koristimo za racun
public:
    Stavka(void);
    ~Stavka(void);
    
    void setKonto(int);
    void setKolicina(int);
    
    int getKonto();
    int getKolicina();
    
private:
    int konto;
    int kolicina;
};
