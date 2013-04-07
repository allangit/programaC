#include <stdio.h>
#include "list.h"

int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		tlist list;
		int n = atoi(argv[1]);
		value_type value;
		
		tlist_init(&list);
		
		srand48(time(NULL));
					
		while (n > 0)
		{
			value = (int) lrand48();			
			
			if (value & 1)
			{
				printf("Odd value: %d\n", value);
				tlist_insert_first(&list, value);
			}
			else
			{
				printf("Even value: %d\n", value);
				tlist_insert_last(&list, value);
			}
			
			n--;
		}
		
		tlistnode *node = list.first;
		
		while (node != NULL)
		{
			printf("Value from list: %d\n", node->value);
			node = node->next;
		}
		
		tlist_clear(&list);
	}
	else
	{
		printf("Usage: test_list <num of list items>\n");
	}
	
	return 0;
}
