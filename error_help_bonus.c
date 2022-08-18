#include "header/pipex_bonus.h"

void	ft_call_exit(void)
{
	perror("Error");
	exit(1);
}

void	ft_call_com_not_found(void)
{
	perror("command not found");
	exit(127);
}

void	ft_call_cant_open(void)
{
	perror("Can not open");
	exit(0);
}

void	ft_call_cant_exe(void)
{
	perror("Command invoked cannot execute");
	exit(127);
}
