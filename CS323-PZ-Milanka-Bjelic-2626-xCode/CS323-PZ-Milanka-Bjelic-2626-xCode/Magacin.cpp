#include <stdio.h>
#include "Magacin.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

Magacin::Magacin(void)
{
}

Magacin::Magacin(string imeFajla)
{
    this->ucitajPodatke(imeFajla);
}

Magacin::~Magacin(void)
{
}

void Magacin::ucitajPodatke(string imeFajla)
{
    ifstream inFile(imeFajla);
    // otvara tok za ucitavanje iz baze
    if (!inFile.good())
    {
        // proverava da li postoji takav fajl i da li je otvoren
        cout << "Nema fajla!\n";
    }
    else
    {
        string line;
        // pomocni string za ucitavanje jedne linije
        while (getline(inFile, line))
        {
            istringstream linestream(line);
            string item;
            int itemNum = 0;
            Artikal artikal;
            // pomocne promenljive za razdeljivanje vrednosti sa zarezom
            
            while (getline(linestream, item, ','))
            {
                itemNum++;
                
                switch (itemNum)
                {
                    case 1:
                        int konto;
                        istringstream(item) >> konto;
                        // upis iz toka u promenljivu konto
                        artikal.setKonto(konto);
                        break;
                    case 2:
                        artikal.setNaziv(item);
                        break;
                    case 3:
                        double cena;
                        istringstream(item) >> cena;
                        artikal.setCena(cena);
                        break;
                    case 4:
                        int kolicina;
                        istringstream(item) >> kolicina;
                        artikal.setKolicina(kolicina);
                        break;
                    case 5:
                        int prodato;
                        istringstream(item) >> prodato;
                        artikal.setProdato(prodato);
                        break;
                }
            }
            
            this->artikli.push_back(artikal);
            // dodavanje objekta artikal u vektor artikli
        }
    }
    inFile.close();
}

void Magacin::upisiPodatke(string imeFajla)
{
    ofstream outFile;
    outFile.open(imeFajla, ios::trunc);
    // otvara tok za upis u bazu
    if (!outFile.good())
    {
        // proverava da li postoji takav fajl i da li je otvoren
        cout << "Nema fajla!\n";
    }
    else
    {
        for (int i = 0; i < this->artikli.size(); i++)
        {
            // ide od prvog objekta u vektoru do poslednje i upisuje vrednosti u bazu
            outFile << this->artikli.at(i).getKonto() << ","
            << this->artikli.at(i).getNaziv() << ","
            << this->artikli.at(i).getCena() << ","
            << this->artikli.at(i).getKolicina() << ","
            << this->artikli.at(i).getProdato() << endl;
        }
    }
    outFile.close();
}

bool Magacin::proveriKonto(int konto, bool prikaziGresku) {
    // funkcija koja proverava pri dodavanju novog artikla da li taj konto vec postoji
    for (unsigned int i = 0; i < this->artikli.size(); i++)
    {
        if (konto == this->artikli.at(i).getKonto()) {
            if (prikaziGresku) {
                cout << "Konto vec postoji" << endl;
            }
            return true;
            // vraca da je true ako pronadje vec taj konto
        }
    }
    // vraca false ako taj konto ne postoji
    return false;
}

void Magacin::dodajArtikal()
{
    Artikal artikal;
    int konto;
    
    do {
        cout << "Unesite konto artikla: ";
        cin >> konto;
    } while (this->proveriKonto(konto, true));
    // dok postoji konto ispisuje gresku
    // ako ne postoji konto trazi naziv,cenu...
    artikal.setKonto(konto);
    
    cout << "Unesite naziv artikla: ";
    string naziv;
    cin >> naziv;
    artikal.setNaziv(naziv);
    
    cout << "Unesite cena artikla: ";
    double cena;
    cin >> cena;
    artikal.setCena(cena);
    
    cout << "Unesite kolicinu artikla: ";
    int kolicina;
    cin >> kolicina;
    artikal.setKolicina(kolicina);
    
    cout << "Uneti broj prodatih proizvoda: ";
    int prodato;
    cin >> prodato;
    artikal.setProdato(prodato);
    
    // dodaje novi objekat u vektor
    this->artikli.push_back(artikal);
    
    cout << endl << "Artikal je uspesno dodat" << endl;
}

void Magacin::listaArtikala() {
    
    for (int i = 0; i < this->artikli.size(); i++)
    {
        // ide od prvog objekta u vektoru do poslednje i stampa vrednosti
        cout << this->artikli.at(i).getKonto() << " - "
        << this->artikli.at(i).getNaziv() << " - "
        << this->artikli.at(i).getCena() << " - "
        << this->artikli.at(i).getKolicina() << " - "
        << this->artikli.at(i).getProdato() << endl;
    }
}

bool Magacin::obrisiArtikal()
{
    
    this->listaArtikala();
    // stampa sve artikle pre brisanja da mozemo da ih vidimo
    
    int konto;
    cout << "Unesite konto artikla: ";
    cin >> konto;
    for (unsigned int i = 0; i < this->artikli.size(); i++)
    {
        if (konto == this->artikli.at(i).getKonto()) {
            // proverava da li je unet konto jednak nekom kontu u vektoru
            this->artikli.erase(this->artikli.begin() + i);
            // erase radi brisanje objekta iz vektora, parametar predstavlja poziciju elementa za brisanje
            cout << "Artikal je uspesno obrisan" << endl;
            return true;
        }
    }
    
    cout << "Artikal sa unetim kontom ne postoji" << endl;
    return false;
}

vector<Artikal> Magacin::getArtikli()
{
    // geter koji vraca ceo vektor artikala
    return this->artikli;
}

Artikal* Magacin::getArtikal(int konto) {
    // geter koji vraca jedan artikal iz vektora
    for (unsigned int i = 0; i < this->artikli.size(); i++)
    {
        if (konto == this->artikli.at(i).getKonto()) {
            return &this->artikli.at(i);
            // da bi se poslao pokazivac umesto reference
        }
    }
    
    return nullptr;
    // pointer usmeren ni na sta
}