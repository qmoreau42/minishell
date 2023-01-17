/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 23:55:53 by qmoreau           #+#    #+#             */
/*   Updated: 2023/01/17 15:21:12 by qmoreau          ###   ########.fr       */
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
		{
			tok.fd_output = open(tok.file_output, O_APPEND, O_WRONLY);
			i++;
		}
		else 
			tok.fd_output = open(tok.file_output, O_WRONLY);
	}
	else
		tok.fd_output = open(tok.file_output, O_CREAT, O_WRONLY);
	if (tok.fd_output == -1)
	{
		//ERROR
	}
	return (i);
}

int		*add_int(int	*tab, int	add)
{
	int	cpt;
	int	*ret;

	cpt = 0;
	if (!tab)
	{
		ret = malloc(sizeof(int) * 2);
		ret [0] = add;
		ret [1] = -1;
		return (ret);
	}
	while (ret[cpt] != -1)
		cpt++;
	ret = malloc(sizeof(int) * (cpt + 2));
	ret[cpt + 1] = -1;
	ret[cpt] = add;
	while (cpt != 0)
	{
		ret[cpt - 1] = tab[cpt - 1];
		cpt--;
	}
	free(tab);
	return (ret);
}

void	redir(t_tok tok)
{
	int	i;
	int j;
	int	k;
	int	l;

	i = 0;
	k = 0;
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
				ft_strjoin(tok.file_input, &tok.content[i + j]);
				j++;
			}
			tok.fd_input = add_int(tok.fd_input, open(tok.file_input, O_RDONLY));
			if (tok.fd_input[k] == -1)
			{
				//Error
			}
			if (tok.content[i + 1] == '<')
			{
				tok.heredoc = 1;
				j = skipped_ws(tok, i + 1);
				while (tok.content[i + j + 1] != ' ')
				{
					ft_strjoin(tok.limiter, tok.content[i + j]);
				}
			}
		}
		i++;
	}
}
/*
int	main()
{
	int	i;
	int	*test;

	test = NULL;
	i = 0;
	test = add_int(test, 5);
	test = add_int(test, 4);
	test = add_int(test, 3);
	test = add_int(test, 2);
	test = add_int(test, 1);
	while (test[i] != -1)
	{
		printf("%d\n", test[i]);
		i++;
	}
}
*/
