#include <iostream>
#include "Polinom.h"

using namespace std;
int main() {

//    16. Implementaţi o structură de date care să permită adunarea a
//    două polinoame de grad mare cu mulţi coeficienţi nuli.

    Polinom p1;
    int nr;
    cout<<"Primul polinom "<<endl;
    cout<<"Dati numarul de termeni ai polinomului: ";
    cin>>nr;
    float coef;
    int exp;
    for(int i=1;i<=nr;i++)
    {
        cout<<"Dati coeficientul si exponentul termenului: "<<endl;
        cout<<"Coeficient: ";
        cin>>coef;
        cout<<"Exponent: ";
        cin>>exp;
        p1.adauga(coef, exp);
    }
    cout<<"Primul polinom: ";
    p1.afiseaza_polinom();

    Polinom p2;
    int nr2;
    cout<<endl<<"Al doilea polinom "<<endl;
    cout<<"Dati numarul de termeni ai polinomului: ";
    cin>>nr2;
    float coef2;
    int exp2;
    for(int i=1;i<=nr2;i++)
    {
        cout<<"Dati coeficientul si exponentul termenului: "<<endl;
        cout<<"Coeficient: ";
        cin>>coef2;
        cout<<"Exponent: ";
        cin>>exp2;
        p2.adauga(coef2, exp2);
    }
    cout<<"Al doilea polinom: ";
    p2.afiseaza_polinom();
    cout<<endl;
    Polinom p3;
    p3.aduna_polinoamele(p1, p2);
    cout<<"--------------"<<endl;
    cout<<"Polinomul rezultat: ";
    p3.afiseaza_polinom();
    return 0;
}
