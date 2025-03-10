/*
 * test_ternary_tree.c
 *
 * Ce fichier teste l'affichage d'un arbre ternaire avec la bibliothèque tree_display.
 * Un arbre binaire est un arbre où chaque nœud a au plus deux enfants.
 */
#include <stdio.h>
#include <stdlib.h>
#include "examples/tree_examples.h"
#include "tree_display.h"

// Structure d'un nœud d'arbre binaire
typedef struct TernaryTreeNode {
    int data;
    struct TernaryTreeNode *left;
    struct TernaryTreeNode *middle;
    struct TernaryTreeNode *right;
} TernaryTreeNode;

// Fonction pour créer un nouveau nœud
TernaryTreeNode *createTernaryNode(int data) {
    TernaryTreeNode *node = malloc(sizeof(TernaryTreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Fonction pour afficher le label d'un nœud
void display_ternary_label(void *input, char *output) {
    sprintf(output, "%p", input);
}

// Fonction pour afficher le contenu data d'un nœud
void display_ternary_data(void * input, char* output) {
    int data = ((TernaryTreeNode*)input)->data;
    sprintf(output, "%d", data);
}

// Fonctions pour récupérer les enfants gauche milieu et droit
void *get_ternary_left_child(void *input) {
    TernaryTreeNode *node = (TernaryTreeNode *) input;
    return node->left;
}

void *get_ternary_middle_child(void *input) {
    TernaryTreeNode *node = (TernaryTreeNode *) input;
    return node->middle;
}

void *get_ternary_right_child(void *input) {
    TernaryTreeNode *node = (TernaryTreeNode *) input;
    return node->right;
}

int ternary_tree_test() {
    // Création de l'arbre binaire
    int values[] = {1, 2, 3, 4, 5, 6};
    TernaryTreeNode *root = createTernaryNode(values[0]);
    root->left = createTernaryNode(values[1]);
    root->right = createTernaryNode(values[2]);
    root->left->left = createTernaryNode(values[3]);
    root->left->middle = createTernaryNode(values[4]);
    root->left->right = createTernaryNode(values[5]);

    // Configuration des données d'affichage
    TreeDisplayData tdp = {
        .get_displayed_data = &display_ternary_data,
        .get_displayed_label = &display_ternary_label,
        .get_left_child = &get_ternary_left_child,
        .get_center_child = &get_ternary_middle_child,
        .get_right_child = &get_ternary_right_child
    };

    // Génération du fichier DOT
    writef_tree("ternary_tree.dot", &tdp, root);
    printf("Fichier DOT généré: ternary_tree.dot\n");

    return 0;
}
