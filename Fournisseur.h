#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H

#include <string>
#include <vector>
#include <set> 
#include <memory>
#include <algorithm> 
#include "Produit.h"
#include "Affichable.h"
using namespace std;
class Produit;
class Fournisseur : public Affichable
{
  public:
    Fournisseur(const string & nom="");
    ~Fournisseur()override;
    string  getNom() const;
    vector<shared_ptr<Produit >>  getCatalogue() const;
     
    void operator + (const shared_ptr<Produit> &produit);
    
    void operator - (const shared_ptr<Produit> &produit);
    
    bool chercherProduit (const shared_ptr<Produit> &produit);
   
   ostream & afficher(ostream & sortie) const override;

  private:
    string nom_;
    vector<shared_ptr<Produit >> catalogue_;
};    
#endif
