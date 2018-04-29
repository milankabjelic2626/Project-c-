#include <stdio.h>
#include "Artikal.hpp"

Artikal::Artikal(void)
{
}

Artikal::~Artikal(void)
{
}

void Artikal::setKonto(int konto)
{
    this->konto = konto;
}
void Artikal::setNaziv(string naziv)
{
    this->naziv = naziv;
}
void Artikal::setCena(double cena)
{
    this->cena = cena;
}
void Artikal::setKolicina(int kolicina)
{
    this->kolicina = kolicina;
}
void Artikal::setProdato(int prodato)
{
    this->prodato = prodato;
}

int Artikal::getKonto()
{
    return this->konto;
}

string Artikal::getNaziv()
{
    return this->naziv;
}

double Artikal::getCena()
{
    return this->cena;
}

int Artikal::getKolicina()
{
    return this->kolicina;
}

int Artikal::getProdato()
{
    return this->prodato;
}