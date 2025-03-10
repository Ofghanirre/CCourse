/*
 * test_binary_tree.c
 *
 * Ce fichier teste l'affichage d'un arbre binaire avec la bibliothèque tree_display.
 * Un arbre binaire est un arbre où chaque nœud a au plus deux enfants.
 */
#include <stdio.h>
#include <stdlib.h>
#include "examples/tree_examples.h"
#include "tree_display.h"

// Structure d'un nœud d'arbre binaire
typedef struct BinaryTreeNode {
    int data;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
} BinaryTreeNode;

// Fonction pour créer un nouveau nœud
BinaryTreeNode *createBinaryNode(int data) {
    BinaryTreeNode *node = malloc(sizeof(BinaryTreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Fonction pour afficher le label d'un nœud
void display_binary_label(void *input, char *output) {
    sprintf(output, "%p", input);
}

// Fonction pour afficher le contenu data d'un nœud
void display_binary_data(void * input, char* output) {
    int data = ((BinaryTreeNode*)input)->data;
    sprintf(output, "%d", data);
}

// Fonctions pour récupérer les enfants gauche et droit
void *get_binary_left_child(void *input) {
    BinaryTreeNode *node = (BinaryTreeNode *) input;
    return node->left;
}

void *get_binary_right_child(void *input) {
    BinaryTreeNode *node = (BinaryTreeNode *) input;
    return node->right;
}

int binary_tree_test() {
    // Création de l'arbre binaire
    int values[] = {1, 2, 3, 4, 5};
    BinaryTreeNode *root = createBinaryNode(values[0]);
    root->left = createBinaryNode(values[1]);
    root->right = createBinaryNode(values[2]);
    root->left->left = createBinaryNode(values[3]);
    root->left->right = createBinaryNode(values[4]);

    // Configuration des données d'affichage
    TreeDisplayData tdp = {
        .get_displayed_data = &display_binary_data,
        .get_displayed_label = &display_binary_label,
        .get_left_child = &get_binary_left_child,
        .get_center_child = NULL,
        .get_right_child = &get_binary_right_child
    };

    // Génération du fichier DOT
    writef_tree("binary_tree.dot", &tdp, root);
    printf("Fichier DOT généré: binary_tree.dot\n");

    return 0;
}
