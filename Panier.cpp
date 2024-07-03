//
//  panier.cpp
//
//  Created by Martine Bellaiche

#include <string>
#include "Panier.h"

Panier::Panier ()
{
    totalAPayer_= 0;
}
Panier::~Panier()= default;
// methodes d'accès

vector<shared_ptr<Produit > > Panier:: getContenuPanier()const{
    return contenuPanier_;
}
int Panier:: getNombreContenuPanier() const{
    return contenuPanier_.size();
}
double Panier:: getTotalAPayer() const{
    return totalAPayer_;
}
// to do TP4
void Panier:: operator + (const shared_ptr<Produit>  & prod){
    auto it = find_if(contenuPanier_.begin(), contenuPanier_.end(), [prod](const auto& p) {return prod == p; });
    if (it != contenuPanier_.end()) {
        return;
    }
    contenuPanier_.push_back(prod);
    totalAPayer_ += prod->getPrix();

}
// to do TP4
void  Panier ::operator - (const shared_ptr<Produit>  &prod)
 {
    auto it = remove_if(contenuPanier_.begin(), contenuPanier_.end(), [prod](const auto& p) {return prod == p; });
     contenuPanier_.erase(it, contenuPanier_.end());

     double somme = 0.0;

     for_each(contenuPanier_.begin(), contenuPanier_.end(), [&somme](const auto& p) {somme += p->getPrix(); });
     totalAPayer_ = somme;
 }
// to do TP4
bool Panier::chercherProduit(const shared_ptr<Produit> & prod)
{
    auto it = find(contenuPanier_.begin(), contenuPanier_.end(), prod);
    if (it != contenuPanier_.end()) {
        return true ;
    }
    return false;

}
void Panier::livrerPanier(){
    contenuPanier_.clear();
    totalAPayer_ = 0;
}
// to do TP4
ostream  & Panier::afficher(ostream & sortie) const{
    sortie << "le panier " << "\n" << "totalPanier " << to_string(totalAPayer_) << "\n";
   for_each(contenuPanier_.begin(), contenuPanier_.end(), [&sortie](const auto& p) { p->afficher(sortie); });
   
   return sortie;
 // to do TP4

}
// to do TP4
map<Fournisseur *, vector<shared_ptr<Produit>> > Panier::getMapFournisseurProduit() {
    map<Fournisseur*, vector<shared_ptr<Produit>> > mapPanier = {};

     //Create the functor object passing mapPanier
    CreerMapFournisseur mapCart(mapPanier);

     //Apply the functor to each product in the Panier
    for (const auto& produit : contenuPanier_) {
        mapCart(produit);
    }

  return mapPanier;
}
// to do TP4
 set<shared_ptr<Produit>, ComparerProduitPrix > Panier::getSetProduitTrierPrix()
 {
     set<shared_ptr<Produit>, ComparerProduitPrix > setPanier;
        transform(contenuPanier_.begin(), contenuPanier_.end(), inserter(setPanier, setPanier.end()), [](const auto& p) {return p; });

     return setPanier;
 }
