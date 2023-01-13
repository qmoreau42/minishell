/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 23:55:53 by qmoreau           #+#    #+#             */
/*   Updated: 2023/01/13 15:50:12 by qmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minish.h"

/*
int	reduct_str(t_tok tok)
{
	int		i;
	char *tmp;

	i = 0;
	while (tok.content[i] != '<' && tok.content[i] != '>')
	{
		tmp = malloc(sizeof);
	}
}
*/

int		skipped_ws(t_tok tok, int i)
{
	int	j;

	j = 0;
	while (tok.content[i + j] == ' ')
		j++;
	return (j);
}

int	redir_out(t_tok tok, int i)
{
	int	j;

	if (tok.file_output != NULL)
		free(tok.file_output);
	if (tok.fd_output != 0)
		close(tok.fd_output);
	j = skipped_ws(tok, i);
	while (tok.content[i + j] != ' ')
	{
		ft_strjoin(tok.file_output, &tok.content[i + j]);
		j++;
	}
	if (access(tok.content, F_OK) == 0)
	{
		if (tok.content[i + 1] == '>')
			tok.fd_output = open(tok.file_output, O_APPEND, O_WRONLY);
		else 
			tok.fd_output = open(tok.file_output, O_WRONLY);
	}
	else
		tok.fd_output = open(tok.file_output, O_CREAT, O_WRONLY);
	if (tok.fd_output == -1)
	{
		//ERROR
	}
}

void	redir(t_tok tok)
{
	int	i;
	int j;

	i = 0;
	while (tok.content[i])
	{
		if (tok.content[i] == '>')
			i = redir_out(tok, i);
		if (tok.content[i] == '<')
		{
			if (tok.file_input != NULL)
				free(tok.file_input);
			j = skipped_ws(tok, i);
			while (tok.content[i + j] != ' ')
			{
				ft_strjoin(tok.file_input, tok.content[i + j]);
				j++;
			}
			tok.fd_redir_in = open(tok.redir_in, O_RDONLY);
			if (!tok.fd_redir_in)
				//Error
		}
		i++;
	}
}
