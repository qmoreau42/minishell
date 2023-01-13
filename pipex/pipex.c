/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgautier <jgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 14:18:25 by jgautier          #+#    #+#             */
/*   Updated: 2022/11/04 16:58:21 by jgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	int		fdin;
	int		fdout;
	
	if (!*env || !check_cmd(av, env, ac))
		return (2);
	fdin = open(av[1], O_RDONLY);
	fdout = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (gestion_error(ac, fdin, fdout) == 0)
		return (2);
	multi_cmd(av, env, fdin, fdout);
	close(fdout);
	close(fdin);
	return (0);
}

char	**recup_path(char **env)
{
	int		i;
	char	*path;
	char	**multi_path;

	i = 0;
	while (ft_strncmp(env[i], "PATH=", 5))
		i++;
	path = env[i] + 5;
	multi_path = ft_split(path, ':');
	return (multi_path);
}

char	*find_path(char **multi_path, char *cmd)
{
	int		i;
	char	*str;
	char	*tmp;

	i = 0;
	tmp = ft_strjoin("/", cmd);
	while (multi_path[i])
	{
		str = ft_strjoin(multi_path[i], tmp);
		if (access(str, F_OK) == 0)
		{
			free(tmp);
			return (str);
		}
		i++;
		free(str);
	}
	free(tmp);
	return (NULL);
}

int	gestion_error(int ac, int fdin, int fdout)
{
	if (ac < 5)
	{
		write(2, "Erreur, nombre d'argument\n", 26);
		return (0);
	}
	if (fdin == -1)
	{
		write(2, "Files not found\n", 16);
		close(fdin);
		close(fdout);
		return (0);
	}
	if (fdout == -1)
	{
		write(2, "Error outfile open\n", 20);
		close(fdin);
		close(fdout);
		return (0);
	}
	return (1);
}

int	check_cmd(char **av, char **env, int ac)
{
	char	**multi_path;
	char	**cmd;
	char	*path;

	while (ac >= 4)
	{
		multi_path = recup_path(env);
		cmd = ft_split(av[ac - 2], ' ');
		path = find_path(multi_path, cmd[0]);
		free_tab(multi_path);
		free_tab(cmd);
		if (!path)
		{
			free(path);
			write(2, "command not found\n", 18);
			return (0);
		}
		free(path);
		ac--;
	}
	return (1);
}
