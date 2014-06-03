#ifndef RESSOURCE_H_INCLUDED
#define RESSOURCE_H_INCLUDED
#include <cassert>
#include <iostream>

using namespace std;

class Ressource
{
    public:


        bool disponible() const;

        Ressource& operator += (const Ressource&);
        Ressource operator + (const Ressource&) const;

        Ressource& operator -= (const Ressource&);
        Ressource operator - (const Ressource&) const;

        //Ressource operator - () const;

        bool operator == (const Ressource& r) const;
        bool operator != (const Ressource& r) const;
        bool operator < (const Ressource& r) const;
        bool operator > (const Ressource& r) const;

  private:

        string nom;
        int capacite;

        friend ostream& operator << (ostream&, const Ressource&);
        friend istream& operator >> (istream&, Ressource&);

};



#endif // RESSOURCE_H_INCLUDED
