#if !defined(__LISTE_H__)
#define __LISTE_H__

#include <assert.h>

template <class T>
class Liste {
public:
    class Iterateur;

    Liste();
    ~Liste();

    bool estVide() const;
    void vider();

    const Liste& operator =(const Liste&);

    T& operator[] (const Iterateur&);
    const T& operator[] (const Iterateur&) const;

    Iterateur inserer(const T&, const Iterateur&);
    Iterateur enlever(const Iterateur&);

    Iterateur inserer_debut(const T&);
    Iterateur inserer_fin(const T&);

    Iterateur debut() const;
    Iterateur fin() const;

    Iterateur trouver(const T&) const;
    Iterateur trouverBourneInf(const T&) const;

protected:

    class Cellule {
    public:

        Cellule(const T& c, Cellule* s = NULL) : suivante(s) {
            contenu = c;
        }
        T contenu;
        Cellule* suivante;
    };

public:

    class Iterateur {
    public:
        Iterateur(const Iterateur&);
        Iterateur(const Liste&);

        Iterateur& operator=(int);

        operator bool() const;
        bool operator!() const;
        bool operator==(const Iterateur&) const;
        bool operator!=(const Iterateur&) const;

        Iterateur operator++(int);
        Iterateur& operator++();

        const T& operator*() const;

        Iterateur operator+(int) const;

        Iterateur& operator+=(int);
        Iterateur& operator =(const Iterateur&);

    protected:
        Cellule* courante;
        const Liste& liste;
        friend class Liste;
    };

protected:
    Liste(const Liste&);

    Cellule* premiere;
};


// Implémentation des constructeurs, destructeurs et fonctions

template <class T>
Liste<T>::Liste() {
    premiere = NULL;
}

template <class T>
Liste<T>::~Liste() {
    vider();
}

template <class T>
bool Liste<T>::estVide() const {
    return premiere == NULL;
}

template <class T>
void Liste<T>::vider() {
    Cellule* c = premiere;
    while (c) {
        Cellule* t = c->suivante;
        delete c;
        c = t;
        if (c == premiere) c = NULL;
    }
    premiere = NULL;
}

template <class T>
const Liste<T>& Liste<T>::operator =(const Liste<T>& autre) {
    if (this == &autre) return *this;

    Iterateur ia(autre);
    Iterateur i(*this);
    for (; ia; ++ia) {
        if (i)
            (*this)[i++] = *ia;
        else
            inserer_fin(*ia);
    }
    return *this;
}

template <class T>
T& Liste<T>::operator [](const Iterateur& i) {
    assert(i.courante);
    return i.courante->suivante->contenu;
}

template <class T>
const T& Liste<T>::operator [](const Iterateur& i) const {
    assert(i.courante);
    return i.courante->suivante->contenu;
}

template <class T>
typename Liste<T>::Iterateur Liste<T>::inserer(const T& e, const Iterateur& i) {
    assert(this == &i.liste);
    Iterateur position(i);
    Cellule* c = i.courante;
    if (premiere == NULL) {
        premiere = new Cellule(e);
        c = premiere->suivante = premiere;
    } else
        if (c == NULL) {
        c = premiere;
        premiere->suivante = new Cellule(e, premiere->suivante);
        premiere = premiere->suivante;
    } else
        c->suivante = new Cellule(e, c->suivante);
    position.courante = c;
    return position;
}

template <class T>
typename Liste<T>::Iterateur Liste<T>::inserer_debut(const T& e) {
    Iterateur position(*this);
    if (premiere == NULL) {
        premiere = new Cellule(e);
        position.courante = premiere->suivante = premiere;
    } else
        position.courante->suivante = new Cellule(e, position.courante->suivante);
    return position;
}

template <class T>
typename Liste<T>::Iterateur Liste<T>::inserer_fin(const T& e) {
    Iterateur position(*this);
    if (premiere == NULL) {
        premiere = new Cellule(e);
        position.courante = premiere->suivante = premiere;
    } else {
        position.courante = premiere;
        premiere->suivante = new Cellule(e, premiere->suivante);
        premiere = premiere->suivante;
    }
    return position;
}

template <class T>
typename Liste<T>::Iterateur Liste<T>::enlever(const Iterateur& i) {
    assert(&i.liste == this);
    Iterateur position(i);
    Cellule* c = i.courante;
    assert(c != NULL && premiere != NULL);
    Cellule* temp = c->suivante;
    c->suivante = temp->suivante;
    delete temp;
    Cellule* retour = temp == premiere ? NULL : c;
    if (premiere == temp) premiere = c;
    if (temp == c)
        premiere = c = NULL;
    position.courante = retour;
    return position;
}

template <class T>
typename Liste<T>::Iterateur Liste<T>::debut() const {
    return Iterateur(*this);
}

template <class T>
typename Liste<T>::Iterateur Liste<T>::fin() const {
    Iterateur iter(*this);
    iter.courante = NULL;
    return iter;
}

template <class T>
typename Liste<T>::Iterateur Liste<T>::trouver(const T& e) const {
    Iterateur iter(*this);
    while (iter && !(*iter == e))
        iter++;
    return iter;
}

template <class T>
typename Liste<T>::Iterateur Liste<T>::trouverBourneInf(const T& e) const {
    Iterateur iter(*this);
    while (iter && (e < *iter))
        iter++;
    return iter;
}


//----------------------------------------------------//

template <class T>
Liste<T>::Iterateur::Iterateur(const Iterateur& i) :
liste(i.liste) {
    courante = i.courante;
}

template <class T>
Liste<T>::Iterateur::Iterateur(const Liste<T>& l) :
liste(l) {
    courante = l.premiere;
}

template <class T>
bool Liste<T>::Iterateur::operator !() const {
    return courante == NULL;
}

template <class T>
Liste<T>::Iterateur::operator bool() const {
    return courante != NULL;
}

template <class T>
bool Liste<T>::Iterateur::operator ==(const Iterateur& autre) const {
    return courante == autre.courante
            && &liste == &autre.liste;
}

template <class T>
bool Liste<T>::Iterateur::operator !=(const Iterateur& autre) const {
    return courante != autre.courante
            || &liste != &autre.liste;
}

template <class T>
typename Liste<T>::Iterateur Liste<T>::Iterateur::operator ++(int) {
    Iterateur temp(*this);
    courante = courante->suivante;
    if (courante == liste.premiere) courante = NULL;
    return temp;
}

template <class T>
typename Liste<T>::Iterateur& Liste<T>::Iterateur::operator ++() {
    courante = courante->suivante;
    if (courante == liste.premiere) courante = NULL;
    return *this;
}

template <class T>
const T& Liste<T>::Iterateur::operator *() const {
    return liste[*this];
}

template <class T>
typename Liste<T>::Iterateur& Liste<T>::Iterateur::operator+=(int n) {
    for (int i = 0; i < n; i++)
        operator++();
    return *this;
}

template <class T>
typename Liste<T>::Iterateur Liste<T>::Iterateur::operator +(int n) const {
    Iterateur t(*this);
    t += n;
    return t;
}

template <class T>
typename Liste<T>::Iterateur& Liste<T>::Iterateur::operator =(int n) {
    courante = liste.premiere;
    *this += n;
    return *this;
}

template <class T>
typename Liste<T>::Iterateur& Liste<T>::Iterateur::operator =(const Iterateur& autre) {
    assert(&liste == &autre.liste);
    courante = autre.courante;
    return *this;
}


#endif

