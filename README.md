# C Courses repository

Ce projet vise à implémenter une pseudo correction d'un exercice de Perfectionnement à la programmation en C, matière de 
L2 de la licence Maths Info de l'université Gustave Eiffel.

L'intérêt n'est pas d'avoir une correction de l'exercice mais plus de:
- fournir un exemple de modularisation simple pour répondre à un besoin
- présenter un makefile générique fonctionnant pour le projet
- proposer un algorithme non bloquant de mesure du temps
  > pas de while(true) bloquant l'execution tant que l'utilisateur n'a pas saisis d'input.
  > Cela peut être utile si votre programme doit faire des tâches en fond.

Le programme n'est pas parfait:
- il manque la gestion des tours
- la gestion du temps peut être biaisée si l'utilisateur spam la touche de pause.
    > Chaque action a un délai d'une milliseconde pour être detectée, et donc l'action de spam la pause / reprise laisse 
  > une petite marge d'erreur pouvant "ralentir" la mesure du temps. 
  > Cela peut être corrigé et peut être un bon exercice pour les étudiants souhaitant s'essayer à de la reprise de code.

## Utilisation
Le programme explique assez explicitement comment l'utiliser.

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
$ ./CChrono
```
### Contribution

Les contributions sont les bienvenues ! Vous pouvez proposer des améliorations ou de nouveaux types d'arbres.

Si vous avez des questions ou des problèmes, n'hésitez pas à ouvrir une issue ou à proposer une pull request.
