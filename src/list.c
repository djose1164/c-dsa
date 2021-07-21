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

void list_destroy(List *list)
{
    free(list);
    list = NULL;
    ++counter_deallocation;
}

void list_delete_all(List *head)
{
    if (head->next)
        list_delete_all(head->next);
    if (head)
        list_destroy(head);
}
void list_add_last(List *head, List *list)
{
    if (!head->next)
        head->next = list;
    else
        list_add_last(head->next, list);
}

void list_display(List *head)
{
    List *current = head;
    for (; current; current = current->next)
        printf("Data: %d\n", current->data);

    putchar('\n');
}

List linked_list_print(void);

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
