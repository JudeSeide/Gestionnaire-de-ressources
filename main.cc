#include "inventaire.h"
#include "cedule.h"

int main(int argc, const char** args) {
    Inventaire i;
    std::cin >> i >> std::ws;
    Cedule cedule(i);

    while (std::cin) {
        Tache t;
        std::cin >> t;
        if (!std::cin) {
            break;
        }

        Cedule copie = cedule;
        copie.ajouter(t);
        if (copie.sansRupture()) {
            cedule = copie;
            std::cout << "OK : " << t.getNumero() << std::endl;
        } else {
            std::cout << "Erreur : " << t.getNumero() << std::endl;
        }
    }
    return 0;
}

