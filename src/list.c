#include "../include/list.h"
#include <stdio.h>
#include <stdlib.h>

static unsigned counter_allocation;
static unsigned counter_deallocation;

List *list_init(List *list)
{
    List *mem = malloc(sizeof(List));
    mem->next = NULL;
    check_allocation(mem);
    ++counter_allocation;

    return mem;
}

void linkedlist_add(LinkedList *l, List *new)
{
    if (!list_is_valid(new))
    {
        fprintf(stderr, "List no valid!");
        die;
    }
    List *current = l->head;
    if (!current)
    {
        current = new;
        return;
    }

    for (; current->next; current = current->next)
        ;
    current->next = new;
    new->next = NULL;
}

static List **list_find_indirect(List *head, List *target)
{
    List **current = &head;

    while ((*current) && (*current) != target)
        current = &(*current)->next;
    return current;
}

void list_insert_before(List *head, List *before, List *item)
{
    /**
     * @brief Hay que ver cuando before es el ultimo elemento para q no se haga
     * un bucle.
     * 
     */
    List **current = list_find_indirect(head, before);
    *current = item;
    before->next = NULL;
    item->next = before;
}

void list_display(List *head)
{
    List *current = head;
    for (; current; current = current->next)
        printf("Data: %d\n", current->data);

    putchar('\n');
}

void is_memory_good()
{
    if (counter_allocation == counter_deallocation)
        printf("All is good! :D\n");
    else
        fprintf(stderr, "Mayday, mayday, there's error!\n"
                        "\a\tAllocations: %d\tDeallocations: %d\n",
                counter_allocation, counter_deallocation);
}

/****************************************************************************/
/*                            Private functions.                            */
/****************************************************************************/

static bool is_index_exists(List *head, unsigned index)
{
    //------------------------------------------------------------------------
    //--------------    Todo: Finish this.  ----------------------------------
    //------------------------------------------------------------------------
    size_t counter = 1;
    if (index == counter)
        return true;
    else
    {
        for (; head->next; head++)
            return true;
    }

    return false;
}

static void check_allocation(void *const list)
{
    if (!list)
    {
        fprintf(stderr, "Error allocation memory.\n");
        exit(-1);
    }
}
