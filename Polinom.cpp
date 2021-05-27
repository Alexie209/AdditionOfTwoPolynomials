//
// Created by Alexie on 5/10/2021.
//

#include "Polinom.h"

Polinom::Polinom() {      //constructorul
    p = NULL;
}

void Polinom::adauga(float coef, int exponent) {

//    Functia adauga in polinom un termen cu coeficientul coef si exponentul exponent
//    coef-float, coeficientul termenului
//    exponent-int, exponentul termenului

    poli *temp =p;
    if (temp == NULL)
    {
        temp = new poli;
        p = temp;
    }
    else
    {
        while(temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = new poli;
        temp = temp->link;
    }
    temp->coeficient = coef;
    temp->exponent = exponent;
    temp->link = NULL;
}

void Polinom::afiseaza_polinom() {
//
//    Functia afiseaza un ploinom deja adaugat
//    Inaintea exponentului se va trece '^'
//
    poli *temp = p;
    int f = 0;

    std::cout<<std::endl;
    while(temp != NULL)
    {
        if(f != 0)
        {
            if(temp->coeficient >= 0)
            {
                std::cout << " + ";
            }
            else
            {
                std::cout << " ";
            }
        }
        if(temp->exponent != 0)
        {
            std::cout << temp->coeficient <<"x^" << temp->exponent;
        }
        else
        {
            std::cout << temp->coeficient;
        }
        temp = temp -> link;
        f = 1;
    }
}

void Polinom::aduna_polinoamele(Polinom &p1, Polinom &p2) {
//
//    Functia aduna 2 polinoame deja create
//    Pentru aceasta se cauta exponentele comune ale celor 2 polinoame
//    pentru a aduna coeficientii lor
//    De asemenea, functia cauta cel mai mare exponent dintre cele 2 polinoame
//    pentru ca polinomul rezultat sa fie ordonat
//
    poli *z;
    if(p1.p == NULL && p2.p == NULL)
        return;
    poli *temp1, *temp2;
    temp1 = p1.p;
    temp2 = p2.p;
    while(temp1 != NULL && temp2 != NULL)
    {
        if(p == NULL)
        {
            p = new poli;
            z = p;
        }
        else
        {
            z->link = new poli;
            z = z->link;
        }
        if(temp1->exponent < temp2->exponent)    //compara exponentii celor 2 polinoame
        {
            z->coeficient = temp2->coeficient;
            z->exponent = temp2->exponent;
            temp2 = temp2->link;
        }
        else
        {
            if(temp1->exponent > temp2->exponent)
            {
                z->coeficient = temp1->coeficient;
                z->exponent = temp1->exponent;
                temp1 = temp1->link;
            }
            else
            {
                if(temp1->exponent == temp2->exponent)
                {
                    z->coeficient = temp1->coeficient + temp2->coeficient;
                    z->exponent = temp1->exponent;
                    temp1 = temp1->link;
                    temp2 = temp2->link;
                }
            }
        }
    }
    while(temp1 != NULL)
    {
        if(p == NULL)
        {
            p = new poli;
            z = p;
        }
        else
        {
            z->link = new poli;
            z = z->link;
        }
        z->coeficient = temp1->coeficient;
        z->exponent = temp1->exponent;
        temp1 = temp1->link;
    }
    while(temp2 != NULL)
    {
        if(p == NULL)
        {
            p = new poli;
            z = p;
        }
        else
        {
            z->link = new poli;
            z = z->link;
        }
        z->coeficient = temp2->coeficient;
        z->exponent = temp2->exponent;
        temp2 = temp2->link;
    }
    z->link = NULL;
}

Polinom::~Polinom() {
//
//    Desructorul
//    Distruge polinoamele create
//
    poli *q;
    while(p != NULL)
    {
        q = p->link;
        delete p;
        p = q;
    }
}

