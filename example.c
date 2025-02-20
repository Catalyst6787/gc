/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:32:02 by lfaure            #+#    #+#             */
/*   Updated: 2025/02/20 17:42:30 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dmbgc.h"
#include "dmbgc_replace.h"

void	create_tab()
{
	int	tab_size = 10;
	int i = 0;
	int j = 0;
	char **tab;

	tab = malloc(sizeof(char *) * (tab_size + 1));
	tab[tab_size] = NULL;
	while(i < tab_size)
	{
		tab[i] = malloc(sizeof(char) * (tab_size + 1));
		tab[i][tab_size] = '\0';
		while(j < tab_size)
		{
			tab[i][j] = 'A';
			j++;
		}
		j = 0;
		i++;
	}
}

int	main(void)
{
	char	*s;

	s = malloc(sizeof(char) * 2);
	s = malloc(sizeof(char) * 2);
	s = malloc(sizeof(char) * 2);
	s = malloc(sizeof(char) * 2);
	s = malloc(sizeof(char) * 2); // orphan mallocs will be handled by dmb_gc
	create_tab();
	create_tab();
	create_tab();

	//s = readline("enter text: ");
	//dmb_force_free(s); // regular dmb_free will not free pointers from external libs

	free(s);
	free(s);
	free(s);
	free(NULL);
	free(NULL);

	dmb_gc(); // this needs to be at the end
	return(0);
}
