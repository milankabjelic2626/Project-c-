#pragma once
#include <string>
using namespace std;
class Artikal
{
public:
    Artikal(void);
    ~Artikal(void);
    
    void setKonto(int);
    void setNaziv(string);
    void setCena(double);
    void setKolicina(int);
    void setProdato(int);
    
    int getKonto();
    string getNaziv();
    double getCena();
    int getKolicina();
    int getProdato();
    
protected:
    int konto;
    string naziv;
    double cena;
    int kolicina;
    int prodato;
};