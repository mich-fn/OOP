#ifndef PRODUIT_AUX_ENCHERES_H
#define PRODUIT_AUX_ENCHERES_H

#include <string>
#include <iostream>
#include "Produit.h"
#include "Client.h"

using namespace std;

class ProduitAuxEncheres : public Produit
{
  public:
    ProduitAuxEncheres(const string & nom = "outil",
            int categorie = 0, double prix = 0.0);
    ~ProduitAuxEncheres() override;
    double getPrix() const override;
    shared_ptr<Client> getEncherisseur() const;
    ostream & afficher(ostream & sortie) const override; 
    void mettreAJourEnchere(const shared_ptr<Client>  & encherisseur, double nouveauPrix);
  private:
    double prixActuel_;
    shared_ptr<Client> encherisseur_;
};

#endif
