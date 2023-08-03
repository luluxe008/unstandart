


# Unstandart

Ce projet est un test pour voire si je peux récréer une bibliothèque standard en C++ uniquement à l'aide des bibliothèque standard du C. A cela s'ajoute un fichier "test/test.cpp" avec des test unitaire et un fichier "assertion.hpp". 
Ce projet se portant bien jusqu'à présent a aussi pour but d'être **léger, rapide à compiler et rapide à exécuter.** Par ailleurs il est développé sur Windows 10, cependant il est censé pouvoir compiler sur Linux/MacOs.

## Pourquoi faire?
J'ai créer ce projet initialement pour pouvoir ensuite l'utiliser comme substitue à la STL qui prend un temps fou à compiler sur des ordinateur avec un mauvais processeur.

## Comment c'est fait?
Il y a un fichier par classes. On essaie d'inclure le moins de fichier possible pour permettre l'utilisation des fichier indépendamment des autres. 
Toutes les classes du projet sont contenue dans le namespace "ustd".
Les fichiers dans le dossier "test/" sont des tests et n'ont pas besoin d'être inclut.
On essaie aussi de minimiser l'utilisation de l'héritage et des templates pour permettre une compilation plus rapide.
## Avancement du projet
Actuellement il y a 5 fichier majeurs:
* exception.hpp - Contient toutes les exceptions qui peuvent survenir à l'exécution
* memory.hpp - Contient une classe de pointeur intélligent pour éviter les fuite de mémoire. **INSTABLE**
* string.hpp - Contient une classe pour pouvoir manipuler les chaines de caractères sans danger.
* array.hpp - Contient une classe qui permet d'avoir une liste statique d'élément.
* vector.hpp - Contient une classe qui permet d'avoir une liste dynamique d'élément.
* ostream.hpp - Contient une class Ostream qui permet d'écrire dans la sortie standart ou dans un fichier (non testé mais théoriquement possible)
* string_cout - Contient une fonction qui permet d'écrire les string avec Ostream.
* 
A l'avenir je prévois d'ajouter:
* Istream- pour pouvoir lire l'entré standart ou les fichiers
* LinkedList/DoubleLinked/Stack/... - plein de conteneurs divers et varié. 