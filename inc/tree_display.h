//
// Created by Antonin Jean on 03/03/2025.
//

#ifndef TREE_DISPLAY_H
#define TREE_DISPLAY_H

#define DISPLAY_LABEL_BUFFER_SIZE 128 // TAILLE MAXIMALE d'un label
#define DISPLAY_DATA_BUFFER_SIZE 128 // TAILLE MAXIMALE d'une donnée représentée au format str

/**
 * This struct contains data to handle a given tree structure.
 *
 * As the module is generic, it doesn't know the structure that will be used, thus it needs the user to help define
 * functions to handle its structure.
 *
 * For each function, the input is considered to be stored into a void* variable.
 */
typedef struct {
    /**
     * This function writes in output buffer a representation of its input's label
     * Tip: use sprintf
     *
     * The output buffer size is given by DISPLAY_LABEL_BUFFER_SIZE
     */
    void (*get_displayed_data)(void *input, char *output);

    /**
     * This function writes in output buffer a representation of its input's data
     * Tip: use sprintf
     *
     * The output buffer size is given by DISPLAY_DATA_BUFFER_SIZE
     */
    void (*get_displayed_label)(void *input, char *output);

    /**
     * This functions returns a ptr to the left child of the given input
     */
    void * (*get_left_child)(void *input);

    /**
     * This functions returns a ptr to the center child of the given input
     */
    void * (*get_center_child)(void *input);

    /**
     * This functions returns a ptr to the right child of the given input
     */
    void * (*get_right_child)(void *input);
} TreeDisplayData;

int writef_tree(const char *filename, const TreeDisplayData *tdp, void *input);

int writef_tree_content(FILE *file, const TreeDisplayData *tdp, void *node);

#endif //TREE_DISPLAY_H
