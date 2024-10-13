//
// Created by Antonin on 05/10/2024.
//

#include "clist.h"

void clist_init(CList *list) {
    // Code here
}

void clist_free(CList *list, void (*free_func)(void *)) {
    // Code here
}

void clist_append(CList *list, void *data) {
    // Code here
}

int clist_remove(CList *list, const int index, void **removedData) {
    // Code here
}

int clist_removeLast(CList *list, void **removedData) {
    // Code here
}

int clist_get(const CList *list, const int index, void **returnedData) {
    // Code here
}

void clist_filter(const CList *list, int (*filterFunction)(const void *data), CList *filteredList) {
    // Code here
}

void clist_sort(const CList *list, int (*sortFunction)(const void *data1, const void *data2), CList *sortedList) {
    // Code here
}

void clist_reverse(const CList *list, CList *reversed) {
    // Code here
}

void clist_copy(const CList *list, CList *copy) {
    // Code here
}

void clist_merge(const CList *list1, const CList *list2, CList *mergedList) {
    // Code here
}

void clist_print(const CList *list, void (*printFunction)(const void *data)) {
    // Code here
}

void clist_println(const CList *list, void (*printFunction)(const void *data)) {
    // Code here
}
