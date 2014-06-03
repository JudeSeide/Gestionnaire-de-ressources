==================
LIBRAIRIES REQUIS:
==================

Le logiciel utilise les librairies standards du c++, g++ est utilise pour la compilation


=============
DESCRIPTION :
=============

Le logiciel est un gestionnaire de ressources.
Il prend en entrer un inventaire de ressources et une liste de taches a effectue accompagnes 
de leur horaire.
Le logiciel permet de detecter les cas de conflits du au manque de ressources ou a
l'indisponibilite de ces ressources.

=================
FORMAT D'ENTRER :
=================

Le fichier d'entrer est un fichier de texte simple sans extension particuliere ou simple .txt
Il suit le format suivant :

d'abord l'inventaire des ressources suivi de l'id d'une tache, de son horaire et ses ressources
il est important de respecter le format. des fichiers .txt sont mis en exemple dans le projet

* Camionnette : 4
* Perceuse : 8
* Pelle : 12
* Marteau_piqueur : 5
* Chef_equipe : 4
* Creuseur : 3
* Deneigeuse : 5
* Cones_Oranges : 100
-
1001
0 600
* Camionnette : 1
* Chef_equipe : 1
* Creuseur : 2
* Marteau_piqueur : 2
* Pelle : 3
* Cones_Oranges : 12
-
1002
300 900
* Camionnette : 2
* Chef_equipe : 2
-
1004
300 900
* Camionnette : 1
* Chef_equipe : 1
* Pelle : 5
-
1005
600 1200
* Camionnette : 1
* Chef_equipe : 1
* Pelle : 10
-

==============
INSTALLATION :
==============

Taper _make_ pour builder le projet dans un terminal
Taper _./gestionnaire < nomFichier.txt_ pour l'execution
Taper _make clean_ pour nettoyer
