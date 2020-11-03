/*************************************************************************
                           Ensemble  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Ensemble> (fichier Ensemble.h) ----------------
#if ! defined ( ENSEMBLE_H )
#define ENSEMBLE_H

const int CARD_MAX =5;

enum crduEstInclus {NON_INCLUSION, INCLUSION_LARGE, INCLUSION_STRICTE};

enum crduAjouter {DEJA_PRESENT, PLEIN, AJOUTE};

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Ensemble>
//
//
//------------------------------------------------------------------------

class Ensemble 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    Ensemble & operator = ( const Ensemble & unEnsemble );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Ensemble ( const Ensemble & unEnsemble );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Ensemble (unsigned int cardMax=CARD_MAX);
    // Mode d'emploi (constructeur 1) :
    //
    // Contrat :
    //

    Ensemble (int t[], unsigned int nbElements);
    // Mode d'emploi (constructeur 2) :

    virtual ~Ensemble ( );
    // Mode d'emploi(destructeur) :
    //
    // Contrat :
    //

    void Afficher(void);
    //Méthode d'Affichage de l'ensemble sous forme {x,y,z}

    bool EstEgal( const Ensemble & unEnsemble) const;

    crduEstInclus EstInclus ( const Ensemble & unEnsemble )const;

    crduAjouter Ajouter ( int aAjouter );

    unsigned int Ajuster (int delta);

    bool Retirer (int element);

    unsigned int Retirer (const Ensemble & unEnsemble);

    int Reunir (const Ensemble & unEnsemble);

    unsigned int Intersection(const Ensemble & unEnsemble);



//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    int cardMaximale;
    int cardAct;
    int* tab;
};

//-------------------------------- Autres définitions dépendantes de <Ensemble>

#endif // ENSEMBLE_H

