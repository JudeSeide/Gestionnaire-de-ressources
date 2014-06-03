template <class T>
Iterateur<T>::Iterateur(const Liste<T>& l)
:listeAssocie(l), curseur(l.premier)
{
}


template <class T>
Iterateur<T>::Iterateur(const Liste<T>& l, Cellule<T>* c)
{
    curseur = c;
    listeAssocie = l;
}

template <class T>
Iterateur<T>::Iterateur(const Iterateur<T>& i)
:listeAssocie(i.listeAssocie)
{
    curseur = i.curseur;

}

template <class T>
Iterateur<T>& Iterateur<T>::operator++()
{
    assert(curseur != NULL);
    curseur = curseur->suivant;
    return *this;
}

template <class T>
Iterateur<T> Iterateur<T>::operator++(int)
{
    Iterateur copie(*this);
    operator++();
    return copie;
}


template <class T>
bool Iterateur<T>::operator ==(const Iterateur& iter) const
{
    return curseur == iter.curseur;
}

template <class T>
bool Iterateur<T>::operator !=(const Iterateur& iter) const
{
    return curseur != iter.curseur;
}

template <class T>
T& Iterateur<T>::operator *() const
{
    assert(curseur != NULL);
    return curseur->data;
}

template <class T>
Iterateur<T>& Iterateur<T>::operator = (const Iterateur& iter)
{
     if (this != &iter)
     {
         curseur = iter.curseur;
     }
     return *this;
}

