//
// Created by Antonin on 05/10/2024.
//

#include "clist.h"
#include <stdio.h>
#include <stdlib.h>

void clist_init(CList * list) {
    CList result = {
        .head = NULL,
        .tail = NULL,
        .size = 0
    };
    *list = result;
}

void clist_free(CList * list, void (*free_func)(void *)) {
    if (list == NULL) return;
    CNode * node = list->head;
    while (node != NULL) {
        CNode * next = node->next;
        if (free_func != NULL) {
            free_func(node->data);
        }
        free(node);
        node = next;
    }
}

void clist_append(CList * list, void * data) {
    if (list == NULL) return;
    CNode * node = (CNode *) malloc(sizeof(CNode));
    if (node == NULL) exit(EXIT_FAILURE);
    node->data = data;
    node->next = NULL;
    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        CNode * last = list->tail;
        last->next = node;
        list->tail = node;
    }
    list->size = list->size + 1;
}

int clist_remove(CList * list, const unsigned int index, void ** removedData) {
    if (list == NULL) return -1;
    if (index >= list->size) return 1;
    CNode * node = list->head;
    if (index == 0) {
        list->head = node->next;
        if (list->head == NULL) list->tail = NULL;
        list->size--;
        *removedData = node->data;
        free(node);
        return 0;
    }

    for (int i = 0; i < index - 1; i++) {
        node = node->next;
    }

    CNode * target = node->next;
    if (target->next == NULL) {
        node->next = NULL;
        list->tail = node;
    } else {
        node->next = target->next;
    }
    *removedData = target->data;
    free(target);
    list->size--;
    return 0;
}

int clist_removeLast(CList * list, void ** removedData) {
    return clist_remove(list, list->size-1, removedData);
}


int clist_get(const CList * list, const unsigned int index, void ** returnedData) {
    if (list == NULL) return -1;
    if (index >= list->size) return 1;

    CNode * node = list->head;
    for (int i = 0; i < index; i++) {
        node = node->next;
    }
    *returnedData = node->data;
    return 0;
}

void clist_filter(const CList * list, int (*filterFunction)(const void * data), CList * filteredList) {
    if (list == NULL) return;
    clist_init(filteredList);
    CNode * node = list->head;
    while (node != NULL) {
        if (filterFunction(node->data)) {
            clist_append(filteredList, node->data);
        }
        node = node->next;
    }
}

void clist_sort(const CList * list, int (*sortFunction)(const void * data1, const void * data2), CList * sortedList) {
    if (list == NULL) return;
    void ** data = malloc(list->size*sizeof(void *));
    CNode * node = list->head;
    for (int i = 0; i < list->size; i++) {
        data[i] = node->data;
        node = node->next;
    }

    qsort(data, list->size, sizeof(void *), sortFunction);

    clist_init(sortedList);
    for (int i = 0; i < list->size; i++) {
        clist_append(sortedList, data[i]);
    }
    free(data);
}

void clist_reverse(const CList * list, CList * reversed) {
    if (list == NULL) return;
    clist_init(reversed);
    for (int i = list->size - 1; i >= 0; i--) {
        void *data;
        clist_get(list, i, &data);
        clist_append(reversed, data);
    }
}

void clist_copy(const CList * list, CList * copy) {
    if (list == NULL) return;
    clist_init(copy);
    CNode * node = list->head;
    while (node != NULL) {
        clist_append(copy, node->data);
        node = node->next;
    }
}

void clist_merge(const CList * list1, const CList * list2, CList * mergedList) {
    if (list1 == NULL || list2 == NULL) return;
    clist_copy(list1, mergedList);
    CNode * node = list2->head;
    while (node != NULL) {
        clist_append(mergedList, node->data);
        node = node->next;
    }
}


void clist_print(const CList * list, void (*printFunction)(const void * data)) {
    if (list == NULL) return;
    printf("CList size: %d\nContent: [", list->size);
    CNode * node = list->head;
    while (node != NULL) {
        printf("\n'> %p | Packet{", (void*) node);
        printFunction(node->data);
        printf("}");
        node = node->next;
    }
    printf("]\n");
}

void clist_println(const CList * list, void (*printFunction)(const void * data)) {
    clist_print(list, printFunction);
    printf("\n");
}