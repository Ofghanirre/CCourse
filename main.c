#include <stdio.h>

#include "clist.h"

typedef struct TestPacket {
    int a;
    int b;
} TestPacket;

void printPacket(const void* packet) {
    const TestPacket* p = packet;
    printf("%p => a: %d, b: %d", packet, p->a, p->b);
}

int filterEven(const void* packet) {
    return ((TestPacket*)packet)->a % 2 == 0;
}

int sortByA(const void* a, const void* b) {
    return ((TestPacket*)a)->a - ((TestPacket*)b)->a;
}

void freePacket(void* packet) {}

void packetTest() {
    CList list;
    clist_init(&list);
    TestPacket packet[]= {
        { .a = 1, .b = 2 },
        { .a = 4, .b = 5 },
        { .a = 8, .b = 9 },
        { .a = 11, .b = 12 },
    };
    for (int i = 0; i < 4; i++) {
        clist_append(&list, &packet[i]);
    }
    clist_print(&list, printPacket);

    CList filtered;
    clist_filter(&list, &filterEven, &filtered);
    clist_print(&filtered, printPacket);

    CList sorted;
    clist_sort(&list, &sortByA, &sorted);
    clist_print(&sorted, printPacket);

    CList reverse;
    clist_reverse(&sorted, &reverse);
    clist_print(&reverse, printPacket);

    CList merged;
    clist_merge(&sorted, &reverse, &merged);
    clist_print(&merged, printPacket);

    clist_free(&list, &freePacket);
    clist_free(&filtered, &freePacket);
    clist_free(&sorted, &freePacket);
    clist_free(&reverse, &freePacket);
    clist_free(&merged, &freePacket);
}

int main(void) {
    packetTest();
    return 0;
}
