#include "Ressource.h"


bool Ressource::disponible() const
{
  return capacite >= 0;
}

Ressource& Ressource::operator += (const Ressource& other)
{
  if(nom == other.nom)
  capacite += other.capacite;
  return *this;
}

Ressource Ressource::operator + (const Ressource& other) const
{
  Ressource temp = *this;
   temp += other;
  return temp;
}

Ressource& Ressource::operator -= (const Ressource& other)
{
  if(nom == other.nom)
  capacite -= other.capacite;
  return *this;
}
Ressource Ressource::operator - (const Ressource& other) const
{
  Ressource temp = *this;
  temp -= other;
  return temp;
}

/*Ressource Ressource::operator - () const
{
  capacite *= -1;
  return *this;
}
*/
bool Ressource::operator == (const Ressource& r) const
{
  return nom == r.nom;
}

bool Ressource::operator != (const Ressource& r) const
{
  return nom != r.nom;
}

bool Ressource::operator < (const Ressource& r) const
{
  return nom < r.nom;
}

bool Ressource::operator > (const Ressource& r) const
{

  return nom > r.nom;
}

ostream& operator << (ostream& os, const Ressource& r)
{
  os << r.nom << " : " << r.capacite;
  return os;
}

istream& operator >> (istream& is, Ressource& r)
{
  char deuxpoints;
  if(is){
    is >> r.nom >> deuxpoints >> r.capacite;
    assert(deuxpoints ==':');
  }
  return is;
}
