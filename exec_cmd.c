#include "minish.h"

void	multi_cmd(t_tok *token, char **env, int fdin, int fdout)
{
	pid_t	pid;
	int		fd[2];

	while (token)
	{
		if (pipe(fd) == -1)
			perror("pipe");
		pid = fork();
		if (pid == 0)
		{
			dup2(fdin, 0);
			if (token->next)
				dup2(fd[1], 1);
			else
				dup2(fdout, 1);
			close(fd[0]);
	        execve(token->path, token->cmd, env);
		}
		else if (pid > 0)
        {
			fdin = multi_cmd_2(pid, fd, fdin);
            token = token->next;
        }
	}
}

int	multi_cmd_2(pid_t pid, int *fd, int fdin)
{
	waitpid(pid, NULL, 0);
	close(fd[1]);
	fdin = fd[0];
	return (fdin);
}