#include <iostream>
using namespace std;
#include "Ensemble.h"

int main(int argc, char const *argv[])
{
    /*cout << "------------- TEST 1-------"<<endl;
    Ensemble e1;
    e1.Afficher();
    Ensemble e2(10);
    e2.Afficher();
    Ensemble e3(0);
    e3.Afficher();
    */

    /*cout << "------------- TEST 2-------"<<endl;
    int tab[5]={7,1,4,9,8};
    int tab2[5]={3,3,4,4,5};
    Ensemble e4(tab,5);
    Ensemble e5(tab2,5);
    e4.Afficher();
    e5.Afficher();
    */

    /*cout << "------------- TEST 3-------"<<endl;
    int tab[5]={7,1,4,9,8};
    int tab2[5]={3,3,4,4,5};
    int tab3[5]={1,7,4,9,8};
    Ensemble e1(tab,5);
    Ensemble e2(tab2,5);
    Ensemble e3(tab3,5);
    Ensemble e4;
    cout<<"Différents: "<<e1.EstEgal(e2)<<endl;
    cout<<"Egaux: "<<e1.EstEgal(e3)<<endl;
    cout<<"Différents2: "<<e1.EstEgal(e4)<<endl;
    */

    /* TEST 4
    int tab[5]={7,1,4,9,8};
    int tab2[3]={7,8,9};
    int tab3[5]={1,7,4,9,8};
    Ensemble e1(tab,5);
    Ensemble e2(tab2,5);
    Ensemble e3(tab3,5);
    cout<<"INCLUSION_LARGE: "<<e1.EstInclus(e3)<<endl;
    cout<<"INCLUSION_STRICTE: "<<e2.EstInclus(e1)<<endl;
    cout<<"NON_INCLUSION: "<<e1.EstInclus(e2)<<endl;
    */

    /*int tab[5]={7,1,4,9,8}; TEST 5
    Ensemble e1(tab,5);
    Ensemble e2;
    cout<<"PLEIN ET PRESENT-->DEJA_PRESENT: "<<e1.Ajouter(1)<<endl;
    cout<<"PLEIN ET NON PRESENT ->PLEIN: "<<e1.Ajouter(3)<<endl;
    cout<<"NON PRESENT ET NON PLEIN ->AJOUTE: "<<e2.Ajouter(3)<<endl;
    cout <<"Affichage du nouveau ensemble:"<<endl;
    e2.Afficher();
    cout<<"PRESENT ET NON PLEIN->DEJA_PRESENT: "<<e2.Ajouter(3)<<endl;
    */

   /* TEST 6
   Ensemble e1;
   int tab[5]={7,1,4,9,8};
   Ensemble e2(tab,5);
   cout<<e1.Ajuster(-2)<<endl;
   e1.Afficher();
   cout<<e2.Ajuster(5)<<endl;
   e2.Afficher();
   cout<<e1.Ajuster(-3)<<endl;
   e1.Afficher();
   cout<<e2.Ajuster(-100)<<endl;
   e2.Afficher();
   */
    /* Test 7
    int tab[5]={7,1,4,9,8};
    Ensemble e2(tab,5);
    e2.Ajuster(5);
    //cout<<e2.Retirer(10)<<endl;
    cout<<e2.Retirer(4)<<endl;
    e2.Afficher();
    Ensemble e1;
    cout<<e1.Retirer(2)<<endl;
    e1.Afficher();
    int tab1[1]={3};
    Ensemble e3(tab1,1);
    e3.Ajuster(5);
    e3.Afficher();
    cout<<e3.Retirer(3)<<endl;
    e3.Afficher();
    */
    /* TEST 8
    int tab[5]={7,1,4,9,8};
    Ensemble e1(tab,5);
    Ensemble e3(tab,5);
    int tab2[2]={1,7};
    Ensemble e2(tab2,2);
    cout<<e1.Retirer(e2)<<endl;
    e1.Afficher();
    cout<<e1.Retirer(e3)<<endl;
    e1.Afficher();
    cout<<e1.Retirer(e2)<<endl;
    e1.Afficher();
    cout<<"--------------"<<endl;
    //int tab4[7]={30,1,50,7,9,8,4};
    Ensemble e4;
    e3.Ajuster(5);
    cout<<e3.Retirer(e4)<<endl;
    e3.Afficher();
    cout <<"-------------"<<endl;
    cout<<e3.Retirer(e3)<<endl;
    e3.Afficher();
    */




    /* TEST 9
    int tab[5]={7,1,4,9,8};
    int tab2[3]={1,4,9};
    Ensemble e1(tab,5);
    e1.Ajuster(5);
    Ensemble e2(tab2,3);
    cout<<e1.Reunir(e2)<<endl;
    e1.Afficher();
    */
    int tab[5]={7,1,4,9,8};
    int tab2[3]={1,4,9};
    Ensemble e1(tab,5);
    e1.Ajuster(5);
    Ensemble e2(tab2,3);
    cout<<e1.Intersection(e2)<<endl;
    e1.Afficher();
    int tab3[3]={1,4,9};
    Ensemble e3(tab3,3);
    e1.Ajuster(5);
    cout<<e1.Intersection(e3)<<endl;
    e1.Afficher();
    int tab4[5]={30,40,50,70,80};
    Ensemble e4(tab4,5);
    cout<<e1.Intersection(e4)<<endl;
    e1.Afficher();
    cout<<"---------------"<<endl;
    int tab5[5]={1,2,3,4,5};
    int tab6[8]={1,2,3,4,5,6,7,8};
    Ensemble e5(tab5,5);
    e5.Ajuster(10);
    Ensemble e6(tab6,8);
    cout<<e5.Intersection(e6)<<endl;
    e5.Afficher();
    cout <<"----------FINAL TEST -------"<<endl;
    e5.Ajuster(5);
    e5.Afficher();
    cout<<e5.Intersection(e5)<<endl;
    e5.Afficher();
    int tab10[2]={1,2};
    Ensemble e10(tab10,2);
    cout<<e5.Intersection(e10)<<endl;
    e5.Afficher();
    return 0;
}
