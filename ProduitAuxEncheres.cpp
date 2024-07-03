#include "ProduitAuxEncheres.h"

// todo
ProduitAuxEncheres::ProduitAuxEncheres(const string &nom,
                                       int categorie, double prix)
    : Produit(nom, categorie, prix),
      prixActuel_(prix),
      encherisseur_(nullptr)
{
}
ProduitAuxEncheres::~ProduitAuxEncheres()= default;

double ProduitAuxEncheres::getPrix() const
{
    return  prixActuel_;
}

shared_ptr<Client> ProduitAuxEncheres::getEncherisseur() const
{
    return encherisseur_;
}

ostream  &ProduitAuxEncheres::afficher(ostream & sortie) const
{
    Produit::afficher(sortie);
    sortie << "\tprix Actuel:\t" << to_string(prixActuel_) << endl;
     if (encherisseur_!= nullptr)
         sortie << "\t\tencherisseur:\t" << encherisseur_->getNom() << endl;
    return sortie;     
}


void ProduitAuxEncheres::mettreAJourEnchere(const shared_ptr<Client>  & encherisseur, 
                         double nouveauPrix)
{
    if (nouveauPrix  >  prixActuel_){
         prixActuel_ = nouveauPrix;
         encherisseur_ = encherisseur;
    }    
    
}