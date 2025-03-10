//
// Created by Antonin Jean on 03/03/2025.
//

#ifndef TREE_DISPLAY_H
#define TREE_DISPLAY_H

#define DISPLAY_LABEL_BUFFER_SIZE 128
#define DISPLAY_DATA_BUFFER_SIZE 128
typedef struct {
    void (*get_displayed_data)(void *input, char *output);

    void (*get_displayed_label)(void *input, char *output);

    void * (*get_left_child)(void *input);

    void * (*get_center_child)(void *input);

    void * (*get_right_child)(void *input);
} TreeDisplayData;

int writef_tree(const char *filename, const TreeDisplayData *tdp, void *input);

int writef_tree_content(FILE *file, const TreeDisplayData *tdp, void *node);

#endif //TREE_DISPLAY_H
