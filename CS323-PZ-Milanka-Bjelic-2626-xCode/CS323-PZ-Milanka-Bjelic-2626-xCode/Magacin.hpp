#pragma once
#include <vector>
#include <string>
#include "Artikal.hpp"
using namespace std;

class Magacin
{
public:
    Magacin(void);
    Magacin(string);
    // konstruktor sa parametrom za ime fajla
    ~Magacin(void);
    
    void dodajArtikal();
    void listaArtikala();
    
    Artikal* getArtikal(int);
    vector<Artikal> getArtikli();
    
    bool proveriKonto(int, bool);
    // proverava da li postoji artikal pod tim rednim brojem
    bool obrisiArtikal();
    
    void upisiPodatke(string);
    
private:
    int brojArtikala;
    // istovremeno velicina vektora
    vector<Artikal> artikli;
    // vektor da bi mogla da manipulisem artiklima iz baze
    
    void ucitajPodatke(string);
    // funkcija za ucitavanje iz baze
};
