#ifndef ITERATEUR_H_INCLUDED
#define ITERATEUR_H_INCLUDED
#include <cassert>
#include "Cellule.h"
#include "Liste.h"

template <typename T>class Iterateur
{
    public:
	    Iterateur(const Liste<T>& a);
        Iterateur(const Iterateur<T>& a);
        Iterateur(const Liste<T>&, Cellule<T>*);

        operator  bool () const{ return curseur != NULL;}
        bool operator !() const{ return curseur == NULL;}
        bool operator==(const Iterateur<T>&) const;
        bool operator!=(const Iterateur<T>&) const;

        T& operator*() const;

        Iterateur<T>& operator++();
    	Iterateur<T> operator++(int);

        Iterateur<T>& operator = (const Iterateur&);

     private:
        const Liste<T>& listeAssocie;
        Cellule<T>* curseur;

	friend class Liste<T>;
};
#include "Iterateur.cpp"
#endif // ITERATEUR_H_INCLUDED
