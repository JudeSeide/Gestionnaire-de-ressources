template <typename T>
Liste<T> ::~Liste() {
    viderListe();
}

template <typename T>
void Liste <T> ::insererElement(const T e) {
    if (premier == NULL) {
        premier = new Cellule<T>(e);
    } else if (e < premier->data) {
        Cellule<T>* temp = new Cellule<T>(e);
        temp->suivant = premier;
        premier = temp;
    } else {
        Cellule<T>* temp = new Cellule<T>(e);
        Cellule<T>* temp1 = premier;
        bool placer = false;
        while (temp1 -> suivant != NULL && !placer) {
            if (e < temp1 -> suivant -> data || e == temp1 -> suivant -> data) {
                temp -> suivant = temp1 -> suivant;
                temp1 -> suivant = temp;
                placer = true;
            } else {
                temp1 = temp1 -> suivant;
            }
        }
        if (!placer) {
            temp1 -> suivant = temp;
        }
        ++taille;
    }
}

template <typename T>
void Liste <T> ::afficherListe() {
    Cellule<T>* temp = premier;

    while (temp != NULL) {
        cout << temp->data << endl;
        temp = temp->suivant;
    }

}

template <typename T>
void Liste <T> ::supprimer(T e) {
    if (premier -> data == e) {
        Cellule<T>* temp = premier;
        premier = premier -> suivant;
        delete [] temp;
        temp = NULL;
    } else {
        Cellule<T>* temp = premier;
        bool supprimee = false;
        while (temp != NULL && !supprimee) {
            if (temp -> suivant -> data == e) {
                Cellule<T>* temp1 = temp -> suivant;
                temp -> suivant = temp1 -> suivant;
                delete [] temp1;
                supprimee = true;
                temp1 = NULL;

            } else
                temp = temp ->suivant;
        }

        temp = NULL;
    }

}

template <typename T>
void Liste <T> ::viderListe() {
    while (premier != NULL) {
        Cellule<T>* temp = premier;
        premier = premier -> suivant;
        std::cout << "delete " << temp << std::endl;
        delete[] temp;
        temp = NULL;
    }
}

template <typename T>
Liste<T>& Liste <T>::operator =(const Liste<T>& l) {
    assert(this != &l);
    viderListe();
    Cellule<T>* temp;
    temp = l.premier;
    while (temp != NULL) {
        insererElement(temp -> data);
        temp = temp -> suivant;
    }
    return *this;

}

template <typename T>
T Liste <T> ::rechercherElement(T e) {
    bool trouver = false;
    T eTemp = NULL;
    Cellule<T>* temp = premier;
    while (temp != NULL &&!trouver) {
        if (temp->data == e) {
            trouver = true;
            eTemp = e;
        } else {
            temp = temp->suivant;
        }
    }
    return eTemp;
}

template <typename T>
bool Liste <T> ::contient(const T e) {
    return rechercherElement(e) != NULL;
}

template <typename T>
Iterateur<T> Liste <T> ::debut() const {
    Iterateur<T> iter = Iterateur<T>(*this);
    return iter;
}
