#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

static unsigned counter_allocation;
static unsigned counter_deallocation;

typedef struct List
{
    int data;
    struct List *next;
} List;

/**
 * @brief Create a new linked list.
 * 
 * @param list The list to be allocated.
 * @return List* Return the allocated memory.
 */
List *list_init(List *list);

/**
 * @brief Deallocates a linked list.
 * 
 * @param list The pointer to memory.
 */
void list_destroy(List *list);

void list_delete_all(List *head);
/**
 * @brief Add a new list to the linked list to the end.
 * 
 * @param list Lis to be added to th end.
 */
void list_add_last(List *head, List *list);

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

#endif //LIST_H
