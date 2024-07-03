#ifndef PRODUIT_SOLDE_H
#define PRODUIT_SOLDE_H

#include <string>
#include <iostream>
#include "Produit.h"
using namespace std;

class ProduitVente : public Produit
{
  public:
    ProduitVente(const string & nom = "outil",
            int categorie = 0, double prix = 0.0, int pourcentageRabais = 0);
    ~ProduitVente() override;
    double getPrix() const override;
    ostream & afficher(ostream & sortie) const override;
  private:
      int pourcentageRabais_;
};

#endif
