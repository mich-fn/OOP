#include "Fournisseur.h"
#include "Foncteur.h"
#include <iostream>

Fournisseur::Fournisseur(const string &nom)
    : nom_(nom)
{
}
Fournisseur::~Fournisseur() = default;
string Fournisseur:: getNom() const 
{ return nom_;}
  
vector< shared_ptr<Produit > > Fournisseur:: getCatalogue() const
{
    return catalogue_;
}

 void Fournisseur::operator + (const shared_ptr<Produit> &produit)
 {
    if (!chercherProduit(produit))
    {   produit->setFournisseur(this);        
        catalogue_.push_back(produit);
       
    }
 }
 // to do TP4
 void Fournisseur::operator - (const shared_ptr<Produit> &produit)
 {
     auto it = remove_if(catalogue_.begin(), catalogue_.end(), [produit](const auto& p) {return produit == p; });
  produit->supprimerFournisseur();
  
  catalogue_.erase(it, catalogue_.end()); 
    
 }
// to do TP4
ostream &  Fournisseur::afficher(ostream & sortie) const{
    sortie<< "CATALOGUE (de " << nom_ << ")" << endl;
    for_each(catalogue_.begin(), catalogue_.end(), [&sortie](const auto& p) { p->afficher(sortie); });
    sortie << endl;
    return sortie; 
}
// to do TP4
bool  Fournisseur::chercherProduit (const shared_ptr<Produit> &produit)
{
    auto it = find_if(catalogue_.begin(), catalogue_.end(), [produit](const auto& p) {return produit == p; });
    if (it != catalogue_.end()) {
        return true;
    }
    return false;
 
}
