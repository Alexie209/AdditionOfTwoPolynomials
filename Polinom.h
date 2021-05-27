//
// Created by Alexie on 5/10/2021.
//

#ifndef PROIECTSDA_POLINOM_H
#define PROIECTSDA_POLINOM_H
#include <iostream>

class Polinom {
private:
    struct poli
    {
        float coeficient;   //coeficientul termenului
        int exponent;       //exponentul termenului
        poli* link;        //urmatorul termen
    }*p;
public:
    Polinom();             //Constructor
    void adauga(float coef, int exponent);     //Functie care adauga un termen in polinom
    void afiseaza_polinom();     //Functie care afiseaza un polinom
    void aduna_polinoamele(Polinom &p1, Polinom &p2);   //Functie care aduna 2 polinoame
    ~Polinom();        //Destructor
};


#endif //PROIECTSDA_POLINOM_H
