#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <functional>
#include "Client.h"
#include "ClientPremium.h"
#include "Fournisseur.h"
#include "Panier.h"
#include "ProduitVente.h"
#include "ProduitAuxEncheres.h"
#include "Produit.h"
#include "Constants.h"
#include "Compagnie.h"
#include <memory>

using namespace std;
namespace testing
{
    string redirect_stdout(function<void()> func)
    {
        stringstream buffer;
        auto old_cout = cout.rdbuf();

        cout.rdbuf(buffer.rdbuf());
        func();

        cout.rdbuf(old_cout);

        return buffer.str();
    }
}
void supprimerR(string &sortie)
{
    string apres = "";

    for (int i = 0; i < sortie.size(); i++)
        if (sortie[i] != '\r')
            apres = apres + sortie[i];
    sortie = apres;
}
// Test pour Produit (3.25 points)

double testProduit()
{
    double points = 0.0;

    Produit Produit1;
    Produit Produit2(NOM_1, CATEGORIE_1, PRIX_1);

    // Test  operator<< pour Produit
    Produit Produit3(NOM_1, CATEGORIE_1, PRIX_1);

    shared_ptr<Produit> ProduitVente1 =
        make_shared<ProduitVente>(NOM_1, CATEGORIE_1, PRIX_1, 10);

    shared_ptr<Produit> ProduitAuxEncheres1 =
        make_shared<ProduitAuxEncheres>(NOM_2, CATEGORIE_2, PRIX_2);

    shared_ptr<Client> unClient =
        make_shared<Client>(CLIENT_1, PRENOM_1, IDENTIFIANT_1, CODEPOSTAL_1);

    ProduitAuxEncheres *produit1 = dynamic_cast<ProduitAuxEncheres *>(ProduitAuxEncheres1.get());

    shared_ptr<Produit> ProduitAuxEncheres3 =
        make_shared<ProduitAuxEncheres>(NOM_3, CATEGORIE_3, PRIX_3);

    ProduitAuxEncheres *produit2 =
        dynamic_cast<ProduitAuxEncheres *>(ProduitAuxEncheres3.get());

    shared_ptr<Fournisseur> fournisseur1 =
        make_shared<Fournisseur>("premier Fournisseur");

    string sortie = testing::redirect_stdout([&]
                                             { cout << Produit3; });

    string sortieAttendue = "\t" + NOM_1 + "\n\tCategorie:\t" +
                            to_string(CATEGORIE_1) + "\n\tPrix:\t\t$" +
                            to_string(PRIX_1) + "\n";

    if (sortie == sortieAttendue)
    {
        points += 0.0;
    }
    else
    {
        cout << "\033[31m"
             << "afficher de  Produit ne fonctionne pas correctement." << endl
             << SEPARATEUR_1 << "\033[0m\n";
        cout << "Sortie attendue:\n"
             << sortieAttendue << "\n";
        cout << "Sortie du programme:\n"
             << sortie << "\n";
    }
    // test  setFournisseur  et getFournisseur
    Produit3.setFournisseur(fournisseur1.get());
    if (Produit3.getFournisseur() == fournisseur1.get())
        points += 0.0;

    else
        cout << "\033[31m"
             << "setFournisseur et getFournisseur Produit ne fonctionne pas correctement." << endl
             << SEPARATEUR_1 << "\033[0m\n";

    // test supprimerFournisseur
    Produit3.supprimerFournisseur();
    if (Produit2.getFournisseur() == nullptr)
        points += 0.0;

    else
        cout << "\033[31m"
             << "supprimerFournisseur Produit ne fonctionne pas correctement." << endl
             << SEPARATEUR_1 << "\033[0m\n";

    // test operator << ProduitVente
    sortie = testing::redirect_stdout([&]
                                      { cout << *ProduitVente1; });
    sortieAttendue = "\t" + NOM_1 + "\n\tCategorie:\t" +
                     to_string(CATEGORIE_1) + "\n\tPrix:\t\t$" +
                     to_string(PRIX_1) + "\n" + "\trabais:\t\t" +
                     to_string(10) + "%\n";
    if (sortie == sortieAttendue)
    {
        points += 0.0;
    }
    else
    {
        cout << "\033[31m"
             << "operator << ProduitVente ne fonctionne pas correctement." << endl
             << SEPARATEUR_1 << "\033[0m\n";
        cout << "Sortie attendue:\n"
             << sortieAttendue << "\n";
        cout << "Sortie du programme:\n"
             << sortie << "\n";
    }

    // test ProduitVente virtual getPrix()
    if (ProduitVente1->getPrix() == 9)
        points += 0.0;
    else
    {
        cout << "\033[31m"
             << "operator virtuel de ProduitVente ne fonctionne pas correctement."
             << endl
             << SEPARATEUR_1 << "\033[0m\n";
    }

    // test operator << ProduitAuxEncheres
    sortie = testing::redirect_stdout([&]
                                      { cout << *ProduitAuxEncheres1; });

    sortieAttendue = "\t" + NOM_2 + "\n\tCategorie:\t" +
                     to_string(CATEGORIE_2) + "\n\tPrix:\t\t$" +
                     to_string(PRIX_2) + "\n" +
                     "\tprix Actuel:\t" + to_string(PRIX_2) + "\n";

    if (sortie == sortieAttendue)
    {
        points += 0.0;
    }
    else
    {
        cout << "\033[31m"
             << "afficher de ProduitAuxEncheres ne fonctionne pas correctement." << endl
             << SEPARATEUR_1 << "\033[0m\n";
        cout << "Sortie attendue:\n"
             << sortieAttendue << "\n";
        cout << "Sortie du programme:\n"
             << sortie << "\n";
    }

    // test ProduitAuxEncheres virtual getPrix()et  mettreAJourEnchere()

    produit1->mettreAJourEnchere(unClient, 30);
    if (produit1->getPrix() == 30 && produit1->getEncherisseur() == unClient)
        points += 0.0;
    else
    {
        cout << "\033[31m"
             << "operator virtuel getPrix et mettreAJourEnchere() de ProduitAuxEncheres ne fonctionne pas correctement." << endl
             << SEPARATEUR_1 << "\033[0m\n";
    }
    // test ProduitAuxEncheres virtual getPrix()et mettreAJourEnchere()
    // shared_ptr<Client>  unClient = make_shared<Client> (CLIENT_1, PRENOM_1, IDENTIFIANT_1, CODEPOSTAL_1);

    produit2->mettreAJourEnchere(unClient, 60);
    if ((produit2->getPrix() == 60) && (produit2->getEncherisseur() == unClient))
        points += 0.0;
    else
    {
        cout << "\033[31m"
             << "operator virtuel getPrix et mettreAJourEnchere() ProduitAuxEncheres ne fonctionne pas correctement." << endl
             << SEPARATEUR_1 << "\033[0m\n";
    }
    return points;
}
// Test pour Panier (0.5 points)
double testPanier()
{
    double points = 0.0;
    Panier panier1;
    // Creer des Produits
    vector<shared_ptr<Produit>> Produits = {
        make_shared<ProduitVente>(NOM_1, CATEGORIE_1, PRIX_1, 5),
        make_shared<ProduitAuxEncheres>(NOM_3, CATEGORIE_3, PRIX_3),
        make_shared<Produit>(NOM_4, CATEGORIE_4, PRIX_4),
        make_shared<Produit>(NOM_5, CATEGORIE_4, PRIX_5),
        make_shared<ProduitAuxEncheres>(NOM_6, CATEGORIE_3, PRIX_6),
        make_shared<ProduitVente>(NOM_2, CATEGORIE_1, PRIX_2, 3),
    };
    // Ajouter les Produits dans le panier
    panier1 + (Produits[0]);
    panier1 + (Produits[1]);
    panier1 + (Produits[2]);
    panier1 + (Produits[0]);
    // panier1 +  (Produits[3]);
    panier1 + (Produits[4]);
    panier1 + (Produits[5]);
    if (panier1.getContenuPanier().size() == 5)
        points += 0.0;
    // supprimer dans le panier
    // panier1 -  (Produits[4]);
    panier1 - (Produits[3]);
    if (panier1.getContenuPanier().size() == 5)
        points += 1;

    // tester la map que lors de l'ajout de fournisseur
    shared_ptr<Fournisseur> fournisseur = make_shared<Fournisseur>(FOURNISSEUR_1);
    shared_ptr<Fournisseur> fournisseur2 = make_shared<Fournisseur>(FOURNISSEUR_2);
    //  test afficher  pour la classe Panier
    fournisseur->operator+(Produits[0]);
    fournisseur->operator+(Produits[1]);
    fournisseur->operator+(Produits[2]);
    fournisseur2->operator+(Produits[3]);
    fournisseur2->operator+(Produits[4]);
    fournisseur2->operator+(Produits[5]);

    auto uneMap = panier1.getMapFournisseurProduit();
    unsigned somme = 0;
    for (const auto &[key, value] : uneMap)
        somme += value.size();
    if (somme == 5)
        points += 1;
    //  Lire la sortie attendue
    ifstream fichier("sortiePanierV2.txt");
    string sortieAttendue((istreambuf_iterator<char>(fichier)),
                          istreambuf_iterator<char>());
    // remove \r
    supprimerR(sortieAttendue);
    // Comparer la sortie attendue avec la sortie du programme
    string sortie = testing::redirect_stdout([&]
                                             { cout << panier1; });
    // ofstream  sortie2("sortiePanierV2.txt");
    // sortie2 << panier1;
    if ((sortieAttendue.size() > 0) && (sortie == sortieAttendue))
    {
        points += 1;
    }
    else
    {
        cout << "\033[31m"
             << "La methode afficher ne fonctionne pas correctement." << endl
             << SEPARATEUR_1 << "\033[0m\n";
        cout << "Sortie attendue:\n"
             << sortieAttendue << "\n";
        cout << "Sortie du programme:\n"
             << sortie << "\n";
    }

    set<shared_ptr<Produit>, ComparerProduitPrix> produitTrierPrix;
    produitTrierPrix = panier1.getSetProduitTrierPrix();
    auto it = produitTrierPrix.begin();
    if ((**it).getNom() == "Tourvenis" &&
        (**(++it)).getNom() == "vis")
        points += 1.5;
    return points;
}

