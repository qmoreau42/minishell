/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgautier <jgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 14:18:54 by jgautier          #+#    #+#             */
/*   Updated: 2022/06/14 14:25:14 by jgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>

/*ft_libft*/
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	free_tab(char **tab);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(const char *str);
/*ft_split*/
char	**ft_split(char const *s, char c);
/*pipex*/
char	*find_path(char **multi_path, char *cmd);
char	**recup_path(char **env);
int		gestion_error(int ac, int fdin, int fdout);
int		check_cmd(char **av, char **env, int ac);
/*exec*/
void	exec_cmd(char *av, char **env);
void	multi_cmd(char **av, char **env, int fdin, int fdout);
int		calcul_nb_cmd(char **av);
int		multi_cmd_2(pid_t pid, int *fd, int fdin, int *i);

#endif
