#include "minishell.h"

int 	main(int ac, char **av, char **env)
{
	ac = 0;
	av = NULL;
	g_signalflag = 0;                        // ??? // I don't know what this flag does yet
	signal(SIGINT, handle_ctrl_c);          // Define signal(handle) for exit
	//init_global_envy((const char **)env);
	//init_hashtable_form_envypath();
}