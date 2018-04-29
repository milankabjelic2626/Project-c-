#include <stdio.h>
#include <iostream>
#include <string>
#include "Magacin.hpp"
#include "Kasa.hpp"
using namespace std;

void menu(Magacin&, Kasa&);
void glavniMenu();
void magacinMenu(Magacin&);
void kasaMenu(Magacin&, Kasa&);

char glavniMenuIzbor = 0;
char magacinMenuIzbor = 0;
char kasaMenuIzbor = 0;

int main()
{
    Magacin* magacin = new Magacin("db.csv");
    Kasa* kasa = new Kasa();
    
    menu(*magacin, *kasa);
    
    delete magacin;
    delete kasa;
    
    return 0;
}

void menu(Magacin& magacin, Kasa& kasa)//po referenci da se ne bi iskopirali
{
    do {
        glavniMenu();
        switch (glavniMenuIzbor)
        {
                // izbor opcije u glavnom meniju
            case '1':
                do
                {
                    magacinMenu(magacin);
                } while (magacinMenuIzbor != '0');
                break;
            case '2':
                do
                {
                    kasaMenu(magacin, kasa);
                } while (kasaMenuIzbor != '0');
            case '0': {
                magacin.upisiPodatke("db.csv");
            }
        }
    } while (glavniMenuIzbor != '0');
}

void glavniMenu()
{
    // iscrtava glavni meni
    cout << "Glavni meni\n"
    << "Izaberite opciju\n"
    << "1 - Magacin\n"
    << "2 - Kasa\n"
    << "0 - Kraj\n"
    << "Opcija: ";
    // ceka unos
    cin >> glavniMenuIzbor;
}

void magacinMenu(Magacin &magacin)
{
    // iscrtava magacin meni
    cout << "Magacin meni\n"
    << "Izaberite opciju\n"
    << "1 - Dodavanje novog arikla\n"
    << "2 - Brisanje artikla\n"
    << "3 - Prikaz svih artikala\n"
    << "0 - Povratak u glavni menu\n"
    << "Opcija: ";
    // ceka unos opcije
    cin >> magacinMenuIzbor;
    
    switch (magacinMenuIzbor)
    {
            // izbor opcije
        case '1':
            cout << "Dodavanje novog arikla\n";
            magacin.dodajArtikal();
            break;
        case '2':
            cout << "Brisanje artikla\n";
            magacin.obrisiArtikal();
            break;
        case '3':
            cout << "Prikaz svih artikala\n";
            magacin.listaArtikala();
            break;
    }
}

void kasaMenu(Magacin &magacin, Kasa &kasa)
{
    // iscrtavanje menija za kasu
    cout << "Kasa menu\n"
    << "Izaberite opciju\n"
    << "1 - Napravi racun: \n"
    << "2 - Prikazi racun\n"
    << "0 - Povratak u glavni meni\n"
    << "Opcija: ";
    // ceka opciju
    cin >> kasaMenuIzbor;
    
    switch (kasaMenuIzbor)
    {
            // izbor opcije
        case '1':
            cout << "Dodaj stavku\n";
            kasa.dodajStavku(magacin);
            break;
        case '2':
            cout << "Prikazi racun\n";
            kasa.prikaziRacun(magacin);
            break;
    }
}
