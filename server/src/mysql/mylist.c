#include "mylist.h"


bool list_init(list_t **list)
{
	if(NULL == ((*list) = (list_t*)malloc(sizeof(list_t))))
	{
		return false;
	}
	if(NULL == ((*list)->front = (node_t*)malloc(sizeof(node_t))))
	{
		return false;
	}
	(*list)->rear = (*list)->front;
	(*list)->front->next = NULL;



	return true;
}

	
bool lst_push(list_t *list,const char *str)
{
	node_t *tmp = NULL;
	if(NULL == (tmp = (node_t*)malloc(sizeof(node_t))))
	{
		return false;	
	}
	if(NULL == (tmp->data = (char*)malloc(strlen(str)+1)))
	{
		return false;
	}
	if(NULL == (strncpy(tmp->data,str,strlen(str)+1)))
	{
		return false;
	}
	tmp->next = NULL;

	list->rear->next = tmp;
	list->rear = tmp;
	return true;

}
char *lst_pop(list_t *list)
{
	if(list->front == list->rear)
	{
		return NULL;
	}
	if(list->front->next == NULL)
	{
		return NULL;
	}
	node_t *tmp = list->front->next;
	char *str = tmp->data;
	list->front->next = tmp->next;
	if(tmp == list->rear)
	{
		list->rear = list->front;
	}
	if(tmp == NULL)
		return NULL;
	free(tmp);
	tmp = NULL;

	return str;
}


bool lst_destroy(list_t **list)
{
	
	while(lst_pop(*list));
	free((*list)->front);
	(*list)->front = NULL;
	(*list)->rear = NULL;
	free(*list);
	(*list) = NULL;
	return true;
}

bool lst_empty(list_t *list)
{
        if(list == NULL)
        {
                return true;
        }
        
        return false;
}
