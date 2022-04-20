#ifndef _ABONAMENTPREMIUM_H
#define _ABONAMENTPREMIUM_H
#include <iostream>
#include "Abonament.h"


class AbonamentPremium: public Abonament{
public:
    AbonamentPremium();
    AbonamentPremium(int, int);
    AbonamentPremium(const AbonamentPremium&);
    AbonamentPremium& operator=(AbonamentPremium);
    void setCartiAditionale(int);
    float getCostSuplimentarCarte();
    int getCartiAditionale();
    friend std::istream& operator>>(std::istream&, AbonamentPremium&);
    friend std::ostream& operator<<(std::ostream&, AbonamentPremium&);
    float calculeazaAbonament();
private:
    static float costSuplimentarCarte;
    int cartiAditionale;
};


#endif //_ABONAMENTPREMIUM_H

