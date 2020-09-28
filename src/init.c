#include "minishell.h"

void 		init_hashtable_form_envypath(void)
{
	char 		**tmp;
	const char	*envy_path;

	g_envypath = ft_mapnew(NULL, 2000);
	if ((envy_path = getvalue_envy)
}

/*
 * Assigns the path to the executable file to the environment variable SHELL
 */

static void setvar_shell(int indexof_shell)
{
	char 	dir[PATH_MAX];
	size_t 	size_of_shellvar;

	getcwd(dir, PATH_MAX);
	size_of_shellvar = ft_strlen("SHELL=") + ft_strlen(dir) + ft_strlen("/minishell");
	if ((g_envy[indexof_shell] = (char *)ft_memalloc(sizeof(char) * (size_of_shellvar + 1))) == NULL)
		exit (-1);
	ft_strglue(g_envy[indexof_shell], "SHELL=", dir, "/minishell", NULL);
}

/*
 * Increment SHLVL variable
 */

static void setvar_shlvl(const char *shlvl_var, int indexof_shlvl)
{
	int		lvl;
	char 	*next_lvl;
	size_t 	size_of_shlvl_var;

	lvl = ft_atoi(shlvl_var + ft_strlen("SHLVL-"));
	next_lvl = ft_itoa(lvl + 1);
	size_of_shlvl_var = ft_strlen("SHLVL=") + ft_strlen(next_lvl);
	if ((g_envy[indexof_shlvl] = (char *)ft_memalloc(sizeof(char) * (size_of_shlvl_var + 1))) == NULL)
		exit(-1);
	ft_strglue(g_envy[indexof_shlvl], "SHLVL=", next_lvl, NULL);
	ft_strdel(&next_lvl);
}

/*
 * Copy environment to global string array
 */

void 	init_global_envy(const char **envy)
{
	int 	i;

	if((g_envy = (char **)malloc(sizeof(char *) * (ft_matrlen(envy) + 1))) == NULL)
		exit (-1);
	i = 0;
	while (envy[i] != NULL)
	{
		if (ft_strncmp("SHELL", envy[i], ft_strlen("SHELL")) == 0)
			setvar_shell(i++);
		else if (ft_strncmp("SHLVL", envy[i], ft_strlen("SHLVL")) == 0)
		{
			setvar_shlvl(envy[i], i);
			i++;
		}
		else
		{
			g_envy[i] = ft_strdup(envy[i]);
			i++;
		}
	}
	g_envy[i] = NULL;
}
