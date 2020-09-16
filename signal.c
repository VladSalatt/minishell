#include "minishell.h"

void 	handle_ctrl_c(int sig)
{
	sig = 0;
	ft_putchar("\n");
	g_signalflag = 0;
	display_prompt();
	g_signalflag = 1;
}