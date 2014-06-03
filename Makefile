# Makefile du projet gestionnaire de ressources
#

OPTIONS = -Wall
# Choisir l'une des deux configuration (-g: Debug | -O3: Release)
#OPTIONS = -g -O0 -Wall
OPTIONS = -O3 -Wall


#Cibles construites sur l'appel de make
all : gestionnaire

#Modele de fichier Makefile
#
#<cible>: <dependances>
#<tabulation><Commandes>
#
# Attention : les dépendances ne sont pas automatique. Vous devez ajouter les .h manuellement.
#

gestionnaire: main.cc inventaire.o cedule.o tache.o ressource.o periode.o
	g++ $(OPTIONS) -o gestionnaire main.cc inventaire.o cedule.o tache.o ressource.o periode.o

inventaire.o: inventaire.cc inventaire.h ressource.h
	g++ -c $(OPTIONS) inventaire.cc

cedule.o: cedule.cc cedule.h liste.h listeassociative.h tache.h
	g++ -c $(OPTIONS) cedule.cc
	
tache.o: tache.cc tache.h inventaire.h periode.h
	g++ -c $(OPTIONS) tache.cc
        
ressource.o: ressource.cc ressource.h liste.h
	g++ -c $(OPTIONS) ressource.cc

periode.o: periode.cc periode.h
	g++ -c $(OPTIONS) periode.cc    

clean :
	rm -f *.o
	rm -f gestionnaire
	rm -f *~


