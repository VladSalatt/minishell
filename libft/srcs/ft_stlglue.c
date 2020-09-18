#include "libft.h"

/*
 * Puts into the "puthere" the arguments that were entered after him
 */

void 	ft_strglue(char *puthere, ...)
{
	va_list		arg;
	int 		count;
	int 		i;
	char 		*str;

	if (puthere == NULL)
		return ;
	va_start(arg, (char *)puthere);
	count = ft_strlen(puthere);
	while (1)
	{
		if ((str = va_arg(arg, char *)) == NULL)
			break ;
		i = 0;
		while (str[i] != '\0')
			puthere[count++] = str[i++];
	}
}