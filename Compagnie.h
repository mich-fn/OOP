#ifndef COMPAGNIE_H
#define COMPAGNIE_H

#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <map>
#include <numeric> // 
#include <utility> // pair
#include "Produit.h"
#include "ProduitAuxEncheres.h"
#include "ProduitVente.h"
#include "Client.h"
#include "Fournisseur.h"
#include "Affichable.h"
#include "Foncteur.h"
#include <functional>

using namespace std;

class Compagnie: public Affichable
{
  public:
    Compagnie (const string & nom);
    ~Compagnie()override ;
    vector<shared_ptr<Produit> > getProduits() const;
    vector<shared_ptr<Client> >  getClients() const;
    vector<shared_ptr<Fournisseur> > getFournisseurs() const;
    map<shared_ptr<Produit>, int> getProduitsAchetes() const;
    double getChiffreAffaires() const;
    
    void operator + (const shared_ptr<Client> & );
    void operator + (const shared_ptr<Fournisseur> & );

    
    void operator - (const shared_ptr<Client> & );
    void operator - (const shared_ptr<Fournisseur> & );

    bool chercherClient (const shared_ptr<Client>  & client) const;
    bool chercherProduit(const shared_ptr<Produit>  & produit) const;
    
    bool encherir(const shared_ptr<Client>  & client, 
                  const shared_ptr<Produit>  & produit, double montant) const;
   
    void acheter (const shared_ptr<Client>  & client, 
                  const shared_ptr<Produit>  & produit);
    void livrer(const shared_ptr<Client>  & client);
    
    unsigned combienProduitEnVente();
    ostream &  afficher(ostream & ) const override;
    
    shared_ptr<Client> chercherClientPlusAchat();
    
    shared_ptr< Produit> getProduitPopulaire();
    // to do TP4
    template < typename T, typename S>
    T * listersi(S conteneur, const function<bool(const T  & av)> & critere) const
    {   
    // to do TP4
        for (auto&& av : conteneur) {
            if (critere(*av)) {
                return  av.get();
            }
        }
        return nullptr;
       
  
   }
  
  private:
    string nom_;
    double chiffreAffaires_;
    vector<shared_ptr<Produit> > produits_;
    // to do TP4
    map<shared_ptr<Produit>, int> produitsAchetes_;
     // to do TP4
    set <shared_ptr<Produit>, ComparerProduitPrix> produitsTrierPrix_;
    vector <shared_ptr<Client> > clients_;
     // to do TP4
    map< shared_ptr<Client>, double> clientsChiffreAffaires_;
    vector <shared_ptr<Fournisseur> > fournisseurs_;
};



#endif 
