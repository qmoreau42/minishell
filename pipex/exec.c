/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgautier <jgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:50:42 by jgautier          #+#    #+#             */
/*   Updated: 2022/11/04 17:00:02 by jgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_cmd(char *av, char **env)
{
	char	*path;
	char	**cmd;
	char	**multi_path;

	multi_path = recup_path(env);
	cmd = ft_split(av, ' ');
	path = find_path(multi_path, cmd[0]);
	execve(path, cmd, env);
	perror("execve");
}

void	multi_cmd(char **av, char **env, int fdin, int fdout)
{
	pid_t	pid;
	int		fd[2];
	int		nb_cmd;
	int		i;

	i = 2;
	nb_cmd = calcul_nb_cmd(av) - 1;
	while (i < nb_cmd)
	{
		if (pipe(fd) == -1)
			perror("pipe");
		pid = fork();
		if (pid == 0)
		{
			dup2(fdin, 0);
			if (i != nb_cmd - 1)
				dup2(fd[1], 1);
			else
				dup2(fdout, 1);
			close(fd[0]);
			exec_cmd(av[i], env);
		}
		else if (pid > 0)
			fdin = multi_cmd_2(pid, fd, fdin, &i);
	}
}

int	multi_cmd_2(pid_t pid, int *fd, int fdin, int *i)
{
	waitpid(pid, NULL, 0);
	close(fd[1]);
	fdin = fd[0];
	*i = *i + 1;
	return (fdin);
}

int	calcul_nb_cmd(char **av)
{
	int	i;

	i = 2;
	while (av[i])
		i++;
	return (i);
}
