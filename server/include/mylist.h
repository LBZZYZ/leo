#ifndef _MYLIST_H_
#define _MYLIST_H_
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
typedef struct  list_node
{
	char *data;
	struct list_node *next;
}node_t;

typedef struct 
{
	node_t *front;
	node_t *rear;
}list_t;


bool list_init(list_t **list);
bool lst_push(list_t * list,const char *str);
char* lst_pop(list_t * list);
bool lst_insert(list_t * list,const char *str);
bool lst_delete(list_t * list,const char *str);
bool lst_destroy(list_t ** list);
#endif
