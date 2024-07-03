#include "Compagnie.h"

Compagnie::Compagnie(const string &nom) : nom_(nom), chiffreAffaires_(0) {}

Compagnie ::~Compagnie() = default;

vector<shared_ptr<Produit>> Compagnie::getProduits() const
{
    return produits_;
}
vector<shared_ptr<Client>> Compagnie::getClients() const
{
    return clients_;
}
vector<shared_ptr<Fournisseur>> Compagnie::getFournisseurs() const
{
    return fournisseurs_;
}
map<shared_ptr<Produit>, int> Compagnie::getProduitsAchetes() const
{
    return produitsAchetes_;
}
void Compagnie::operator+(const shared_ptr<Client> &client)
{
    if (chercherClient(client))
        return;
    clients_.push_back(client);
}
// to do TP4
void Compagnie::operator+(const shared_ptr<Fournisseur> &fournisseur)
{
    auto it = find_if(fournisseurs_.begin(), fournisseurs_.end(), [&](const auto &f)
                      { return fournisseur == f; });
    if (it != fournisseurs_.end())
    {
        return;
    }
    fournisseurs_.push_back(fournisseur);

    for (const auto &produit : fournisseur->getCatalogue())
    {
        produitsTrierPrix_.insert(produit);
        if (!chercherProduit(produit))
        {
            produits_.push_back(produit);
        }
    }
}

void Compagnie::operator-(const shared_ptr<Client> &client)
{
    for (int i = 0; i < clients_.size(); i++)
        if (clients_[i] == client)
        {
            clients_[i] = clients_.back();
            clients_.pop_back();
            return;
        }
    return;
}
void Compagnie::operator-(const shared_ptr<Fournisseur> &fournisseur)
{
    for (int i = 0; i < fournisseurs_.size(); i++)
        if (fournisseurs_[i] == fournisseur)
        {
            fournisseurs_[i] = fournisseurs_.back();
            fournisseurs_.pop_back();
            break;
        }
    for (int i = 0; i < produits_.size(); i++)
        if (produits_[i]->getFournisseur() == fournisseur.get())
        {   // chercher   de produits_[i]  dans le set
            // TO DO TP4. Il est interdit de faire une boucle
            // il faut supprimer tous  les produits associés à ce  fournisseur
            produitsTrierPrix_.erase(produits_[i]);
            swap(produits_[i], produits_.back());
            produits_.pop_back();
        }
    return;
}
// TO DO TP4. Il est interdit de faire une boucle
ostream &Compagnie::afficher(ostream &sortie) const
{
    for_each(produits_.begin(), produits_.end(), [&sortie](const auto &p)
             { p->afficher(sortie); });
    for_each(clients_.begin(), clients_.end(), [&sortie](const auto &c)
             { c->afficher(sortie); });
    for_each(fournisseurs_.begin(), fournisseurs_.end(), [&sortie](const auto &f)
             { f->afficher(sortie); });

    return sortie;
}

double Compagnie::getChiffreAffaires() const
{
    return chiffreAffaires_;
}
// TO DO TP4. Il est interdit de faire une boucle
void Compagnie::livrer(const shared_ptr<Client> &client)
{
    chiffreAffaires_ += client->getCoutPanier();
    clientsChiffreAffaires_.insert(make_pair(client, client->getCoutPanier()));

    for (const auto &p : client->getPanier()->getContenuPanier())
    {
        produitsAchetes_[p]++;
    }

    client->livrerPanier();
}
// TO DO TP4. Il est interdit de faire une boucle
bool Compagnie::chercherClient(const shared_ptr<Client> &client) const
{

    auto it = find_if(clients_.begin(), clients_.end(), [&](const auto &c)
                      { return client->getNom() == c->getNom(); });

    if (it != clients_.end())
    {
        return true;
    }
    return false;
}
// TO DO TP4. Il est interdit de faire une boucle
bool Compagnie::chercherProduit(const shared_ptr<Produit> &produit) const
{
    auto it = find_if(produits_.begin(), produits_.end(), [&](const auto &prod)
                      { return produit == prod; });
    if (it != produits_.end())
    {
        return true;
    }
    return false;
}

bool Compagnie::encherir(const shared_ptr<Client> &client,
                         const shared_ptr<Produit> &produit, double montant) const
{
    // vérifier que le client  est dans la compagnie et le produitAuxEncheres
    bool condition = dynamic_cast<ProduitAuxEncheres *>(produit.get()) &&
                     chercherClient(client);

    if (condition)
    {
        dynamic_cast<ProduitAuxEncheres *>(produit.get())->mettreAJourEnchere(client, montant);
        return true;
    }
    return false;
}

void Compagnie::acheter(const shared_ptr<Client> &client,
                        const shared_ptr<Produit> &produit)
{

    if (chercherClient(client) && chercherProduit(produit))
    {
        client->acheterProduit(produit);
    }
}
// TO DO TP4
unsigned Compagnie::combienProduitEnVente()
{
    return fournisseurs_.size();
}
// TO DO TP4
shared_ptr<Client> Compagnie::chercherClientPlusAchat()
{
    auto it = max_element(clientsChiffreAffaires_.begin(), clientsChiffreAffaires_.end(), [](const auto &paire1, const auto &paire2)
                          { return paire1.second < paire2.second; });
    return it->first;
}
// TO DO TP4
shared_ptr<Produit> Compagnie::getProduitPopulaire()
{
    auto it = max_element(produitsAchetes_.begin(), produitsAchetes_.end(), [](const auto &paire1, const auto &paire2)
                          { return paire1.second < paire2.second; });
    return it->first;
}