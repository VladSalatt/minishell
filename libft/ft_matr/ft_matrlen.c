#include "libft.h"

size_t 		ft_matrlen(const char **matr)
{
	size_t 	len;

	len = 0;
	while (*matr != NULL)
	{
		len++;
		matr++;
	}
	return (len);
}