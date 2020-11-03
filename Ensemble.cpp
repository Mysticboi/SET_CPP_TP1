/*************************************************************************
                           Ensemble  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Ensemble> (fichier Ensemble.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Ensemble.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Ensemble::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
Ensemble & Ensemble::operator = ( const Ensemble & unEnsemble )
// Algorithme :
//
{
    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Ensemble::Ensemble ( const Ensemble & unEnsemble )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Ensemble>" << endl;
#endif
} //----- Fin de Ensemble (constructeur de copie)


Ensemble::Ensemble (unsigned int cardMax)
// Algorithme :
//
{
    if(cardMax!=0){
    cardAct=0;
    cardMaximale=cardMax;
    tab= new int [cardMaximale];
    }
    else{
        cardAct=0;
        cardMaximale=cardMax;
        tab= NULL;
    }
    
#ifdef MAP
    cout << "Appel au constructeur de <Ensemble>" << endl;
#endif
} //----- Fin de Ensemble

Ensemble:: Ensemble( int t[], unsigned int nbElements)
// Constructeur 2
{
    cardMaximale=nbElements;
    tab=new int[nbElements];
    int nombre=0;
    for( unsigned int i=0; i<nbElements; i++){
        if(nombre==0){
            tab[i]=t[i];
            nombre++;
        }
        else{
            bool present=false;
            for(int j=0; j<nombre; j++){
                if(tab[j]==t[i]){
                    present=true;
                }
            }
            if(!present){
                tab[nombre]=t[i];
                nombre++;
            }
        }
    }
    cardAct=nombre;
}


Ensemble::~Ensemble ( )
// Algorithme :
//
{
    delete [] tab;
#ifdef MAP
    cout << "Appel au destructeur de <Ensemble>" << endl;
#endif
} //----- Fin de ~Ensemble

void Ensemble::Afficher(void)
// Algorithme :
//
{
    cout<< cardAct<<"\r\n";
    cout<< cardMaximale<<"\r\n";
    if(cardAct==0){
        cout<<"{}"<<"\r\n";
    }
    else{
        int min=100000;
        int indice=1;
        int temp;
        //On trie d'abbord le tableau
        for(int j=0; j<cardAct; j++){
            for(int i=j; i<cardAct; i++){
                if(tab[i]<min){
                    min=tab[i];
                    indice=i;
                }
            }
            temp=tab[j];
            tab[j]=min;
            tab[indice]=temp;
            min=100000;
        }
        cout<<"{";
        for(int i=0; i<cardAct; i++){
            if(i!=cardAct-1)
                cout<<tab[i]<<",";
            else
                cout<<tab[i]<<"}";
        }
        cout << "\r\n";
    }

} //----- Fin de Afficher

bool Ensemble::EstEgal( const Ensemble & unEnsemble) const
{
    if(cardAct != unEnsemble.cardAct){
        return false;
    }
    bool res=true;
    for(int i=0; i<cardAct; i++){
        if(!res)
            break;
    
        for(int j=0; j<cardAct; j++){
            if(unEnsemble.tab[j]==tab[i]){
                break;
            }
            if(j==cardAct-1){
                res=false;
            }
        }
    }
    return res;

} //----- Fin de EstEgal

crduEstInclus Ensemble::EstInclus ( const Ensemble & unEnsemble )const
{
    if(this->EstEgal(unEnsemble)){
        return INCLUSION_LARGE;
    }
    else{
        bool res=true;
        for(int i=0; i<cardAct; i++){
            if(!res)
                break;
        
            for(int j=0; j<unEnsemble.cardAct; j++){
                if(unEnsemble.tab[j]==tab[i]){
                    break;
                }
                if(j==unEnsemble.cardAct-1){
                    res=false;
                }
            }
        }
        if(res)
            return INCLUSION_STRICTE;
        else
            return NON_INCLUSION;
    }
} //----- Fin de EstInclus

crduAjouter Ensemble::Ajouter ( int aAjouter )
{
    for(int i=0; i<cardAct; i++){
        if(tab[i]==aAjouter)
            return DEJA_PRESENT;
    }
    if(cardAct==cardMaximale){
        return PLEIN;
    }
    tab[cardAct]=aAjouter;
    cardAct++;
    return AJOUTE;
}

unsigned int Ensemble::Ajuster(int delta)
{
    if(delta>0){
        int* temp=new int[cardMaximale+delta];
        cardMaximale+=delta;
        for(int i=0; i<cardAct; i++){
            temp[i]=tab[i];
        }
        delete []tab;
        tab=temp;
        return (unsigned int)cardMaximale;
    }
    if(delta==0){
        return (unsigned int)cardMaximale;
    }
    if(delta<0){
        if(cardAct>0){
                if((cardMaximale+delta) < cardAct){
                    delta=cardAct-cardMaximale;
                }
                int* temp=new int[cardMaximale+delta];
                cardMaximale+=delta;
                for(int i=0; i<cardAct; i++){
                temp[i]=tab[i];
                }
                delete []tab;
                tab=temp;
                return (unsigned int)cardMaximale;
        }
            
        if(cardAct==0){
            if(cardMaximale==0){
                return (unsigned int)cardMaximale;
            }
            if((cardMaximale+delta) < cardAct){
                    delta=cardAct-cardMaximale;
            }
            if(cardMaximale+delta==0){
                    cardMaximale=0;
                    tab=NULL;
                    return (unsigned int)cardMaximale;
            }
            if(cardMaximale+delta>0){
                int* temp=new int[cardMaximale+delta];
                cardMaximale+=delta;
                delete[]tab;
                tab=temp;
                return (unsigned int)cardMaximale;
            }
        }
    }
    return (unsigned int)cardMaximale;
}

bool Ensemble::Retirer (int element)
{
    bool res=false;
    int indice;
    for(int i=0; i<cardAct; i++){
        if(tab[i]== element){
            indice=i;
            //cout<<"Indice dans premier for"<<indice<<endl;
            res=true;
            break;
        }
    }
    int j=0;
    if(res){
        if(cardAct==1){
            cardAct=0;
            cardMaximale=0;
            tab=NULL;
            return res;
        }
        cardMaximale=cardAct-1;
        int* temp=new int[cardAct-1];
        for(int i=0; i<cardAct; i++){
            if(i==indice){
                //cout<<"Indice dans deuxieme for"<<indice<<"|"<<tab[i]<<endl;
                continue;
            }
            //cout<<j<<'|'<<temp[j]<<'|'<<i<<'|'<<tab[i]<<endl; 
            temp[j]=tab[i];
            j++;
        }
        cardAct=cardAct-1;
        delete []tab;
        tab=temp;
    }
    else{
        if(cardAct==0){
            cardMaximale=0;
            tab=NULL;
            return res;
        }
        cardMaximale=cardAct;
        int* temp=new int[cardAct];
        for(int i=0; i<cardAct; i++){
            temp[i]=tab[i];
        }
        delete []tab;
        tab=temp;
    }
    return res;
}

unsigned int Ensemble::Retirer(const Ensemble & unEnsemble)
{
    unsigned int nb=0;
    if(EstEgal(unEnsemble)){
        nb=cardAct;
        int *temp=new int[cardMaximale];
        delete []tab;
        tab=temp;
        cardAct=0;
        return nb;
    }
    if(cardAct==0 or unEnsemble.cardAct==0){
        return (unsigned int) 0;
    }
    for(int i=0; i<(unEnsemble.cardAct); i++){
        bool res=false;
        int indice=0;
        for(int j=0; j<cardAct;j++){
            if(tab[j]== unEnsemble.tab[i]){
                indice=j;
                res=true;
                break;
            }
        }
        if(res){
            int* temp=new int[cardMaximale];
            int k=0;
            for(int j=0;j<cardAct;j++){
                if(j==indice){
                    continue;
                }
                temp[k]=tab[j];
                k++;
            }
            delete []tab;
            tab=temp;
            nb++;
            cardAct--;
        }
    }
    return nb;
}

int Ensemble::Reunir(const Ensemble & unEnsemble)
{
    int nb=0;
    for(int i=0; i<unEnsemble.cardAct; i++){
        for(int j=0; j<cardAct; j++){
            if(tab[j]==unEnsemble.tab[i] and j!=(cardAct-1)){
                break;
            }
            if(j==cardAct-1 && tab[j]!=unEnsemble.tab[i]){
                nb++;
                //cout<<unEnsemble.tab[i]<<" is not present"<<endl;
            }
        }
    }
    //cout<< "nb equals: "<<nb<<endl;
    if(nb==0){
        return nb;
    }
    bool ajustement=false;
    if((cardAct+nb)>cardMaximale){
        int* temp= new int [cardAct+nb];
        for(int i=0; i<cardAct; i++){
            temp[i]=tab[i];
        }
        delete [] tab;
        tab=temp;
        cardMaximale=cardAct+nb;
        ajustement=true;

    }
    int k=cardAct;
    for(int i=0; i<unEnsemble.cardAct; i++){
        for(int j=0; j<cardAct; j++){
            if(tab[j]==unEnsemble.tab[i] and j!=(cardAct-1)){
                break;
            }
            if(j==cardAct-1 and tab[j]!=unEnsemble.tab[i]){
                tab[k]=unEnsemble.tab[i];
                k++;
            }
        }
    }
    cardAct+=nb;
    if(ajustement)
        nb=-nb;
    return nb;
}

/*
unsigned int Ensemble::Intersection(const Ensemble & unEnsemble)
{
    int t[50];
    unsigned int k=0;
    unsigned int res=0;
    if(cardAct==0){
        cardAct=0;
        cardMaximale=0;
        tab=NULL;
        return k;
    }
    if(unEnsemble.cardAct==0){
        this->Ajuster(cardAct-cardMaximale);
        return k;
    }
    for(int i=0;i<unEnsemble.cardAct; i++){
        for(int j=0; j<cardAct; j++){
            if(tab[j]==unEnsemble.tab[i]){
                t[k]=tab[j];
                k++;
                break;
            }
        }
    }
    if(k==0){
        this->Ajuster(cardAct-cardMaximale);
        return k;
    }
    int* temp=new int[k];
    for(unsigned int i=0; i<k; i++){
        temp[i]=t[i];
    }
    res=cardAct-k;
    delete []tab;
    tab=temp;
    cardAct=k;
    cardMaximale=k;
    return res;

}
*/

unsigned int Ensemble::Intersection( const Ensemble & unEnsemble)
{
    unsigned int k=0;
    if(EstEgal(unEnsemble)){
        //cout<<"Cas spécial"<<endl;
        Ajuster(cardAct-cardMaximale); 
        return k;   
    }
    int limit=cardAct;
    for(int x=0; x<limit;x++){
        for(int i=0; i<cardAct; i++){
            int a=tab[i];
            for(int j=0; j<unEnsemble.cardAct; j++){
                if(unEnsemble.tab[j]==tab[i] and j!=(unEnsemble.cardAct-1)){
                    break;
                }
                if(j==(unEnsemble.cardAct-1) and unEnsemble.tab[j]!=tab[i]){
                    this->Retirer(a);
                    //cout<<"Card Act: "<<cardAct<<endl;
                    k++;
                }
            }
        }
    }
    if(k==0){
        this->Ajuster(cardAct-cardMaximale);
        return k;
    }
    return k;
}






//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

