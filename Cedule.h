#ifndef CEDULE_H_INCLUDED
#define CEDULE_H_INCLUDED
#include <iostream>
#include "Liste.h"
#include "Inventaire.h"
#include "Tache.h"

using namespace std;

class Cedule
{
    public:

        Cedule(const Inventaire& i);
        Cedule(const Cedule&);
        void ajouter(Tache& t);
        bool sansRupture() const;
        Liste<int>& getConflitsNumerosTaches();

    private:

        Liste<Tache> todo;
        Inventaire besoins;
        Liste<int> conflits;
};


#endif // CEDULE_H_INCLUDED
