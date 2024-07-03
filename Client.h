
//  client.h
//  
//

#ifndef CLIENT_H
#define CLIENT_H
#include <string>
#include "Panier.h"
#include "Affichable.h"
#include <memory>
#include <list>
using namespace std;
class Client: public Affichable
{
public:
    Client (const string & nom="",  const string & prenom="", 
    int identifiant= 0, const string & codePostal = "");
    // constructeur de Copie
    Client (const Client & c);
    Client & operator = ( const Client & c);
     ~Client()override;
    // methodes d'acces   
    string  getNom() const;
    string  getPrenom() const;
    int  getIdentifiant() const;
    string  getCodePostal() const;
    Panier *  getPanier () const;  
    virtual double  getCoutPanier() const;
    // methodes de modification
    void  setNom(const string &nom) ;
    void  setPrenom(const string  & prenom) ;
    void  setIdentifiant(int identifiant) ;
    void  setCodePostal(const string  & codePostal);
      
    // autres méthodes
    void acheterProduit (const shared_ptr<Produit>  & prod);
    void supprimerProduit(const shared_ptr<Produit>  & prod);
    void livrerPanier();
    ostream & afficher(ostream & ) const override;
private:   
    string nom_;
    string prenom_;
    int identifiant_;
    string codePostal_;
 protected:   
    unique_ptr<Panier>  monPanier_;
};
#endif /* client_h */
