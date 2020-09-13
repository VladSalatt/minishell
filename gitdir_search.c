#include "minishell.h"

/* Glues current position and default
** location with the branch name
*/

static char 	*get_path(char *current_path)
{
	char 	*path_to_branch_name_file;
	char 	len;

	len = ft_strlen(current_path) + ft_strlen("/") + ft_strlen(GIT_BRANCH_NAME_FILE) + 1;
	if ((path_to_branch_name_file = (char *)ft_memalloc(sizeof(char) * len)) == NULL)
		exit(-1);
	ft_strglue(path_to_branch_name_file, current_path, "/", GIT_BRANCH_NAME_FILE, NULL);
	return (path_to_branch_name_file);
}

static char 	*get_branch_name(char *path_to_branch_name_file)
{
	int 	fd;
}

char 	*gitdir_search(void)
{
	char 	*current_path;
	char 	*stop_path;
	char 	*path_to_branch_name_file;
	char 	*branch_name;
	char 	dir[PATH_MAX];

	branch_name = NULL;
	stop_path = ft_strdup("/");
	getcwd(dir, PATH_MAX);
	current_path = ft_strdup(dir);
	while (ft_strcmp(current_path, stop_path) != 0)
	{
		path_to_branch_name_file = get_path(current_path);
		if (access(path_to_branch_name_file, 0) == 0)
		{
			branch_name = get_branch_name
		}
	}
}