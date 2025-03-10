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
typedef struct BinaryTreeNode2 {
    int data;
    struct BinaryTreeNode2 *left;
    struct BinaryTreeNode2 *right;
} BinaryTreeNode2;

// Fonction pour créer un nouveau nœud
BinaryTreeNode2 *createBinaryNode2(int data) {
    BinaryTreeNode2 *node = malloc(sizeof(BinaryTreeNode2));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Fonction pour afficher le contenu data d'un nœud
void display_binary_data2(void * input, char* output) {
    int data = ((BinaryTreeNode2*)input)->data;
    sprintf(output, "%d", data);
}

// Fonctions pour récupérer les enfants gauche et droit
void *get_binary_left_child2(void *input) {
    BinaryTreeNode2 *node = (BinaryTreeNode2 *) input;
    return node->left;
}

void *get_binary_right_child2(void *input) {
    BinaryTreeNode2 *node = (BinaryTreeNode2 *) input;
    return node->right;
}

int binary_test_only_data() {
    // Création de l'arbre binaire
    int values[] = {1, 2, 3, 4, 5};
    BinaryTreeNode2 *root = createBinaryNode2(values[0]);
    root->left = createBinaryNode2(values[1]);
    root->right = createBinaryNode2(values[2]);
    root->left->left = createBinaryNode2(values[3]);
    root->left->right = createBinaryNode2(values[4]);

    // Configuration des données d'affichage
    TreeDisplayData tdp = {
        .get_displayed_data = &display_binary_data2,
        .get_displayed_label = NULL, // On ne veut pas afficher le nom; uniquement les données
        .get_left_child = &get_binary_left_child2,
        .get_center_child = NULL,
        .get_right_child = &get_binary_right_child2
    };

    // Génération du fichier DOT
    writef_tree("binary_tree_only_data.dot", &tdp, root);
    printf("Fichier DOT généré: binary_tree_only_data.dot\n");

    return 0;
}
