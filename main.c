/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gautier <gautier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:07:49 by jgautier          #+#    #+#             */
/*   Updated: 2022/11/22 01:00:46 by gautier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int main(int ac, char **av, char **env)
{
    // char    *cmd;
    // t_tok  *lst_tok;
    // t_tok  *lst_tmp;
    // t_prpt  *prompt;
	// char	*tab[3];
	// int		i;
	// int		j;
	// char	*path;

	launch_minish(env);
	// cmd = readline(">>");	
	// cmd = import_varsenv(cmd);
	// free(cmd);
	// // tab[0] = "ls";
	// // tab[1] = NULL;
	// printf("%s\n", getcwd(NULL, 0));
	// printf("%s\n", path);
	// printf("OK\n");
	// path = readline(">>");
	// chdir(path);
	// execve("/bin/ls", tab, env);
	// while (i)
    // {    
    //     lst_tok = NULL;
    //     lst_tmp = NULL;
    //     cmd = readline("minishell->");
    //     if (!cmd[0])
    //         printf("cest nuul \n");
    //     add_history(cmd);
	// 	tab = ft_split_cmd(cmd);
	// 	free(cmd);
    //     j = 0;
	// 	while (tab[j])
	// 	{
	// 		printf("%s\n", tab[j]);
	// 		j++;
	// 	}
	// 	free_tab(tab);
	// 	prompt->str = cmd;
    //     prompt->quote = quote_secur(cmd);
    //     lst_tok = token_izer(prompt);
    //     free(cmd);
    //     free(prompt->quote);
    //     free(prompt);
    //     lst_tmp = lst_tok;
    //     while (lst_tok)
    //     {
    //         printf("%s\n", lst_tok->content);
    //         lst_tok = lst_tok->next;
    //     }
    //     tok_lstclear(lst_tmp);
    //     tok_lstclear(lst_tok);
    //     i--;
    // }
    return (0);
}
