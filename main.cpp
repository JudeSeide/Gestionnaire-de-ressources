#include <iostream>
#include <cstdlib>
#include <fstream>
#include "Liste.h"
#include "Ressource.h"
#include "Inventaire.h"
#include "Tache.h"
#include "Cedule.h"
#include "Iterateur.h"

using namespace std;

void test1(){
  std::cout << "Test1()\n";
  Liste<int> liste1;
  std::cout << "FIN Test1()\n";  
}

void test2(){
  std::cout << "Test2()\n";
  Liste<int> liste1;
  liste1.insererElement(4);
  std::cout << "FIN Test2()\n";  
}

void test3(){
  std::cout << "Test3()\n";
  Liste<int> liste1;
  liste1.insererElement(4);
  liste1.insererElement(2);
  liste1.insererElement(5);
  liste1.insererElement(1);
  liste1.insererElement(3);
  liste1.insererElement(8);
  std::cout << "FIN Test3()\n";  
}

void test4(){
  std::cout << "Test4()\n";
  Liste<int> liste1;
  liste1.insererElement(4);
  liste1.insererElement(2);
  liste1.insererElement(5);
  liste1.insererElement(1);
  liste1.insererElement(3);
  liste1.insererElement(8);
  
  Liste<int> liste2;
  liste2 = liste1;
  Liste<int> liste3;
  liste2 = liste3;
  std::cout << "FIN Test4()\n";  
}

void test5(){
  std::cout << "Test5()\n";
  Liste<int> liste1;
  liste1.insererElement(4);
  liste1.insererElement(2);
  liste1.insererElement(5);
  liste1.insererElement(1);
  liste1.insererElement(3);
  liste1.insererElement(8);
  
  Liste<int> liste2(liste1);
  Liste<int> liste3;
  liste2 = liste3;
  std::cout << "FIN Test5()\n";  
}

void test6(){
  std::cout << "Test6()\n";
  Liste<int> listeint;
//  listeint.insererElement(4);
//  listeint.insererElement(2);
  
  Liste<Liste<int > > listedeliste;
  std::cout << " 1 Test6()\n";
  listedeliste.viderListe();
  std::cout << " 2 Test6()\n";
  
  listedeliste.insererElement(listeint);
  std::cout << " 3 Test6()\n";
  
  listedeliste.viderListe();
  std::cout << " 4 Test6()\n";
  
  std::cout << "FIN Test6()\n";  
}



int main(int argc, char **argv)
{
   int* a = new int();
   delete[] a;
   
/*   test1();
   test2();
   test3();
   test4();
   */
//   test5();
   test6();
   
   /* //string fichierEntree;

    if(argc != 2)
    {
        cerr << "Erreur : Nombres d'arguments incorrects!" << endl;
        exit(-1);
    }


    Inventaire inventaire_initial();
    Inventaire inventaire_tache();

    std::cin >> inventaire_initial;
    Cedule cedule(inventaire_initial);
  while(std::cin){
    Tache tache(0,0,0,inventaire_tache);
    cin >> tache;
    Cedule ceduletest = cedule;
    ceduletest.ajouter(tache);
    if(ceduletest.sansRupture()){
      std::cout << "OK : " << tache.getNumero() << std::endl;
      cedule = ceduletest;
    }else{
      cout << "Erreur : "<< tache.getNumero() << endl;
      Liste<int> conflits ;
     conflits = ceduletest.getConflitsNumerosTaches();
      conflits.afficherListe();
    }
  }
  return 0;
 if(argc != 2)
   {
       cerr << "Erreur : Nombres d'arguments incorrects!" << endl;
       exit(-1);
   }
   //string fichier = argv[1];
   */

   //ifstream flux("test.txt");
   /*
  std::cout << "Allo\n";
  ifstream flux("test.txt");

  std::cout << "Allo\n";
  
  Inventaire inventaire_initial;
  std::cout << "Allo\n";
  flux >> inventaire_initial;
  std::cout << "Allo\n";
  Cedule cedule(inventaire_initial);
  std::cout << "Allo\n";
  do{
    std::cout << "Allo Do 1\n";
    Tache tache;
    std::cout << "Allo Do 2\n";
    flux >> tache;
    std::cout << "Allo Do 3\n";
    Cedule ceduletest = cedule;
    std::cout << "Allo Do 4\n";
    ceduletest.ajouter(tache);
    std::cout << "Allo Do 5\n";
    if(ceduletest.sansRupture()){
      std::cout << "OK : " << tache.getNumero() << std::endl;
      cedule = ceduletest;
    }else{
      std::cout << "Erreur : "<< tache.getNumero() << std::endl;
     Liste<int> conflits;
    conflits = cedule.getConflitsNumerosTaches();
      //conflits.afficherArbre();
      Iterateur<int> iter(conflits);
      for(iter = conflits.debut();iter;iter++)
      {
          cout << "Conflit : "<< *iter << endl;
      }

    }
  }while(flux);
*/
  return 0;
}
