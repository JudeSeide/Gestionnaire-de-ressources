#include "Inventaire.h"

Inventaire::Inventaire(const Inventaire& other)
{
  ressources = other.ressources;
}

bool Inventaire::sansRupture() const
{
  Iterateur<Ressource> iter = ressources.debut();
  while(iter)
  {
      if( !(*iter).disponible() )
      {
          return false;
      }
      iter++;
  }
  return true;
}

Inventaire& Inventaire::operator += (const Inventaire& other)
{
    Iterateur<Ressource> iter(ressources);
    Iterateur<Ressource> iter_other(other.ressources);
    for(iter_other = other.ressources.debut();iter_other;iter_other++)
    {
        for(iter = ressources.debut();iter ;iter++)
        {
            if((*iter) == (*iter_other))
            {
                (*iter) = (*iter) + (*iter_other);
            }
            else
            {
                ressources.insererElement(*iter_other);
            }
        }
    }

  return *this;
}

Inventaire Inventaire::operator + (const Inventaire& other) const
{
    Inventaire result(*this);
    result += other;
    return result;
}

Inventaire& Inventaire::operator -= (const Inventaire& other)
{
    Iterateur<Ressource> iter(ressources);
    Iterateur<Ressource> iter_other(other.ressources);
    for(iter_other = other.ressources.debut();iter_other;iter_other++)
    {
        for(iter = ressources.debut();iter ;iter++)
        {
            if((*iter) == (*iter_other))
            {
                (*iter) = (*iter) - (*iter_other);

            }
        }
    }

  return *this;
}

Inventaire Inventaire::operator - (const Inventaire& other) const{
  Inventaire result(*this);
  result -= other;
  return result;
}


ostream& operator << (ostream& os, const Inventaire& e){
    Iterateur<Ressource> iter(e.ressources);
  for(iter = e.ressources.debut();iter;iter++){
    os << "* " << *iter << std::endl;
  }
  os << "-" << std::endl;
  return os;
}

std::istream& operator >> (std::istream& is, Inventaire& e){
  e.ressources.viderListe();
  char c;
  is >> c;
  while(c=='*'){
    Ressource r;
    is >> r >> std::ws;
    e.ressources.insererElement(r);
    is >> c;
  }
  assert(c=='-');
  return is;
}

