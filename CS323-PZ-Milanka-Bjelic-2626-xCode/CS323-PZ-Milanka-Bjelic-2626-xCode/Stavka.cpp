#include <stdio.h>
#include "Stavka.hpp"

Stavka::Stavka(void)
{
}

Stavka::~Stavka(void)
{
}

int Stavka::getKolicina()
{
    return this->kolicina;
}

int Stavka::getKonto()
{
    return this->konto;
}

void Stavka::setKolicina(int kolicina)
{
    this->kolicina = kolicina;
}

void Stavka::setKonto(int konto)
{
    this->konto = konto;
}