#ifndef FONCTEUR_H
#define FONCTEUR_H
#include <memory>
#include <utility>
#include "Fournisseur.h"
#include "Produit.h"
#include <vector>
#include <map>
using namespace std;
// to do TP4
class ComparerProduit{
 public:
    // to do TP4
  // ComparerProduit(shared_ptr<Produit>& produit) : produit_(produit) {}
   bool operator()(const shared_ptr<Produit>& produit) const {
       return produit == produit_;
   }
 private:
   shared_ptr<Produit> produit_;
};
// to do TP4
class ComparerProduitPrix {
public:
    // to do TP4
   // ComparerProduitPrix(shared_ptr<Produit> produit1, shared_ptr<Produit> produit2) : produit1_(produit1), produit2_(produit2) {}
    bool operator()(const shared_ptr<Produit>& produit1, const shared_ptr<Produit>& produit2) const {
        return produit1->getPrix() < produit2->getPrix();
    }
};
 // to do TP4
class CreerMapFournisseur{
   public:
      CreerMapFournisseur(map<Fournisseur *, vector<shared_ptr<Produit> > >  & uneMap):
      mapFournisseur_(uneMap){}
      void operator()(const shared_ptr<Produit>  & p){
        // to do TP4
          if (p->getFournisseur() != nullptr) {
              mapFournisseur_[p->getFournisseur()].push_back(p);
          }
      }
      private:
     map<Fournisseur *, vector<shared_ptr<Produit> > >  & mapFournisseur_;
  };

  #endif
  