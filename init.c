#include "minishell.h"

void 	init_global_envy(const char **envy)
{
	int 	i;

	if((g_envy = (char **)malloc(sizeof(char *) * (ft_matrlen(envy) + 1))) == NULL)
		exit (-1);
	i = 0;

}