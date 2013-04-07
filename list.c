/**
 * list.c
 * 
 * Implementation of the functionality of a list.
 * 
 * Created by: Martínez Flores, Allan
 * Created on: 2013-03-01
 * Last update: 2013-04-07
 * */

#include "list.h"

tlistnode * tlistnode_new(value_type value, tlistnode *next)
{
	tlistnode *node = (tlistnode *) malloc(sizeof(tlistnode));
	
	if (node != NULL)
	{
		node->value = value;
		node->next = next;
	}
	
	return node;
}

void tlist_init(tlist *list)
{
	list->first = NULL;
	list->last = NULL;
	list->size = 0;
}

int tlist_is_empty(tlist *list)
{
	return list->size == 0;
}

int tlist_insert_first(tlist *list, value_type value)
{
	tlistnode *newnode = tlistnode_new(value, list->first);
	
	if (newnode != NULL)
	{
		list->first = newnode;
		
		if (list->last == NULL) {
			list->last = newnode;
		}
		
		list->size++;
		
		return 1;
	}
	
	return 0;
}

int tlist_insert_at(tlist *list, long index, value_type value)
{
	if (index <= 0) return tlist_insert_first(list, value);
	if (index >= list->size) return tlist_insert_last(list, value);
	
	tlistnode *newnode = tlistnode_new(value, NULL);
	
	if (newnode != NULL)
	{
		tlistnode *node = list->first;
		
		while (node != NULL && index > 1)
		{
			node = node->next;
			index--;
		}
		
		newnode->next = node->next;
		node->next = newnode;
		
		list->size++;
		
		return 1;
	}
	
	return 0;
}

int tlist_insert_last(tlist *list, value_type value)
{
	tlistnode *newnode = tlistnode_new(value, NULL);
	
	if (newnode != NULL)
	{
		if (list->first == NULL)
		{
			list->first = newnode;
		}
		else
		{
			list->last->next = newnode;
		}
		
		list->last = newnode;
		
		list->size++;
		
		return 1;
	}
	
	return 0;
}

void tlist_clear(tlist *list) {
	tlistnode *node = list->first;
	
	while (node != NULL)
	{
		list->first = list->first->next;
		free(node);
		node = list->first;
	}
	
	tlist_init(list);
}
