#include <iostream>
#include <vector>
#include "Biblioteca.h"
#include "Abonat.h"


Biblioteca::Biblioteca(){}

Biblioteca::Biblioteca(std::string denumire, std::vector<Abonat> abonati){
    this->denumire=denumire;
    this->abonati=abonati;
}

Biblioteca::Biblioteca(const Biblioteca& b){
    denumire=b.denumire;
    for(Abonat a: b.abonati){
        abonati.push_back(a);
    }
}

Biblioteca::~Biblioteca(){
    this->abonati.clear();
}

Biblioteca& Biblioteca::operator=(Biblioteca& b){
    if(this!=&b){
        denumire=b.denumire;
        abonati=b.abonati;
    }
    return *this;
}


void Biblioteca::setDenumireBiblioteca(std::string denumire){
    this->denumire=denumire;
}

std::string Biblioteca::getDenumireBiblioteca() {
    return this->denumire;
}

std::istream& operator>>(std::istream& is, Biblioteca& b){
    is>>b.denumire;
    std::cout<<'\n';
    b.setDenumireBiblioteca(b.denumire);
    return is;
}


std::ostream& operator<<(std::ostream& os, Biblioteca& b) {
    int i=1;
    os<<"Denumire biblioteca: "<<b.denumire<<'\n';
    if(b.abonati.size()==0)
        os<<"Nu exista niciun abonat\n";
    for(Abonat a: b.abonati){
        std::cout<<"Abonatul "<<i<<":\n";
        i++;
        os<<a<<'\n';
    }
    return os;
}


void Biblioteca::adaugaAbonat(Abonat& a){
    abonati.push_back(a);
}

int Biblioteca::numarAbonati(){
    Abonat* a;
    return a->getNumarAbonati();
}

float Biblioteca::sumaIncasata(){
    float s=0;
    for(Abonat a: this->abonati)
        s=s+a.cheltuieliAbonat();
    return s;
}
