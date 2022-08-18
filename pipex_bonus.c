#include "header/pipex_bonus.h"

void	ft_for_first_child(int **pipe, char **argv, char **envp, int i)
{
	char	**cmd;
	int		fd1;
	int		d1;
	int		d2;

	fd1 = open(argv[1], O_RDONLY);
	if (fd1 == -1)
		ft_call_cant_open();
	d1 = dup2(fd1, 0);
	if (d1 == -1)
		ft_call_exit();
	d2 = dup2(pipe[0][1], 1);
	if (d2 == -1)
		ft_call_exit();
	close(pipe[0][0]);
	cmd = ft_delenie_cmd(argv[i]);
	cmd = ft_change_cmd(cmd, envp);
	execve(cmd[0], cmd, envp);
	ft_call_cant_exe();
}

void	ft_for_last_child(int **pipe, char **argv, char **envp, int i)
{
	char	**cmd;
	int		fd2;
	int		d1;
	int		d2;

	fd2 = open(argv[i + 3], O_CREAT | O_TRUNC | O_RDWR, 0777);
	if (fd2 == -1)
		ft_call_exit();
	d1 = dup2(pipe[i - 1][0], 0);
	if (d1 == -1)
		ft_call_exit();
	d2 = dup2(fd2, 1);
	if (d2 == -1)
		ft_call_exit();
	close(pipe[i - 1][0]);
	close(pipe[i - 1][1]);
	cmd = ft_delenie_cmd(argv[i + 2]);
	cmd = ft_change_cmd(cmd, envp);
	execve(cmd[0], cmd, envp);
	ft_call_cant_exe();
}

void	ft_for_circle_child(int **pipe, char **argv, char **envp, int i)
{
	char	**cmd;
	int		d1;
	int		d2;

	d1 = dup2(pipe[i - 1][0], 0);
	if (d1 == -1)
		ft_call_exit();
	d2 = dup2(pipe[i][1], 1);
	if (d2 == -1)
		ft_call_exit();
	close(pipe[i - 1][0]);
	close(pipe[i - 1][1]);
	close(pipe[i][0]);
	cmd = ft_delenie_cmd(argv[i + 2]);
	cmd = ft_change_cmd(cmd, envp);
	execve(cmd[0], cmd, envp);
	ft_call_cant_exe();
}

pid_t	ft_circle_function(int **pipes, int argc, char **argv, char **envp)
{
	int		i;
	pid_t	pid;

	i = -1;
	while (++i <= (argc - 4))
	{
		if (i < (argc - 4))
			pipe(pipes[i]);
		if (i > 0)
			close(pipes[i - 1][1]);
		pid = fork();
		if (pid < 0)
			ft_call_exit();
		else if (pid == 0)
		{
			if (i < (argc - 4))
				argc -= ft_choose_child(pipes, argv, envp, i);
			else
				ft_choose_last_child(pipes, argv, envp, i);
		}
		if (i > 0)
			close(pipes[i - 1][0]);
	}
	return (pid);
}

int	main(int argc, char **argv, char **envp)
{
	int		**pipes;
	int		status;
	pid_t	pid;

	if (argc <= 4)
		ft_call_exit();
	pipes = ft_create_pipes(argc);
	if (!pipes)
		return (1);
	pid = ft_circle_function(pipes, argc, argv, envp);
	ft_close_all(pipes, argc);
	waitpid(pid, &status, 0);
	ft_free_all(pipes, argc);
	return (WEXITSTATUS(status));
}
