#include "periode.h"

std::ostream& operator <<(std::ostream& os, const Periode& p) {
    os << p.debut << p.fin;
    return os;
}

std::istream& operator >>(std::istream& is, Periode& p) {
    if (is) {
        is >> p.debut >> p.fin;
    }
    return is;
}

