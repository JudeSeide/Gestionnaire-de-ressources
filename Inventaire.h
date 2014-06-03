#ifndef INVENTAIRE_H_INCLUDED
#define INVENTAIRE_H_INCLUDED
#include <iostream>
#include "Ressource.h"
#include "Liste.h"
#include "Iterateur.h"

using namespace std;

class Inventaire
{
    public:

        Inventaire(){};
        Inventaire(const Inventaire&);

        //Un inventaire est sans rupture ssi tous les ressources sont disponibles
        bool sansRupture() const;

        Inventaire& operator += (const Inventaire& i);
        Inventaire operator + (const Inventaire& i) const;

        Inventaire& operator -= (const Inventaire& i);
        Inventaire operator - (const Inventaire& i) const;

        friend ostream& operator << (ostream&, const Inventaire&);
        friend istream& operator >> (istream&, Inventaire&);

    private:

        Liste<Ressource> ressources;
};

#endif // INVENTAIRE_H_INCLUDED
