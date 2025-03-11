# Utilisation de tree_display

Ce module permet la visualisation d'arbre générique de type unaire, binaire ou ternaire via la génération de fichiers
au format dot. Le module `tree_display` est responsable entièrement de l'affichage, et le projet proposent différents 
exemples présents dans le dossier `examples`.

> Si vous souhaitez utiliser le module, il vous suffit de copier le module `tree_display`

### Mode d'emplois:

Le module ne conait pas à l'avance quel type de structure va être utilisé pour représenter un arbre, il est donc de la 
responsabilité de l'utilisateur de renseigner le module sur l'utilisation de son module.

Pour cela la structure `TreeDisplayData` est à remplir. Vous pouvez retrouver une documentation dans `tree_display.h` et
retrouver des exemples fournis dans le projet.

Les différents exemples proposées sont les suivants:

| nom du test                | nom du fichier output     |
|----------------------------|---------------------------|
| unary_tree                 | unary_tree.dot            | 
| binary_tree                | binary_tree.dot           | 
| ternary_tree               | ternary_tree.dot          | 
| binary_tree_with_only_data | binary_tree_only_data.dot | 

Chaque test se présente comme tel:
- il définit une structure représentant un arbre
- il définit des fonctions permettant au module d'utiliser la structure
- il renseigne ces fonctions à une structure `TreeDisplayData`
- il appel la fonction de display

## Compilation

Le projet peut être compilé via deux méthodes:
- CMAKE:
  - placez vous dans le dossier cmake-build-debug
    > `$ cd cmake-build-debug`
  - 
- Makefile

## Exécution

L'exécution d'un test génère un fichier .dot, utilisable avec Graphviz :

./test_unary_tree
./test_binary_tree_int
./test_ternary_tree

Vous pouvez ensuite générer un fichier image :

dot -Tpng unary_tree.dot -o unary_tree.png
dot -Tpng binary_tree_int.dot -o binary_tree_int.png
dot -Tpng ternary_tree.dot -o ternary_tree.png

### Explication des exemples

1. test_unary_tree.c

Affiche un arbre unaire où chaque nœud possède un unique enfant.

2. test_binary_tree_int.c

Affiche un arbre binaire contenant des entiers, en affichant uniquement la donnée sans label.

3. test_ternary_tree.c

Affiche un arbre ternaire, où chaque nœud peut avoir jusqu'à trois enfants.

Ces exemples montrent comment utiliser tree_display pour différentes structures d'arbres et comment configurer les fonctions d'affichage et de récupération des enfants.

### Contribution

Les contributions sont les bienvenues ! Vous pouvez proposer des améliorations ou de nouveaux types d'arbres.

Si vous avez des questions ou des problèmes, n'hésitez pas à ouvrir une issue ou à proposer une pull request.

