#include <stdio.h>
#include <tree_display.h>

int writef_tree_child_handler(FILE *file, const TreeDisplayData *tdp, void *node,
                              void *(*get_child)(void *), const char *port_name) {
    void *child = NULL;
    if (get_child != NULL) {
        child = get_child(node);
        if (child) {
            fprintf(file, "  node%p:%s -> node%p;\n", node, port_name, child);
            return writef_tree_content(file, tdp, child);
        }
    }
    return 0;
}

int try_write_displayed_label(FILE* file, const TreeDisplayData *tdp, void *node) {
    if (NULL == tdp->get_displayed_label) {
        return 1;
    }
    char buffer[DISPLAY_LABEL_BUFFER_SIZE];
    tdp->get_displayed_label(node, buffer);

    fprintf(file, " %s |", buffer);
    return 0;
}

int try_write_displayed_data(FILE* file, const TreeDisplayData *tdp, void *node) {
    if (NULL == tdp->get_displayed_data) {
        return 1;
    }

    char buffer[DISPLAY_DATA_BUFFER_SIZE];
    tdp->get_displayed_data(node, buffer);
    fprintf(file, " %s |", buffer);
    return 0;
}


int try_write_left_child(FILE *file, const TreeDisplayData *tdp) {
    if (NULL == tdp->get_left_child) {
        return 1;
    }
    fprintf(file, "<left> G");
    return 0;
}

int try_write_middle_child(FILE *file, const TreeDisplayData *tdp) {
    if (NULL == tdp->get_center_child) {
        return 1;
    }
    fprintf(file, "<middle> M");
    return 0;
}

int try_write_right_child(FILE *file, const TreeDisplayData *tdp) {
    if (NULL == tdp->get_right_child) {
        return 1;
    }
    fprintf(file, "<right> D");
    return 0;
}

void writef_tree_children(FILE *file, const TreeDisplayData *tdp) {
    fprintf(file, "{");
    try_write_left_child(file, tdp);
    if (tdp->get_center_child) fprintf(file, " | ");
    try_write_middle_child(file, tdp);
    if (tdp->get_right_child) fprintf(file, " | ");
    try_write_right_child(file, tdp);
    fprintf(file, "}");
}

int writef_tree_content(FILE *file, const TreeDisplayData *tdp, void *node) {
    if (file == NULL) return -1;
    if (node == NULL) return 0;
    fprintf(file, "  node%p [label=\"{", node);
    try_write_displayed_label(file, tdp, node);
    try_write_displayed_data(file, tdp, node);

    writef_tree_children(file, tdp);
    fprintf(file, "}\", shape=record];\n");

    return writef_tree_child_handler(file, tdp, node, tdp->get_left_child, "left") +
           writef_tree_child_handler(file, tdp, node, tdp->get_center_child, "middle") +
           writef_tree_child_handler(file, tdp, node, tdp->get_right_child, "right");
}

int writef_tree(const char *filename, const TreeDisplayData *tdp, void *input) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }
    fprintf(file, "digraph Tree {\n  node [fontname=\"Arial\"];\n"
        "  node [ shape = record , height = .1 ]\n"
        "  edge [ tailclip = false , arrowtail = dot , dir = both ];\n\n\n");
    writef_tree_content(file, tdp, input);
    fprintf(file, "}\n");
    fclose(file);
    return 0;
}
