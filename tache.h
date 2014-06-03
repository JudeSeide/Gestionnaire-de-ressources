#if !defined(__TACHE_H__)
#define __TACHE_H__

#include <iostream>
#include "inventaire.h"
#include "periode.h"

class Tache {
private:
    int numero;
    Periode periode;
    Inventaire besoins;

public:

    int getNumero() const {
        return numero;
    }

    friend std::ostream& operator <<(std::ostream&, const Tache&);
    friend std::istream& operator >>(std::istream&, Tache&);
    friend class Cedule;
};
#endif
