#include "ressource.h"

Ressource::Ressource() {
    nom = "inconnu";
    nombre = 0;
}

Ressource::Ressource(const Ressource& r)
: nom(r.nom), nombre(r.nombre) {
    tachesUtilisant = r.tachesUtilisant;
}

bool Ressource::isOk() const {
    return nombre >= 0;
}

Ressource& Ressource::operator +=(const Ressource& other) {
    assert(nom == other.nom);
    nombre += other.nombre;
    return *this;
}

Ressource Ressource::operator +(const Ressource& other) const {
    Ressource result = *this;
    result += other;
    return result;
}

Ressource& Ressource::operator -=(const Ressource& other) {
    assert(nom == other.nom);
    nombre -= other.nombre;
    return *this;
}

Ressource Ressource::operator -(const Ressource& other) const {
    Ressource result = *this;
    result -= other;
    return result;
}

Ressource Ressource::operator -() const {
    Ressource r(*this);
    r.nombre *= -1;
    return r;
}

bool Ressource::operator ==(const Ressource& r) const {
    return nom == r.nom;
}

bool Ressource::operator !=(const Ressource& r) const {
    return nom != r.nom;
}

std::ostream& operator <<(std::ostream& os, const Ressource& r) {
    os << r.nom << " : " << r.nombre;
    return os;
}

std::istream& operator >>(std::istream& is, Ressource& r) {
    char deuxpoints;
    if (is) {
        is >> r.nom >> deuxpoints >> r.nombre;
        assert(deuxpoints == ':');
    }
    return is;
}


