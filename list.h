/*
hola
*/

#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

typedef int value_type;
typedef struct slistnode tlistnode;
typedef struct slistnode {
	value_type value;
	tlistnode *next;
} tlistnode;

typedef struct slist {
	tlistnode *first;
	tlistnode *last;
	long size;
} tlist;

tlistnode * tlistnode_new(value_type value, tlistnode *next);

void tlist_init(tlist *list);
int tlist_is_empty(tlist *list);
int tlist_insert_first(tlist *list, value_type value);
int tlist_insert_at(tlist *list, long index, value_type value);
int tlist_insert_last(tlist *list, value_type value);
void tlist_clear(tlist *list);

#endif
