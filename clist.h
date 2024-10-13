//
// Created by Antonin on 05/10/2024.
//

#ifndef CLIST_H
#define CLIST_H

/**
 * Represents an element of a CList, it is linking to the next element and contains data as a ptr.
*/
typedef struct CNode {
    void * data;
    struct CNode * next;
} CNode;

/**
 * Represents a Generic custom List, it contains a reference to its first and last elements.
 * The size of the list is portrayed by its `size` attribute.
 */
typedef struct CList {
    CNode * head;
    CNode * tail;
    unsigned int size;
} CList;

/**
 * Initializes a new empty CList and put it onto the given ptr.
 * @param list
 */
void clist_init(CList * list);

/**
 * Frees a given CList and free every data contained within using the free_func parameter.
 *
 * @param list
 * @param free_func a function used to free each and every element of the list
 */
void clist_free(CList * list, void (*free_func)(void *));

/**
 * Adds an element to the end of the list.
 *
 * @param list
 * @param data
 */
void clist_append(CList * list, void * data);

/**
 * Removes an element at the given index and puts its data onto removedData.
 *
 * @param list
 * @param index
 * @param removedData The removed element.
 * @return -1 if list is NULL, 1 if index is incorrect, else 0
 */
int clist_remove(CList * list, unsigned int index, void ** removedData);

/**
 * Removes the last element of the list and puts its data onto removedData.
 *
 * @param list
 * @param removedData The removed element.
 * @return -1 if list is NULL, else 0
 */
int clist_removeLast(CList * list, void ** removedData);

/**
 * Gets the content at the given index, by putting it onto returnedData.
 *
 * @param list
 * @param index
 * @param returnedData The expected result.
 * @return -1 if list is NULL, 1 if index is incorrect, else 0
 */
int clist_get(const CList * list, unsigned int index, void ** returnedData);

/**
 * Constructs a new CList containing all the elements from list that matched the given filterFunction.
 * The new list is then put into filteredList.
 *
 * @param list
 * @param filterFunction A predicate function, returns 1 if the element should be kept and 0 otherwise.
 * @param filteredList The expected result.
 */
void clist_filter(const CList * list, int (*filterFunction)(const void * data), CList * filteredList);

/**
 * Constructs a new CList containing all the elements of list sorted with the given sortFunction.
 * The new list is then put into sortedList.
 *
 * @param list
 * @param sortFunction A qsort comparing function, returns:
 * - -1 if the element 1 is inferior compared to the element 2.
 * - 0 if the element 1 and 2 are considered equals.
 * - 1 if the element 1 is superior compared to the element 2.
 * @param sortedList The expected result.
 */
void clist_sort(const CList * list, int (*sortFunction)(const void * data1, const void * data2), CList * sortedList);

/**
 * Constructs a new CList containing all the elements of list but with the order reversed.
 * The new list is then put into reversed.
 *
 * @param list
 * @param reversed The expected result.
 */
void clist_reverse(const CList * list, CList * reversed);

/**
 * Merges 2 CLists together, by constructing a new lists containing all the elements from list1 followed by all the
 * elements from list2.
 * The new list is then put into mergedList.
 *
 * @param list1
 * @param list2
 * @param mergedList The expected result.
 */
void clist_merge(const CList * list1, const CList * list2, CList * mergedList);

/**
 * Makes a copy of the given list into a new one. The new one contains all the elements of the first one, but the 2
 * CList are different and will need to be handled as such.
 *
 * @param list
 * @param copy The expected result.
 */
void clist_copy(const CList * list, CList * copy);

/**
 * Prints a CList onto stdout, using the given printFunction to print each and every data contained within the list.
 * No new line are added at the end of this function.
 *
 * See `clist_println` for that.
 *
 * @param list
 * @param printFunction A Consumer function, taking a data and printing onto stdout its content.
 */
void clist_print(const CList * list, void (*printFunction)(const void * data));

/**
 * Prints a CList onto stdout, using the given printFunction to print each and every data contained within the list.
 * A new line is then added to level the display.
 *
 * @param list
 * @param printFunction A Consumer function, taking a data and printing onto stdout its content.
 */
void clist_println(const CList * list, void (*printFunction)(const void * data));

#endif //CLIST_H