/*
// // Test pour Client (3 points)
double testClient() {
    double points = 0.0;

    Client Client1;
    Client Client2(CLIENT_1, PRENOM_1, IDENTIFIANT_1, CODEPOSTAL_1);

    // Test de  operator <<
    Client Client3(CLIENT_1, PRENOM_1, IDENTIFIANT_1, CODEPOSTAL_1);
    string sortie = testing::redirect_stdout([&] { cout<< Client3; });
    string sortieAttendue = CLIENT_1 + ": " + PRENOM_1 + " - Identifiant: " + to_string(IDENTIFIANT_1)
    +  "\nle panier "+"\n"+ "totalPanier " + to_string(0.0) +"\n";

    if (sortie == sortieAttendue) {
        points += 0.25;
    }
    else {
        cout << "\033[31m" << "Afficher pour Client ne fonctionne pas correctement." << endl << SEPARATEUR_1 << "\033[0m\n";
        cout << "Sortie attendue:\n" << sortieAttendue << "\n";
        cout << "Sortie du programme:\n" << sortie << "\n";
    }
    ClientPremium  clientP (CLIENT_1, PRENOM_1, IDENTIFIANT_1, CODEPOSTAL_1, 100);
    sortie = testing::redirect_stdout([&] { cout<< clientP; });
    sortieAttendue = CLIENT_1 + ": " + PRENOM_1 + " - Identifiant: " + to_string(IDENTIFIANT_1)
    +  "\nle panier "+"\n"+ "totalPanier " + to_string(0.0) +"\n" +
                      "\t\tjours restants:\t" + to_string(100) +"\n";
    if (sortie == sortieAttendue) {
        points += 0.25;
    }
    else {
        cout << "\033[31m" << "Afficher pour ClientPremium ne fonctionne pas correctement."
              << endl << SEPARATEUR_1 << "\033[0m\n";
        cout << "Sortie attendue:\n" << sortieAttendue << "\n";
        cout << "Sortie du programme:\n" << sortie << "\n";
    }

    clientP.setJoursRestants(40);
    if (clientP.getJoursRestants() == 60 )
        points += 0.5;
    else {
        cout << "\033[31m" << "setJoursRestants pour ClientPremium ne fonctionne pas correctement."
              << endl << SEPARATEUR_1 << "\033[0m\n";
    }

    vector<shared_ptr<Produit> >produits = {
        make_shared< ProduitVente>(NOM_1, CATEGORIE_1, PRIX_1, 5),
        make_shared< ProduitAuxEncheres>(NOM_3, CATEGORIE_3, PRIX_3),
        make_shared< Produit>(NOM_4, CATEGORIE_4, PRIX_4),
        make_shared< ProduitAuxEncheres>(NOM_5, CATEGORIE_5, PRIX_5),
        make_shared< ProduitVente>(NOM_6, CATEGORIE_6, PRIX_6, 7),
        make_shared< Produit>(NOM_7, CATEGORIE_7, PRIX_7)
        };
    Client2.acheterProduit(produits[0]);
    Client2.acheterProduit(produits[2]);
    Client2.acheterProduit(produits[3]);
    Client2.acheterProduit(produits[4]);
    if (static_cast<int>(Client2.getCoutPanier()) == 137)
       points += 1;
    else {
        cout << "\033[31m" << " getPrix()de Produit et getCoutPanier ne fonctionnent pas correctement avec Client." << endl << SEPARATEUR_1 << "\033[0m\n";
    }
    clientP.acheterProduit(produits[0]);
    clientP.acheterProduit(produits[2]);
    clientP.acheterProduit(produits[3]);
    clientP.acheterProduit(produits[4]);
    if (static_cast<int>(clientP.getCoutPanier()) == 120)
       points += 1;
    else {
        cout << "\033[31m" << " getPrix()de Produit et getCoutPanier ne fonctionnent pas correctement avec ClientPremium."
             << endl << SEPARATEUR_1 << "\033[0m\n";
    }
    return points;
}
*/
// Test Fournisseur (points: 2.5)
double testFournisseur()
{
    double points = 0.0;

    shared_ptr<Fournisseur> fournisseur = make_shared<Fournisseur>(FOURNISSEUR_1);
    shared_ptr<Fournisseur> fournisseur2 = make_shared<Fournisseur>(FOURNISSEUR_2);

    // Cr�er des Produits
    vector<shared_ptr<Produit>> Produits = {
        make_shared<Produit>(NOM_1, CATEGORIE_1, PRIX_1),
        make_shared<Produit>(NOM_3, CATEGORIE_3, PRIX_3),
        make_shared<Produit>(NOM_4, CATEGORIE_4, PRIX_4),
        make_shared<Produit>(NOM_5, CATEGORIE_5, PRIX_5),
    };
    fournisseur->operator+(Produits[0]);

    // Lire la sortie attendue
    ifstream fichier("sortieFournisseur.txt");
    string sortieAttendue((istreambuf_iterator<char>(fichier)),
                          istreambuf_iterator<char>());
    // remove \r
    supprimerR(sortieAttendue);
    // Comparer la sortie attendue avec la sortie du programme
    string sortie = testing::redirect_stdout([&]()
                                             { cout << *fournisseur; });

    if ((sortieAttendue.size() > 0) && (sortieAttendue == sortie))
    {
        points += 0.5;
    }
    else
    {
        cout << "\033[31m"
             << "Echec du test afficher de Fournisseur" << endl
             << SEPARATEUR_1 << "\033[0m\n";
        cout << "Sortie attendue:\n"
             << sortieAttendue << "\n";
        cout << "Sortie du programme:\n"
             << sortie << "\n";
    }
    // chercher Produit dans Fournisseur
    if (!fournisseur->chercherProduit(Produits[1]))
        points += 0.5;
    else
    {
        cout << "\033[31m"
             << "Echec du test  chercherProduit de Fournisseur" << endl
             << SEPARATEUR_1 << "\033[0m\n";
    }
    // chercher Produit dans Fournisseur
    if (fournisseur->chercherProduit(Produits[0]))
        points += 0.5;
    else
    {
        cout << "\033[31m"
             << "Echec du test  chercherProduit de Fournisseur" << endl
             << SEPARATEUR_1 << "\033[0m\n";
    }
    // chercher le fournisseur du produit
    auto four = Produits[0]->getFournisseur();
    if (four == fournisseur.get())
        points += 0.0;
    else
    {
        cout << "\033[31m"
             << "Echec du Fournisseur du produit" << endl
             << SEPARATEUR_1 << "\033[0m\n";
    }
    // supprimer le fournisseur du produit
    fournisseur->operator-(Produits[0]);
    if (Produits[0]->getFournisseur() == nullptr)
        points += 1;
    else
    {
        cout << "\033[31m"
             << "Echec du suppression du produit" << endl
             << SEPARATEUR_1 << "\033[0m\n";
    }

    return points;
}
// test  Compagnie (p)

 double testCompagnie()
 {  double points = 0.0;
    Compagnie  polyReno("Poly");
    // Creer des Produits
    vector<shared_ptr<Produit> >produits = {
        make_shared< ProduitVente>(NOM_1, CATEGORIE_1, PRIX_1, 5),
        make_shared< ProduitAuxEncheres>(NOM_3, CATEGORIE_3, PRIX_3),
        make_shared< Produit>(NOM_4, CATEGORIE_4, PRIX_4),
        make_shared< ProduitAuxEncheres>(NOM_5, CATEGORIE_5, PRIX_5),
        make_shared< ProduitVente>(NOM_6, CATEGORIE_6, PRIX_6, 7),
        make_shared< Produit>(NOM_7, CATEGORIE_7, PRIX_7)
        };

    vector<shared_ptr<Client> > clients = {
        make_shared<Client> (CLIENT_1,PRENOM_1, IDENTIFIANT_1,CODEPOSTAL_1  ),
        make_shared<ClientPremium> (CLIENT_2, PRENOM_2, IDENTIFIANT_2, CODEPOSTAL_2, 40),
        make_shared<ClientPremium> (CLIENT_3,PRENOM_3, IDENTIFIANT_3,CODEPOSTAL_3,50 ),
        make_shared<Client> (CLIENT_4,PRENOM_4, IDENTIFIANT_4,CODEPOSTAL_4 ),
        make_shared<Client> (CLIENT_5,PRENOM_5, IDENTIFIANT_5,CODEPOSTAL_5 ),
        make_shared<Client> (CLIENT_6,PRENOM_6, IDENTIFIANT_6,CODEPOSTAL_6 ),
    };
    vector <shared_ptr <Fournisseur> > fournisseurs = {
        make_shared<Fournisseur> ("fournisseur1"),
        make_shared<Fournisseur> ("fournisseur2"),
    };
    // ajouter des produits dans les fournisseurs
    fournisseurs[0] ->operator+(produits[0]);
    fournisseurs[0]->operator+(produits[1]);
    fournisseurs[0]->operator+(produits[2]);

    fournisseurs[1]->operator+ (produits[3]);
    fournisseurs[1]->operator+ (produits[4]);

     // ajouter  Fournisseur,  Client, dans Compagnie
    polyReno + fournisseurs[0];
    polyReno + fournisseurs[1];

    polyReno + clients[0];
    polyReno + clients[1];
    polyReno + clients[2];
    polyReno + clients[3];


    if ((polyReno.getClients().size ()== 4) &&
         (polyReno.getProduits().size()==5) &&
         (polyReno.getFournisseurs().size() == 2))
         points += 1;
    else
        cout << "\033[31m" << "Echec du test ajout Client Fournisseur Produit dans Compagnie"
            << endl << SEPARATEUR_1 << "\033[0m\n";
    // retirer Client et fournisseur
    polyReno -  clients[2];
    
    polyReno - fournisseurs[0];
    if ((polyReno.getClients().size ()== 3) &&
        (polyReno.getProduits().size()== 2) &&
        (polyReno.getFournisseurs().size() == 1))
         points += 1;
    else
        cout << "\033[31m" << "Echec du test  supprimer  Client Fournisseur dans Compagnie"
            << endl << SEPARATEUR_1 << "\033[0m\n";

     // tester  chercherProduit existant
    if (polyReno.chercherProduit(produits[3]))
        points +=1;
    else
        cout << "\033[31m" << "Echec du test chercherProduit dans Compagnie"
            << endl << SEPARATEUR_1 << "\033[0m\n";

    // tester  chercherProduit non existant
    if (!polyReno.chercherProduit(produits[5]))
        points +=1;
    else
        cout << "\033[31m" << "Echec du test  chercherProduit dans Compagnie"
            << endl << SEPARATEUR_1 << "\033[0m\n";

   // chercherClient existant
    polyReno + clients[2];
    polyReno + fournisseurs[0];
    if (polyReno.chercherClient(clients[2]))
        points +=0.75;
    else
        cout << "\033[31m" << "Echec du test chercherClient dans Compagnie"
            << endl << SEPARATEUR_1 << "\033[0m\n";

    // tester  chercherClient non existant
    if (!polyReno.chercherClient(clients[5]))
        points +=0.75;
    else
        cout << "\033[31m" << "Echec du test  chercherClient dans Compagnie"
            << endl << SEPARATEUR_1 << "\033[0m\n";

    polyReno.acheter(clients[2], produits[1]);
    polyReno.acheter(clients[2], produits[4]);
    polyReno.acheter(clients[2], produits[3]);
    if (static_cast<int>(clients[2]->getCoutPanier())== 45)
        points +=0;
    else
        cout << "\033[31m" << "Echec  acheter dans Compagnie"
            << endl << SEPARATEUR_1 << "\033[0m\n";

     // tester mise aux enchères
    polyReno.encherir(clients[2], produits[1],100 ) ;

    if (static_cast<int>(clients[2]->getCoutPanier())== 95)
        points +=0.0;
    else
        cout << "\033[31m" << "Echec  encherir dans Compagnie"
            << endl << SEPARATEUR_1 << "\033[0m\n";

    if (!polyReno.encherir(clients[2], produits[2],100 ))
        points +=0.0;
    else
        cout << "\033[31m" << "Echec  encherir dans Compagnie"
            << endl << SEPARATEUR_1 << "\033[0m\n";

    if (!polyReno.encherir(clients[4], produits[1],100 ))
        points +=0.0;
    else
        cout << "\033[31m" << "Echec  encherir dans Compagnie"
            << endl << SEPARATEUR_1 << "\033[0m\n";

    if (polyReno.getChiffreAffaires() == 0 )
       points +=0.0;
    else
        cout << "\033[31m" << "Echec  getChiffresAffaires dans Compagnie"
            << endl << SEPARATEUR_1 << "\033[0m\n";

    // livraison des paniers
    polyReno.acheter(clients[0], produits[1]);
    polyReno.acheter(clients[0], produits[4]);
    polyReno.acheter(clients[0], produits[3]);

    polyReno.livrer(clients[0]);
    polyReno.livrer(clients[2]);
    if (static_cast<int> (polyReno.getChiffreAffaires()) == 203 && 
       polyReno.getProduitsAchetes().size() == 3)
        points +=1.5;
    else
        cout << "\033[31m" << "Echec  livrer dans Compagnie"
             << endl << SEPARATEUR_1 << "\033[0m\n";

     // test combien  Produit en Vente
    if (polyReno.combienProduitEnVente() ==  2)
        points +=1;
    else
        cout << "\033[31m" << "Echec  combienProduitEnVente dans Compagnie"
            << endl << SEPARATEUR_1 << "\033[0m\n";

string nom = "Scie";   
const auto trouverProduit = [nom](const Produit & p) {
return p.getNom() == nom;};
auto produit = polyReno.listersi<Produit,vector<shared_ptr< Produit> > >(polyReno.getProduits(), trouverProduit);
if (produit->getNom() == "Scie")
       points +=1;

nom = "fournisseur2";      
const auto  trouverFournisseur = [nom](const Fournisseur & f) {
return f.getNom() == nom;}; 
auto fournisseur = polyReno.listersi<Fournisseur,vector<shared_ptr< Fournisseur>> > (polyReno.getFournisseurs(), trouverFournisseur);
if (fournisseur->getNom() == "fournisseur2")
       points +=1;

// chercher client plus d'achat 
    polyReno +clients[3];
    polyReno + clients[4];
    polyReno.acheter(clients[3], produits[1]);

    polyReno.livrer(clients[3]); 
    shared_ptr<Client> unClient = polyReno.chercherClientPlusAchat();
    if (unClient->getNom() == "Client1")
      points +=1.5;
    else
    cout << "\033[31m" << "Echec  chercherClientPlusAchat dans Compagnie"
            << endl << SEPARATEUR_1 << "\033[0m\n";
    
    polyReno.acheter(clients[4], produits[1]);
    polyReno.acheter(clients[4], produits[1]);
    polyReno.livrer(clients[4]);
    shared_ptr<Produit> unProduit = polyReno.getProduitPopulaire();
    if ( unProduit-> getNom()=="Scie")
     points +=1.5;
    else
    cout << "\033[31m" << "Echec  getProduitPoulaire dans Compagnie"
            << endl << SEPARATEUR_1 << "\033[0m\n";
   return points;
 }
 
