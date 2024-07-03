#include "Affichable.h"
// to do
ostream& operator<<(ostream& out, const Affichable& a)
{
    return a.afficher(out);
}

Affichable::~Affichable() = default;