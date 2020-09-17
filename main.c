#include "minishell.h"

int 	main(int ac, char **av, char **env)
{
	ac = 0;
	av = NULL;
	g_signalflag = 0;
	signal(SIGINT, handle_ctrl_c);
	init_global_envy((const char **)env);
	init_hashtable_form_envypath()
}