void lancerTests()
{

    cout << SEPARATEUR_1;
    cout << "\033[35m"
         << "Lancement des tests pour la classe Produit."
         << "\033[0m\n";
    cout << SEPARATEUR_1;
    double point1 = testProduit();
    cout << "\033[32m => " << fixed << setprecision(2) << point1 << "/0"
         << "\033[0m\n";

    cout << SEPARATEUR_1;
    cout << "\033[35m"
         << "Lancement des tests pour la classe Panier."
         << "\033[0m\n";
    cout << SEPARATEUR_1;
    double point2 = testPanier();
    cout << "\033[32m => " << fixed << setprecision(2) << point2 << "/4.5"
         << "\033[0m\n";
    cout << SEPARATEUR_1;

    cout << "\033[35m"
         << "Lancement des tests pour la classe Fournisseur."
         << "\033[0m\n";
    cout << SEPARATEUR_1;
    double point3 = testFournisseur();
    cout << "\033[32m => " << fixed << setprecision(2) << point3 << "/2.5"
         << "\033[0m\n";
    cout << SEPARATEUR_1;
    
        // cout << SEPARATEUR_1;
        // cout << "\033[35m" << "Lancement des tests pour la classe Client." << "\033[0m\n";
        // cout << SEPARATEUR_1;
        double point4 = 0.0;
        // double point4 = testClient();
        // cout << "\033[32m => " << fixed << setprecision(2) << point4 << "/3.0" << "\033[0m\n";

        cout << SEPARATEUR_1;
        cout << "\033[35m" << "Lancement des tests pour la classe Compagnie." << "\033[0m\n";
        cout << SEPARATEUR_1;
        double point5 = testCompagnie();
        cout << "\033[32m => " << fixed << setprecision(2) << point5 << "/13" << "\033[0m\n";

        cout << SEPARATEUR_2;
       cout << "Total des points: " << "\033[32m" << fixed << setprecision(2)
        << point1 + point2 + point3 + point4 + point5<< "/20.0" << "\033[0m" << endl;
        cout << SEPARATEUR_2;
        
}
