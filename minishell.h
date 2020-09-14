#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/includes/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <limits.h>
# include <fcntl.h>
# include <dirent.h>
# include <signal.h>


# define GIT_BRANCH_NAME_FILE ".git/HEAD"

int		g_signalflag;

char 	*gitdir_search(void);

#endif