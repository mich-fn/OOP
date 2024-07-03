#include "ProduitVente.h"


// to do
ProduitVente::ProduitVente( const string &nom,
                           int categorie, double prix, int pourcentageRabais)
    : Produit(nom, categorie, prix),
            pourcentageRabais_(pourcentageRabais)
{
}
ProduitVente::~ProduitVente()= default;

double ProduitVente::getPrix() const
{
    return Produit::getPrix() * ((100 - pourcentageRabais_) / 100.0);
}

ostream & ProduitVente::afficher(ostream  & sortie) const
{
    Produit::afficher(sortie);
    sortie << "\trabais:\t\t" << pourcentageRabais_ << "%" << endl;
    return sortie;
}
