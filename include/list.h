#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

#define NULL ((void *)0)
#define die exit(-1)
static unsigned counter_allocation;
static unsigned counter_deallocation;

struct List
{
    int data;
    struct List *next;
};
typedef struct List List;

struct LinkedList
{
    List *head;
};
typedef struct LinkedList LinkedList;

/**
 * @brief Create a new linked list.
 * 
 * @param list The list to be allocated.
 * @return List* Return the allocated memory.
 */
List *list_init(List *list);

/**
 * @brief Add a new list to the linked list.
 * 
 * @param head The linked list's head.
 * @param new The list to be added.
 */
void linkedlist_add(LinkedList *l, List *new);

/**
 * @brief Deallocates a linked list.
 * 
 * @param list The pointer to memory.
 */
static inline void list_destroy(List *list)
{
    free(list);
    list = NULL;
    ++counter_deallocation;
}

static inline void linkedlist_delete(LinkedList *l)
{
    if (l)
        list_delete_all(l->head);
}

static inline void list_remove(List *head, List *target)
{
    List **current = list_find_indirect(head, target);
    *current = target->next;
    list_destroy(target);
}

void list_insert_before(List *head, List *before, List *item);

void list_display(List *head);

void is_memory_good();

static inline bool list_is_valid(List *list)
{
    if (list)
        return true;
    return false;
}

#if 0  // To check later.
/**
 * @brief Inserts an element just after element in the linked list specified 
 * by list. If element is NULL, the new element is inserted at the head of 
 * the list. The new element contains a pointer to data, so the memory 
 * referenced by data should remain valid as long as the element remains in 
 * the list. It is the responsibility of the caller to manage the storage 
 * associated with data.
 * 
 * @param list 
 * @param element 
 * @param data 
 * @return int 
 */
int list_ins_next(List *list, ListElmt *element, const void* data);

/**
 * @brief Add a new data to an existing linked list.
 * 
 * @param index To what linked list add the data.
 * @param data The data to be saved.
 */
void linked_list_add_data(unsigned index, void *data);


void list_print_all(void);
#endif // To check later.
/****************************************************************************/
/*                            Private functions.                            */
/****************************************************************************/

/**
 * @brief Verify that the requested index exists
 * 
 * @param index The index to check.
 * @return true The index exists.
 * @return false The index does no exists.
 */
static bool linked_list_exists(List *head, unsigned index);
static void check_allocation(void *const list);
static List **list_find_indirect(List *head, List *target);
static inline void list_delete_all(List *head)
{
    if (head->next)
        list_delete_all(head->next);
    list_destroy(head);
}

#endif //LIST_H
