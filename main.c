#include "dmbgc.h"

void	create_tab()
{
	int	tab_size = 10;
	int i = 0;
	int j = 0;
	char **tab;

	tab = dmb_malloc(sizeof(char *) * (tab_size + 1));
	tab[tab_size] = NULL;
	while(i < tab_size)
	{
		tab[i] = dmb_malloc(sizeof(char) * (tab_size + 1));
		tab[i][tab_size] = '\0';
		while(j < tab_size)
		{
			tab[i][j] = 'A';
			j++;
		}
		j = 0;
		i++;
	}

	i = 0;
	j = 0;

	while(tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
}

int	main(void)
{
	char	*s;

	s = dmb_malloc(sizeof(char) * 2);
	s = dmb_malloc(sizeof(char) * 2);
	s = dmb_malloc(sizeof(char) * 2);
	s = dmb_malloc(sizeof(char) * 2);
	s = dmb_malloc(sizeof(char) * 2);
	if(!s)
		return(printf("Error: %d", ERROR_MALLOC_FAILED), 1);
	s[0] = 's';
	s[1] = '\0';
	printf("%s\n", s);

	create_tab(get_head(GET));

	dmb_gc(get_head(GET));

	return(0);
}
