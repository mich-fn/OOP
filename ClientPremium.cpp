#include "ClientPremium.h"

ClientPremium::ClientPremium(const string &nom, const string &prenom, int identifiant,
                             const string &codePostal,
                             unsigned int joursRestants)
    : Client(nom, prenom, identifiant, codePostal),
      joursRestants_(joursRestants)
{
}
ClientPremium::~ClientPremium()=default;

unsigned int ClientPremium::getJoursRestants() const
{
    return joursRestants_;
}

double ClientPremium::getCoutPanier() const
{  
    double montant = 0;
    vector<shared_ptr<Produit > > lePanier = monPanier_->getContenuPanier();
    for (unsigned int i = 0; i < lePanier.size(); i++) {
        double prix = lePanier[i]->getPrix();
        montant += prix < 5 ? 0 : prix - 5;
    }
    return montant;
}

ostream & ClientPremium::afficher(ostream & sortie) const
{
    Client::afficher(sortie);
    sortie << "\t\tjours restants:\t" << joursRestants_ << endl;
    return sortie;
}

void ClientPremium::setJoursRestants(unsigned int retirerJours)
{    if  ((joursRestants_- retirerJours ) >= 0)
       joursRestants_ -= retirerJours;
     else
        joursRestants_ = 0;  

}
