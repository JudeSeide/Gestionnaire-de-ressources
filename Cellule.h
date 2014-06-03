#ifndef CELLULE_H_INCLUDED
#define CELLULE_H_INCLUDED
#include <iostream>

template <typename T>
class Liste;
template <typename T>
class Iterateur;

template <typename T>
class Cellule {
public:
    friend class Liste<T>;
    friend class Iterateur<T>;

    Cellule(const T& d, Cellule * s) : data(d),
    suivant(s) {
    }

    Cellule(const T& d) : data(d), suivant(NULL) {
    }

    Cellule(const Cellule& copie) : data(NULL), suivant(NULL) {
        *this = copie;
    }

    virtual ~Cellule() {
        delete suivant;
        data = NULL;
    }

    Cellule operator =(const Cellule& copie) {
        this->data = copie.data;
        this->suivant = copie.suivant;
    }

    bool operator ==(const Cellule& cellule) {
        return data == cellule.data;
    }

    bool operator !=(const Cellule& cellule) {
        return data != cellule.data;
    }

    bool operator<(const Cellule& cellule) {
        return data < cellule.data;
    }


private:
    T data;
    Cellule* suivant;

};

#endif // CELLULE_H_INCLUDED
