/*
  INF3105 - Structures de données et algorithmes
  Session Hiver 2012.
  TP2 - Partie A

  Auteur(s):

*/
#include "Cedule.h"
Cedule :: Cedule(const Inventaire& i)
{
    besoins = i;
    //todo = Liste<Tache>();
    //conflits = Liste<int>();
}

Cedule :: Cedule(const Cedule& c)
{
    todo = c.todo;
    besoins = c.besoins;
    conflits  = c.conflits;
}

void Cedule::ajouter(Tache& t)
{
std::cout << "Cedule::ajouter()\n";
    Inventaire temp(t.getBesoin());
std::cout << "Cedule::ajouter()\n";
    cout << temp << endl;
    Liste<Tache> liste;
    liste.insererElement(t);
std::cout << "Cedule::ajouter()\n";
    
    todo.insererElement(t);
std::cout << "Cedule::ajouter()\n";
    besoins = besoins - temp;
std::cout << "Cedule::ajouter()\n";
}

bool Cedule::sansRupture() const
{
    return besoins.sansRupture();
}

Liste<int>& Cedule:: getConflitsNumerosTaches()
{

    Iterateur<Tache> iter(todo), iter2(todo);
    iter = todo.debut();
    iter2 = iter;
    for(iter;iter;iter++)
    {
         iter2 = iter;
        for(++iter2; iter2; iter2++)
        {
            if((*iter).conflit(*iter2))
            {
                conflits.insererElement((*iter2).getNumero());
            }
        }
    }
    return *&conflits;
}

