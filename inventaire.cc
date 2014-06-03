#include "inventaire.h"
#include <assert.h>

Inventaire::Inventaire() {
}

Inventaire::Inventaire(const Inventaire& other) {
    ressources = other.ressources;
}

bool Inventaire::isOk() const {
    Liste<Ressource>::Iterateur iter(ressources);
    while (iter) {
        if (!(*iter).isOk()) {
            return false;
        }
        ++iter;
    }
    return true;
}

Inventaire& Inventaire::operator +=(const Inventaire& other) {
    Liste<Ressource>::Iterateur other_iter = other.ressources.debut();
    while (other_iter) {
        Liste<Ressource>::Iterateur iter = ressources.trouver(*other_iter);
        if (iter) {
            ressources[iter] += *other_iter;
        } else {
            iter = ressources.inserer_fin(*other_iter);
        }
        ++other_iter;
    }
    return *this;
}

Inventaire Inventaire::operator +(const Inventaire& other) const {
    Inventaire result(*this);
    result += other;
    return result;
}

Inventaire& Inventaire::operator -=(const Inventaire& other) {
    Liste<Ressource>::Iterateur other_iter = other.ressources.debut();
    while (other_iter) {
        Liste<Ressource>::Iterateur iter = ressources.trouver(*other_iter);
        if (iter) {
            ressources[iter] -= *other_iter;
        } else {
            iter = ressources.inserer_fin(- *other_iter);
        }
        ++other_iter;
    }
    return *this;
}

Inventaire Inventaire::operator -(const Inventaire& other) const {
    Inventaire result(*this);
    result -= other;
    return result;
}

std::ostream& operator <<(std::ostream& os, const Inventaire& e) {
    for (Liste<Ressource>::Iterateur iter(e.ressources); iter; iter++) {
        os << "* " << *iter << std::endl;
    }
    os << "-" << std::endl;
    return os;
}

std::istream& operator >>(std::istream& is, Inventaire& e) {
    e.ressources.vider();
    char c;
    is >> c;
    while (c == '*') {
        Ressource r;
        is >> r >> std::ws;
        e.ressources.inserer_fin(r);
        is >> c;
    }
    assert(c == '-');
    return is;
}


