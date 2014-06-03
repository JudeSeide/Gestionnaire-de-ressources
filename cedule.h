#if !defined(__CEDULE_H__)
#define __CEDULE_H__

#include <iostream>
#include "listeassociative.h"
#include "inventaire.h"
#include "tache.h"

class Cedule {
public:
    Cedule(const Inventaire init);
    Cedule(const Cedule&);

    void ajouter(const Tache& tache);
    bool sansRupture() const;

private:
    ListeAssociative<int, Inventaire> inventaires;

    friend std::ostream& operator <<(std::ostream&, const Cedule&);
};

#endif

