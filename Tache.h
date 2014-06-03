#ifndef TACHE_H_INCLUDED
#define TACHE_H_INCLUDED

#include "Inventaire.h"


using namespace std;

class Tache
{

    public:


        friend ostream& operator << (ostream& os, const Tache& t);
        friend istream& operator >> (istream& is, Tache& t);

        bool operator < (const Tache& t) const;
        bool operator == (const Tache& t) const;

        bool conflit(const Tache& t);

        Inventaire& getBesoin();
        int getNumero();

    private:

        Inventaire deRessources;
        int debut;
        int fin;
        int numeroId;


};


#endif // TACHE_H_INCLUDED
