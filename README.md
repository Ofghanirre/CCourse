# Introduction

Ce module permet la visualisation d'arbre générique de type unaire, binaire ou ternaire via la génération de fichiers
au format dot. Le module `tree_display` est responsable entièrement de l'affichage, et le projet proposent différents 
exemples présents dans le dossier `examples`.

> Si vous souhaitez utiliser le module, il vous suffit de copier le module `tree_display`

Ce projet peut être utiliser pour visualiser des arbres facilement, pour découvrir une approche de la programmation générique, et pour découvrir un exemple de makefile avec règles génériques et variables automatiques.
Il peut servir d'inspiration mais il est vivement conseillé que les étudiant s'essayent à recoder par eux memes les fonctions.

# Utilisation:

## Mode d'emplois:

Le module ne conait pas à l'avance quel type de structure va être utilisé pour représenter un arbre, il est donc de la 
responsabilité de l'utilisateur de renseigner le module sur l'utilisation de son module.

Pour cela la structure `TreeDisplayData` est à remplir. Vous pouvez retrouver une documentation dans 
[tree_display.h](inc/tree_display.h) et retrouver des exemples fournis dans le projet.

## Exemples:
Les différents exemples proposées sont les suivants:

| nom du test                   | nom du fichier output     |
|-------------------------------|---------------------------|
| unary_tree_example            | unary_tree.dot            | 
| binary_tree_example           | binary_tree.dot           | 
| ternary_tree_example          | ternary_tree.dot          | 
| binary_tree_only_data_example | binary_tree_only_data.dot | 

Chaque test se présente comme tel:
- il définit une structure représentant un arbre
- il définit des fonctions permettant au module d'utiliser la structure
- il renseigne ces fonctions à une structure `TreeDisplayData`
- il appelle la fonction `writef_tree`


## Compilation
*Ce projet fournis un [Makefile](./Makefile) détaillé, pouvant être analysé et recopié pour les étudiants afin
de comprendre l'utilisation d'un makefile générique.*


Le projet peut être compilé via deux méthodes:
- CMAKE: (requis l'installation de CMAKE)
  - placez vous dans le dossier cmake-build-debug
    > ```sh
    > $ cd cmake-build-debug
    > ```
  - compiler avec cmake:
    > ```sh
    > $ cmake ..
    > ```
- Makefile
    > ```sh
    > $ make clean & make
    > ```

## Exécution
```sh
$ ./C_DOT_TREE_VISUALIZER
```
### Contribution

Les contributions sont les bienvenues ! Vous pouvez proposer des améliorations ou de nouveaux types d'arbres.

Si vous avez des questions ou des problèmes, n'hésitez pas à ouvrir une issue ou à proposer une pull request.

