#ifndef LISTE_H_INCLUDED
#define LISTE_H_INCLUDED

#include "Iterateur.h"
#include <iostream>
#include "Cellule.h"
#include <assert.h>
using namespace std;

/**
 * La liste est maintenue triee en ordre croissant, le tri insertion est utilise
 */

template <typename T> class Liste {
public:

    Liste() : premier(NULL), taille(0) {
    }

    Liste(const Liste<T>& copie) : premier(NULL) {
        *this = copie;
        this->taille = copie.taille;
    }

    virtual ~Liste();

    friend class Iterateur <T>;

    void insererElement(const T);
    void afficherListe();
    void supprimer(T);
    void viderListe();

    bool contient(const T);
    T rechercherElement(const T);

    Iterateur <T> debut() const;

    bool operator ==(const Liste<T>&) const;

    Liste<T>& operator =(const Liste<T>&);

    const T& operator[](const Iterateur<T>& iter) const {
        return *iter;
    }

private:
    Cellule<T>* premier;
    int taille;
};

#include "Liste.cpp"
#endif // LISTE_H
