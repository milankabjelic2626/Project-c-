#include <stdio.h>
#include "Kasa.hpp"
#include "Magacin.hpp"
#include <iostream>

Kasa::Kasa(void)
{
}

Kasa::~Kasa(void)
{
}

void Kasa::dodajStavku(Magacin& magacin)
{
    Stavka stavka;
    int konto;
    
    magacin.listaArtikala();
    // stampa celu listu artikala
    
    cout << "Unesite konto artikla: ";
    cin >> konto;
    
    while (!magacin.proveriKonto(konto, false)) {
        cout << "Artikal sa unetim kontom ne postoji!" << endl << "Unesite konto artikla: ";
        cin >> konto;
    }
    
    stavka.setKonto(konto);
    // kad pronadje odgovarajuci konto u listi dodeljuje ga objektu stavka
    
    cout << "Unesite kolicinu artikla: ";
    int kolicina;
    cin >> kolicina;
    stavka.setKolicina(kolicina);
    
    this->stavke.push_back(stavka);
    // stavlja u vektor stavke objekat stavka
    
    cout << endl << "Artikal je uspesno dodat u kasu" << endl;
}

void Kasa::prikaziRacun(Magacin& magacin) {
    double ukupnaCena = 0;
    cout << endl << "      Prodavnica mesovite robe";
    cout << endl << "             *MIMA* ";
    cout << endl << "     ul. Nikole Tesle br. 40 ";
    cout << endl << "           SRBIJA, SID ";
    
    cout << endl << "  -------------------------------------\n";
    cout << endl << "  -------------------------------------\n";
    for (unsigned int i = 0; i < this->stavke.size(); i++)
    {
        cout << "  Naziv: " << magacin.getArtikal(this->stavke.at(i).getKonto())->getNaziv() << "   x " << this->stavke.at(i).getKolicina() << endl;
        // iz vektora magacina uzimamo artikal sa izabranim kontom pa uzimamo njegov naziv i kolicinu
        cout << "  Cena: " << magacin.getArtikal(this->stavke.at(i).getKonto())->getCena() << " rsd\n" << endl;
        ukupnaCena += magacin.getArtikal(this->stavke.at(i).getKonto())->getCena() * this->stavke.at(i).getKolicina();
    }
    
    cout << endl << "  -------------------------------------\n";
    cout << endl << "  --------------------------------------";
    cout << endl << "  Ukupno: " << ukupnaCena << "rsd";
    cout << endl << "		Vlasnik: Milanka Bjelic";
    cout << endl << "			Hvala na poseti";
    cout << endl << "  -------------------------------------\n";
    cout << endl << " ________________________________________\n" << endl;
}