#include "Produit.h"
#include "Fournisseur.h"
#include <iostream>
#include <string>
#include <iomanip>
// to do pour initilaiser le fournisseur
Produit::Produit(const string &nom, int categorie, double prix)
    : nom_(nom),
      categorie_(categorie),
      prix_(prix), fournisseur_(nullptr)
{
   
}
Produit::~Produit() = default;

string Produit:: getNom() const
{
    return nom_;
}

int Produit:: getCategorie() const
{
    return categorie_;
}

double Produit:: getPrix() const
{
    return prix_;
}
//to do
Fournisseur * Produit:: getFournisseur() const
{ return fournisseur_;
}
void Produit:: setNom(const string &nom)
{
    nom_ = nom;
}

void Produit:: setCategorie(int categorie)
{
    categorie_ = categorie;
}

void Produit:: setPrix(double prix)
{
    prix_ = prix;
}

void Produit::setFournisseur ( Fournisseur *  f)
{  fournisseur_ = f;}

void Produit:: supprimerFournisseur(){
    fournisseur_ = nullptr;
}

ostream & Produit::afficher(ostream & sortie) const
{
    return sortie << "\t" << nom_ << "\n\tCategorie:\t" <<
        to_string(categorie_) << "\n\tPrix:\t\t$" <<
        to_string(prix_) << "\n";
}

bool Produit:: operator == ( const Produit & p)
{
    return nom_ == p.nom_;
}



