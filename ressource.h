#if !defined(__RESSOURCE_H__)
#define __RESSOURCE_H__

#include <iostream>
#include <string>
#include "liste.h"

class Ressource {
private:
    std::string nom;
    int nombre;
    Liste<int> tachesUtilisant;

    friend std::ostream& operator <<(std::ostream&, const Ressource&);
    friend std::istream& operator >>(std::istream&, Ressource&);

public:
    Ressource();
    Ressource(const Ressource& r);

    bool isOk() const;

    Ressource& operator +=(const Ressource& i);
    Ressource operator +(const Ressource& i) const;

    Ressource& operator -=(const Ressource& i);
    Ressource operator -(const Ressource& i) const;

    Ressource operator -() const;

    bool operator ==(const Ressource& r) const;
    bool operator !=(const Ressource& r) const;
};

#endif
