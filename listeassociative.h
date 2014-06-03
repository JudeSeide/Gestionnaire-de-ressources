#if !defined(__LISTE_ASSOCIATIVE_H__)
#define __LISTE_ASSOCIATIVE_H__

#include "liste.h"

template <class K, class V>
class Map {
public:

    virtual ~Map() {
    }

    virtual void enlever(const K&) = 0;
    virtual bool contient(const K&) const = 0;

    virtual const V& operator[] (const K&) const = 0;
    virtual V& operator[] (const K&) = 0;
};

template <class K, class V>
class ListeAssociative : public Map<K, V> {
private:

    struct Entree {

        Entree() {
        }

        Entree(const K& c) : cle(c) {
        }
        K cle;
        V valeur;

        bool operator ==(const Entree& e) const {
            return cle == e.cle;
        }
    };

    Liste<Entree> entrees;

public:

    virtual bool contient(const K&) const;

    virtual void enlever(const K&);
    void vider();

    virtual const V& operator[] (const K&) const;
    virtual V& operator[] (const K&);

    class IterateurConst {
    public:

        IterateurConst(const ListeAssociative& l) : iter(l.entrees) {
        }

        operator bool() const {
            return iter.operator bool();
        };

        IterateurConst& operator++() {
            ++iter;
            return *this;
        }

        const K& cle() const {
            return (*iter).cle;
        }

        const V& valeur() const {
            return (*iter).valeur;
        }

    private:
        typename Liste<Entree>::Iterateur iter;
    };

    class Iterateur {
    public:

        Iterateur(ListeAssociative& l) : iter(l.entrees) {
        }

        operator bool() const {
            return iter.operator bool();
        };

        Iterateur& operator++() {
            ++iter;
            return *this;
        }

        const K& cle() const {
            return (*iter).cle;
        }

        V& valeur() {
            return (V&) (*iter).valeur;
        }

    private:
        typename Liste<Entree>::Iterateur iter;
    };

    IterateurConst debut() const {
        return IterateurConst(*this);
    }

    Iterateur debut() {
        return Iterateur(*this);
    }

};

template <class K, class V>
void ListeAssociative<K, V>::vider() {
    entrees.vider();
}

template <class K, class V>
void ListeAssociative<K, V>::enlever(const K& c) {
    Entree e(c);
    typename Liste<typename ListeAssociative<K, V>::Entree>::Iterateur iter = entrees.trouver(e);
    entrees.enlever(iter);
}

template <class K, class V>
bool ListeAssociative<K, V>::contient(const K& c) const {
    return entrees.trouver(c) != entrees.fin();
}

template <class K, class V>
const V& ListeAssociative<K, V>::operator[] (const K& c) const {
    typename Liste<Entree>::Iterateur iter = entrees.trouver(c);
    return entrees[iter].valeur;
}

template <class K, class V>
V& ListeAssociative<K, V>::operator[] (const K& c) {
    typename Liste<Entree>::Iterateur iter(entrees);
    while (iter && entrees[iter].cle < c) {
        ++iter;
    }
    if (!iter || c < entrees[iter].cle) {
        iter = entrees.inserer(Entree(c), iter);
    }
    return entrees[iter].valeur;
}


#endif

