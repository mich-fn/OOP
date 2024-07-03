
//  panier.cpp
//  Created by Martine Bellaiche on 18-01-22.
//  Copyright © 2018 Martine Bellaiche. All rights reserved.
//
#ifndef PANIER_H
#define PANIER_H
#include <string>
#include "Produit.h"
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <memory>
#include "Affichable.h"
#include "Foncteur.h"
using namespace std;
class Panier:public Affichable
{
public:
    Panier ();
    ~Panier()override;
    // methodes d'accès
  //  vector<shared_ptr<Produit > >  getContenuPanier()const;
    vector<shared_ptr<Produit > >  getContenuPanier()const;
    int  getNombreContenuPanier() const;
    double  getTotalAPayer() const;   
    // autres méthodes 
    void operator + (const shared_ptr<Produit > & p);
 //   Panier  operator  + ( const Panier & p);

    void  operator - (const shared_ptr<Produit > &p);
  //  Panier  operator  - (const Panier & p);
    bool chercherProduit(const shared_ptr<Produit > & prod);
    void livrerPanier();
    ostream &  afficher(ostream  &  out) const override; 
   // à tester lors  de l'ajout fournisseur au produit.
   map<Fournisseur *, vector<shared_ptr<Produit>> > getMapFournisseurProduit();  
   set<shared_ptr<Produit>, ComparerProduitPrix > getSetProduitTrierPrix();

private:  
   // vector<shared_ptr<Produit > > contenuPanier_;  
    vector<shared_ptr<Produit > > contenuPanier_; 
    double totalAPayer_;
};

#endif

