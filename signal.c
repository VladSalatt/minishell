#include "minishell.h"

void 	handle_ctrl_c(int sig)
{
	sig = 0;
	ft_putchar("\n");
	g_signalflag = 0;
	di
}