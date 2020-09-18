#include "minishell.h"

/*
 * Get value of environment variable
 */

const char 		*getvalue_envy(const char *var_name)
{
	int 		index_of_key;
	const char 	*result;
	size_t 		len;

	if (var_name == NULL)
		return (NULL);
	len = ft_strlen(var_name);
	if ((index_of_key = find_envy((const char **)g_envy, var_name)) == -1)
		return (NULL);
	result = g_envy[index_of_key] + len + 1;
	return (result);
}

/*
 * Get index of environment variable
 */

int 			find_envy(const char **envy, const char *var_name)
{
	int 		i;
	int 		j;
	int 		len;

	i = 0;
	while (envy[i] != NULL)
	{
		j = 0;
		len = 0;
		while (envy[i][j] != '=' && envy[i][j] != '\0')
		{
			len++;
			j++;
		}
		if (ft_strncmp(envy[i], var_name, len) == 0 && var_name[len] == '\0')
			return (i);
		i++;
	}
	return (-1);
}
