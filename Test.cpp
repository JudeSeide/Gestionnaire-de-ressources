/*
  INF3105 - Structures de données et algorithmes
  Session Hiver 2012.

  TP2 - Partie A
*/

#include "inventaire_a.h"
#include "cedule_a.h"

void test1();
void test2();

int main(){
  test1();
  test2();
  //Complétez avec les autres tests que vous jugez requis.
}

// Si vous avez implémenté une ListeAssociative (voir Lab4).
void test1(){
  ListeAssociative<int, std::string> l;
  l[5] = "cinq";
  l[3] = "trois";
  l[4] = "quatre";
  l[6] = "six";
  l[1] = "un";
  ListeAssociative<int, std::string>::Iterateur i(l);
  while(i){
    std::cout << i.cle() << " = " << i.valeur() << std::endl;
    ++i;
  }
}

void test2(){
  Inventaire i1;
  std::cin >> i1;

  Inventaire i2;
  std::cin >> i2;

  Inventaire i3 = i1 + i2;
  std::cout << "i1+i2:\n" << i3;
  std::cout << "i2+i1:\n" << (i1+i2);

  std::cout << "i1-i2:\n" << (i1-i2);
  std::cout << "i1-i2:\n" << (i2-i1);
}

