#include "tache.h"

std::ostream& operator <<(std::ostream& os, const Tache& t) {
    os << t.numero << std::endl;
    os << t.periode << std::endl;
    os << t.besoins;
    return os;
}

std::istream& operator >>(std::istream& is, Tache& t) {
    is >> t.numero;
    if (!is) {
        return is;
    }
    is >> t.periode;
    is >> t.besoins;
    return is;
}
