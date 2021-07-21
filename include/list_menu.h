#ifndef LIST_MENU_H
#define LIST_MENU_H

#include "list.h"
/****************************************************************************/
/*                            Public functions.                             */
/****************************************************************************/

void list_menu();

/****************************************************************************/
/*                            Private functions.                            */
/****************************************************************************/

static unsigned list_menu_ask_quantity();
static void list_menu_fill(List *head);
static int list_menu_ask_data();
static List *list_menu_create_necessary(const unsigned quantity);

#endif //LIST_MENU_H
