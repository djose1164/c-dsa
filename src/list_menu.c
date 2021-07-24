#include "list_menu.h"
#include <stdio.h>
#include <stdlib.h>

static int list_menu_ask_data(const char *msg)
{
    char line[8];
    unsigned data;

    printf("%s", msg);
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &data);

    return data;
}

static unsigned list_menu_ask_quantity()
{
    const char *msg = "How may list do you want?: ";
    return list_menu_ask_data(msg);
}

static List *list_menu_create_necessary(const unsigned quantity)
{
    List *head = list_init(head);
    if (quantity == 1)
        return head;

    List *lists[quantity - 1];
    for (size_t i = 0; i < quantity - 1; i++)
    {
        *(lists + i) = list_init(*(lists + 1));
        list_add_last(head, *(lists + i));
    }

    return head;
}
static void list_menu_fill(List *head)
{
    char buffer[100];
    List *current = head;

    if (!list_is_valid(head))
    {
        fprintf(stderr, "List no valid!\n");
        exit(-1);
    }

    for (size_t i = 1; current; i++, current = current->next)
    {
        snprintf(buffer, sizeof buffer, "Fill in list #%zu with data: ", i);
        current->data = list_menu_ask_data(buffer);
        fflush(stdout);
    }
}

void list_menu()
{
    const unsigned list_quantity = list_menu_ask_quantity();
    List *head = list_menu_create_necessary(list_quantity);
    list_menu_fill(head);
    list_display(head);
   // linkedlist_delete(head);
    is_memory_good();
}