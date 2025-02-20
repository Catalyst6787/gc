#ifndef DMBGC_H
# define DMBGC_H

#include <stdlib.h>
#include <stdio.h> // REMOVE

typedef struct s_gc
{
	void	*ptr;
	struct s_gc	*next;
}	t_gc;

typedef enum {
	ERROR_NONE = 0,
	ERROR_MALLOC_FAILED,
	ERROR_OTHER
}	ErrorCode;

typedef enum {
	GET = 0,
	REMOVE
}	GetHead;

void	*dmb_malloc(int size);
void	dmb_gc(t_gc *head);
t_gc	*get_head();
void	dmb_free(void	*ptr);

#endif