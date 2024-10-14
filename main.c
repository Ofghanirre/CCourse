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


int main(void) {
    /**
     * FIRST TEST
     */
    CList list;
    clist_init(&list);

    clist_println(&list, printPacket);

    /**
     * SECOND TEST
     */
    TestPacket packet[]= {
        { .a = 1, .b = 2 },
        { .a = 4, .b = 5 },
        { .a = 8, .b = 9 },
        { .a = 11, .b = 12 },
    };
    for (int i = 0; i < 4; i++) {
        clist_append(&list, &packet[i]);
    }
    clist_println(&list, printPacket);

    /**
     * THIRD TEST
     */
    TestPacket packetToBeRemoved = {.a = 42, .b = 42 };
    clist_append(&list, &packetToBeRemoved);
    clist_println(&list, printPacket);
    TestPacket * removedPacket;
    clist_removeLast(&list, (void**) &removedPacket);
    printf("Expected packet to be removed : %p\nRemoved packet : %p\n", &packetToBeRemoved, removedPacket);

    /**
     * FOURTH TEST
     */
    CList filtered;
    clist_filter(&list, &filterEven, &filtered);
    clist_print(&filtered, printPacket);

    /**
     * FIFTH TEST
     */
    CList sorted;
    clist_sort(&list, &sortByA, &sorted);
    clist_print(&sorted, printPacket);

    /**
     * SIXTH TEST
     */
    CList reverse;
    clist_reverse(&sorted, &reverse);
    clist_print(&reverse, printPacket);

    /**
     * SEVENTH TEST
     */
    CList merged;
    clist_merge(&sorted, &reverse, &merged);
    clist_print(&merged, printPacket);


    clist_free(&list, &freePacket);
    // TEST 4
    clist_free(&filtered, &freePacket);
    // TEST 5
    clist_free(&sorted, &freePacket);
    // TEST 6
    clist_free(&reverse, &freePacket);
    // TEST 7
    clist_free(&merged, &freePacket);

    return 0;
}
