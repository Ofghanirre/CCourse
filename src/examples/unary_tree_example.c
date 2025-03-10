/*
 * test_unary_tree.c
 *
 * Ce fichier teste l'affichage d'un arbre unaire avec la bibliothèque tree_display.
 * Un arbre unaire est un arbre où chaque nœud n'a qu'un seul enfant.
 */
#include <stdio.h>
#include <stdlib.h>
#include "examples/tree_examples.h"
#include "tree_display.h"

// Structure d'un nœud d'arbre unaire
typedef struct UnaryTreeNode {
    int data;
    struct UnaryTreeNode *child;
} UnaryTreeNode;

// Fonction pour créer un nouveau nœud
UnaryTreeNode *createUnaryNode(int data) {
    UnaryTreeNode *node = malloc(sizeof(UnaryTreeNode));
    node->data = data;
    node->child = NULL;
    return node;
}

// Fonction pour afficher le label d'un nœud
void display_unary_label(void *input, char *output) {
    sprintf(output, "%p", input);
}

// Fonction pour afficher le contenu data d'un nœud
void display_unary_data(void * input, char* output) {
    int data = ((UnaryTreeNode*)input)->data;
    sprintf(output, "%d", data);
}

// Fonction pour récupérer l'enfant d'un nœud
void *get_unary_child(void *input) {
    UnaryTreeNode *node = (UnaryTreeNode *) input;
    return node->child;
}

int unary_tree_test() {
    // Création de l'arbre unaire
    int values[] = {1, 2, 3};
    UnaryTreeNode *root = createUnaryNode(values[0]);
    root->child = createUnaryNode(values[1]);
    root->child->child = createUnaryNode(values[2]);

    // Configuration des données d'affichage
    TreeDisplayData tdp = {
        .get_displayed_data = &display_unary_data,
        .get_displayed_label = &display_unary_label,
        .get_left_child = &get_unary_child,
        .get_center_child = NULL,
        .get_right_child = NULL
    };

    // Génération du fichier DOT
    writef_tree("unary_tree.dot", &tdp, root);
    printf("Fichier DOT généré: unary_tree.dot\n");

    return 0;
}