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
	list_menu();
	return (0);
}