#ifndef AFFICHABLE_H
#define AFFICHABLE_H
#include <iostream>
using namespace std;
class Affichable {
public:
   // destructeur virtuel
    virtual ~Affichable() = 0;
   //  fonction amie operator <<
    friend ostream& operator<<(ostream& out, const Affichable& a);
protected:
    // fonction  membre afficher() virtuelle pure
    virtual ostream & afficher(ostream& out) const = 0;
};
#endif