#include <stdio.h>
#include "../include/list.h"

sum(unsigned n)
{
	if (n)
		return n + sum(n - 1);
	else
		return n;
}
int main()
{
	LinkedList l;
	List *head = list_init(head);
	l.head = head;

	List *list1 = list_init(list1);
	List *list2 = list_init(list2);
	List *list3 = list_init(list3);

	head->data = 0;
	list1->data = 1;
	list2->data = 2;
	list3->data = 3;

	linkedlist_add(&l, list1);
	linkedlist_add(&l, list2);
	linkedlist_add(&l, list3);

	/*
	list_add_last(head, list1);
	list_add_last(head, list2);
	list_add_last(head, list3);

	printf("Before removing\n");
	list_display(head);

	list_remove(head, list1);

	printf("After removing\n");
	list_display(head);
	list_insert_before(head, list2, list3);

	printf("After insert before\n");
	*/
	list_display(head);

	linkedlist_delete(&l);
	is_memory_good();
	return (0);
}