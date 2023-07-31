

# Unstandart

Ce projet est un test pour voire si je peux r�cr�er une biblioth�que standard en C++ uniquement � l'aide des biblioth�que standard du C. A cela s'ajoute un fichier "test/test.cpp" avec des test unitaire et un fichier "assertion.hpp". 
Ce projet se portant bien jusqu'� pr�sent a aussi pour but d'�tre **l�ger, rapide � compiler et rapide � ex�cuter.** Par ailleurs il est d�velopp� sur Windows 10, cependant il est cens� pouvoir compiler sur Linux/MacOs.

## Pourquoi faire?
J'ai cr�er ce projet initialement pour pouvoir ensuite l'utiliser comme substitue � la STL qui prend un temps fou � compiler sur des ordinateur avec un mauvais processeur.

## Comment c'est fait?
Il y a un fichier par classes. On essaie d'inclure le moins de fichier possible pour permettre l'utilisation des fichier ind�pendamment des autres. 
Toutes les classes du projet sont contenue dans le namespace "ustd".
Les fichiers dans le dossier "test/" sont des tests et n'ont pas besoin d'�tre inclut.
On essaie aussi de minimiser l'utilisation de l'h�ritage et des templates pour permettre une compilation plus rapide.
## Avancement du projet
Actuellement il y a 3 fichier majeurs:
* exception.hpp - Contient toutes les exceptions qui peuvent survenir � l'ex�cution
* memory.hpp - Contient une classe de pointeur int�lligent pour �viter les fuite de m�moire. **INSTABLE**
* string.hpp - Contient une classe pour pouvoir manipuler les chaines de caract�res sans danger.
* array.hpp - Contient une classe qui permet d'avoir une liste statique d'�l�ment.

A l'avenir je pr�vois d'ajouter:
* vector.hpp - une classe template pour pouvoir faire des liste dynamique s�curiser.
* out - une classe pour pouvoir utiliser plus simplement la sortie standard (dans le m�me style que std::ostream)