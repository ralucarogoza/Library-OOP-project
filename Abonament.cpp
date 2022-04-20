#include "Abonament.h"
#include <iostream>


int Abonament::perioada=2;
float Abonament::pret=20;
int Abonament::numarMaximCarti=15;


Abonament::Abonament(){}

Abonament::Abonament(int numarCartiImprumutate){
    this->numarCartiImprumutate=numarCartiImprumutate;
}

Abonament::Abonament(const Abonament& ab){
    numarCartiImprumutate=ab.numarCartiImprumutate;
}

Abonament& Abonament::operator=(const Abonament& ab){
    if(this!=&ab){
        numarCartiImprumutate=ab.numarCartiImprumutate;
    }
    return *this;
}


void Abonament::setNumarCartiImprumutate(int numarCartiImprumutate){
    this->numarCartiImprumutate=numarCartiImprumutate;
}

int Abonament::getNumarMaximCarti(){
    return this->numarMaximCarti;
}

int Abonament::getNumarCartiImprumutate(){
    return this->numarCartiImprumutate;
}

int Abonament::getPerioada(){
    return this->perioada;
}

float Abonament::getPret(){
    return this->pret;
}


std::istream& operator>>(std::istream& is, Abonament& ab){
    std::cout<<"Ati ales un abonament normal\n";
    std::cout<<"Perioada abonamentului: "; std::cout<<ab.getPerioada(); std::cout<<" luni\n";
    std::cout<<"Pretul abonamentului: "; std::cout<<ab.getPret(); std::cout<<" lei\n";
    while(true){
        try{
            std::cout<<"Numarul maxim de carti care pot fi imprumutate: "; std::cout<<ab.getNumarMaximCarti(); std::cout<<'\n';
            std::cout<<"Introduceti numarul de carti imprumutate: "; is>>ab.numarCartiImprumutate; std::cout<<'\n';
            if(ab.numarMaximCarti<ab.numarCartiImprumutate)
                throw ab.numarCartiImprumutate;
            break;
        }
        catch(int x){
            std::cout<<"Numarul de carti care pot fi imprumutate este mai mare decat numarul maxim de carti.\n";
            std::cout<<"Numarul maxim de carti care pot fi imprumutate: "; std::cout<<ab.getNumarMaximCarti(); std::cout<<'\n';
            std::cout<<"Reintroduceti numarul de carti imprumutate: "; is>>ab.numarCartiImprumutate; std::cout<<'\n';
        }
    }
    ab.setNumarCartiImprumutate(ab.numarCartiImprumutate);
    return is;
}

std::ostream& operator<<(std::ostream& os, Abonament& ab){
    os<<"Perioada abonament: "<<ab.perioada<<" luni\n";
    os<<"Pret abonament: "<<ab.pret<<" lei\n";
    os<<"Numarul maxim de carti care pot fi imprumutate: "<<ab.numarMaximCarti<<'\n';
    os<<"Numarul de carti imprumutate: "<<ab.numarCartiImprumutate<<'\n';
    return os;
}

float Abonament::calculeazaAbonament(){
    float plata=this->pret*this->perioada;
    return plata;
}