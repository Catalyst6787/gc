/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dmbgc.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:38:14 by lfaure            #+#    #+#             */
/*   Updated: 2025/02/20 17:49:19 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DMBGC_H
# define DMBGC_H

# include <stdlib.h>

typedef struct s_gc
{
	void		*ptr;
	struct s_gc	*next;
}	t_gc;

typedef enum GetHead
{
	GET = 0,
	REMOVE
}	t_get_head;

void	*dmb_malloc(size_t size);
void	dmb_gc(void);
void	dmb_free(void	*ptr);
void	dmb_force_free(void	*ptr);

#endif