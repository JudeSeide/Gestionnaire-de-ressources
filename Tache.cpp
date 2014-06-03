#include "Tache.h"

/*Tache::Tache(int id, int hD, int hF, Inventaire i)
{
    numeroId = id;
    debut = hD;
    fin = hF;
    deRessources = i;
}*/
ostream& operator << (ostream& os, const Tache& t)
{
    os << t.numeroId << endl;
    os << t.debut  << t.fin<< endl;
    os << t.deRessources;
    return os;
}

istream& operator >> (istream& is, Tache& t)
{
    is >> t.numeroId;
    if(!is)
    {
        return is;
    }
    is >> t.debut >> t.fin;
    is >> t.deRessources;
    return is;
}

bool Tache::operator < (const Tache& t) const
{
    return numeroId < t.numeroId;
}

bool Tache::operator == (const Tache& t) const
{
    return numeroId == t.numeroId;
}

bool Tache::conflit(const Tache& t)
{
    bool result = false;
    if(debut == t.debut && fin == t.fin)
    {
        result = true;
    }

    return result;
}

Inventaire& Tache::getBesoin()
{
    return deRessources;
}

int Tache::getNumero()
{
    return numeroId;
}
