#ifndef CLIENT_PREMIUM_H
#define CLIENT_PREMIUM_H

#include <string>
#include "Client.h"

using namespace std;

class ClientPremium : public Client
{
  public:
    ClientPremium(const string & nom="",  const string & prenom="", 
    int identifiant= 0, const string & codePostal = "", unsigned int joursRestants = 0);
    ~ClientPremium()override;

    unsigned int getJoursRestants() const;
    double getCoutPanier() const override;
    void setJoursRestants(unsigned int retirerJours);
    ostream & afficher(ostream &) const override;

  private:
    unsigned int joursRestants_; // avant la fin de l'abonnement
};

#endif
