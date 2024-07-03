
//  client.cpp
//  
//  
//

#include "Client.h"
Client::Client (const string & nom,  const string & prenom, 
        int identifiant, const string & codePostal)
{   nom_ = nom;
    prenom_ = prenom;
    identifiant_ = identifiant;
    codePostal_ = codePostal;
    monPanier_ = make_unique<Panier>();
}
Client ::Client (const Client & c){
        nom_ = c.nom_;
        prenom_ = c.prenom_;
        identifiant_ = c.identifiant_;
        codePostal_ = c.codePostal_;
        monPanier_= make_unique<Panier>();
        vector<shared_ptr<Produit> >  liste = c.monPanier_->getContenuPanier();
        for ( int i = 0 ; i< liste.size(); i++)
            monPanier_-> operator +(liste[i]);
      
        
}

Client &Client :: operator = ( const Client & c)
{
     if ( this != & c)
     {
         nom_ = c.nom_;
         prenom_ = c.prenom_;
         identifiant_ = c.identifiant_;
         codePostal_ = c.codePostal_;
         monPanier_= make_unique<Panier>();
         vector<shared_ptr<Produit> >  liste = c.monPanier_->getContenuPanier();
         for ( int i = 0 ; i< liste.size(); i++)
                 monPanier_-> operator +(liste[i]);
    }
     
    return *this;   
}

Client::~Client() =default;

// methodes d'acces

string Client:: getNom() const{
    return nom_;
}
string Client:: getPrenom() const
{
    return prenom_;
}
int Client:: getIdentifiant() const
{
    return identifiant_;
}

string Client:: getCodePostal() const
{ return codePostal_;
}
Panier  * Client:: getPanier () const
{ return monPanier_.get();}

// methodes de modification
void  Client:: setNom(const string &nom)
{
    nom_ = nom;
}
void Client:: setPrenom(const string  &prenom) {
    prenom_ = prenom;
}
void Client:: setIdentifiant(int identifiant)
{
    identifiant_= identifiant;
}
void Client:: setCodePostal(const string & codePostal)
{
    codePostal_ = codePostal;
}

// autres méthodes
void Client::acheterProduit (const shared_ptr<Produit> & prod){
        monPanier_->operator + (prod);
}

 void Client::supprimerProduit(const shared_ptr<Produit> & prod){
       monPanier_->operator -(prod);
 }

void Client:: livrerPanier()
{
    monPanier_->livrerPanier();
}

double   Client::getCoutPanier() const
{
    return monPanier_->getTotalAPayer();
}

ostream & Client::afficher(ostream & sortie) const
{  sortie << nom_ + ": " + prenom_ + " - Identifiant: " + to_string(identifiant_)<< endl;;
   sortie <<*monPanier_;
   return sortie;

}
 
 
