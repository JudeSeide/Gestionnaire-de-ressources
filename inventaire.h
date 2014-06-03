#if !defined(__INVENTAIRE_H__)
#define __INVENTAIRE_H__

#include <iostream>
#include "ressource.h"

class Inventaire {
private:
    Liste<Ressource> ressources;

public:
    Inventaire();
    Inventaire(const Inventaire&);

    bool isOk() const;

    Inventaire& operator +=(const Inventaire& i);
    Inventaire operator +(const Inventaire& i) const;

    Inventaire& operator -=(const Inventaire& i);
    Inventaire operator -(const Inventaire& i) const;

    friend std::ostream& operator <<(std::ostream&, const Inventaire&);
    friend std::istream& operator >>(std::istream&, Inventaire&);
};
#endif

