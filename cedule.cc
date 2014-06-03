#include "cedule.h"
#include <assert.h>

Cedule::Cedule(const Inventaire init) {
    inventaires[0] = init;
}

Cedule::Cedule(const Cedule& c) {
    inventaires = c.inventaires;
}

void Cedule::ajouter(const Tache& tache) {

    ListeAssociative<int, Inventaire>::Iterateur iter(inventaires);
    Inventaire* dernier = NULL;

    while (iter) {
        if (iter.cle() >= tache.periode.getDebut()) {
            break;
        }
        dernier = &(iter.valeur());
        ++iter;
    }

    if (!iter || tache.periode.getDebut() < iter.cle()) {
        Inventaire& cible = inventaires[tache.periode.getDebut()];
        cible = *dernier - tache.besoins;
        dernier = &cible;
        if (iter && tache.periode.getDebut() == iter.cle()) {
            ++iter;
        }
    } else {
        assert(iter.cle() == tache.periode.getDebut());
    }

    while (iter) {
        if (iter.cle() >= tache.periode.getFin()) {
            break;
        }
        dernier = &(iter.valeur());
        *dernier -= tache.besoins;
        ++iter;
    }

    if (!iter || tache.periode.getFin() < iter.cle()) {
        inventaires[tache.periode.getFin()] = *dernier + tache.besoins;
    }
}

bool Cedule::sansRupture() const {
    ListeAssociative<int, Inventaire>::IterateurConst iter(inventaires);
    while (iter) {
        if (!iter.valeur().isOk()) {
            return false;
        }
        ++iter;
    }
    return true;
}

std::ostream& operator <<(std::ostream& os, const Cedule& c) {
    ListeAssociative<int, Inventaire>::IterateurConst iter(c.inventaires);
    while (iter) {
        os << "[Temps=" << iter.cle() << "]\n";
        os << iter.valeur() << std::endl;
        ++iter;
    }
    return os;
}


