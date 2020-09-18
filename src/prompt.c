#include "minishell.h"

/*
 * Display prompt with git branch
 */

void 	display_git_prompt(char **branch_name)
{
	ft_putstr("(mini) ");
	ft_putstr("-> ");
	ft_putstr(*branch_name);
	ft_strdel(branch_name);
}

/*
 * Display prompt without git branch
 */

void 	display_default_prompt(void)
{
	ft_putstr("(mini) ");
}

/*
 * Display prompt relative to git branch
 */

void 	display_prompt(void)
{
	char 	*branch_name;

	if (g_signalflag == 0)
	{
		if ((branch_name = gitdir_search()) != NULL)  // If a git branch exist
			display_git_prompt(&branch_name);
		else
			display_default_prompt();
	}
	else
		g_signalflag = 0;
}