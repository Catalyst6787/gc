#include "dmbgc.h"

t_gc	*get_tail(t_gc *head)
{
	if (!head)
		return(head);
	while(head->next)
		head = head->next;
	return(head);
}

t_gc	*append_node(void *ptr, t_gc *head)
{
	t_gc	*tail;
	t_gc	*new_node;

	new_node = malloc(sizeof(t_gc));
	if (!new_node)
		return(printf("malloc error in append_node\n"), head); // TODO handle fail
	new_node->next = NULL;
	new_node->ptr = NULL;
	tail = get_tail(get_head(GET));
	if (!tail)
		return(printf("malloc error in get_head\n"), NULL);
	tail->next = new_node;
	new_node->ptr = ptr;
	return(head);
}

void	*dmb_malloc(int size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		return(NULL);
	append_node(ptr, get_head());
	return(ptr);
}

void	dmb_gc(t_gc *head)
{
	t_gc *next;

	next = NULL;
	while(head)
	{
		if (head->ptr)
		{
			free(head->ptr);
			head->ptr = NULL;
		}
		next = head->next;
		free(head);
		head = next;
	}
}

t_gc	*get_head()
{
	static	t_gc	*head;

	if (!head)
	{
		head = malloc(sizeof(t_gc));
		if (!head)
			return(NULL);
		head->ptr = NULL;
		head->next = NULL;
	}
	return(head);
}

void	dmb_free(void	*ptr)
{
	t_gc	*tail;
	t_gc	*prev;

	tail = get_head();
	prev = get_head();
	while(tail)
	{
		if (tail->ptr == ptr)
		{
			free(ptr);
			tail->ptr = NULL;
			prev->next = tail->next;
			free(tail);
			return ;
		}
		prev = tail;
		tail = tail->next;
	}
	//free(ptr);
	return ;
}
