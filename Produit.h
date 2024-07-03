#ifndef PRODUIT_H
#define PRODUIT_H

#include <string>
#include <iostream>
#include "Fournisseur.h" 
#include "Affichable.h"
using namespace std;
class Fournisseur;
class Produit: public Affichable
{
  public:
    Produit(const string &nom = "outil",
            int categorie = 0, double prix = 0.0);
    ~Produit()override;
    string getNom() const;
    int  getCategorie() const;
  
    virtual double getPrix() const;
    Fournisseur * getFournisseur() const;
    
    void  setNom(const string &nom);
    void  setCategorie(int categorie);
    void  setPrix(double prix);
   
    void  setFournisseur (Fournisseur * f);
    void  supprimerFournisseur ();

    bool operator == (const Produit & p); 
    ostream & afficher(ostream & sortie) const override;
  
  private:
    string nom_;
    int categorie_;
    double prix_;
    Fournisseur * fournisseur_;
};

#endif
