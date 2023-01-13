/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token-izer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gautier <gautier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:43:21 by jgautier          #+#    #+#             */
/*   Updated: 2022/11/22 00:40:10 by gautier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"

t_tok	*token_izer(char *str, char *str_desac)
{
	t_tok		*lst_tok;
	char		*cmd_cut;
	int			i;

	i = 0;
	lst_tok = NULL;
	while (str[i])
	{
		cmd_cut = NULL;
		cmd_cut = cp_cmd(str, str_desac, &i);
		if (cmd_cut)
			if (tok_lstadd_back(&lst_tok, tok_lstnew(cmd_cut)))
				return (NULL);//free lst_tok
		if (str[i])
			i++;
	}
	return (lst_tok);
}

char	*cp_cmd(char *str, char *quote, int *i)
{
	char	*cmd_tmp;
	char	*cmd_cut;

	cmd_tmp = NULL;
	cmd_cut = NULL;
	while (str[*i] && (quote[*i] == '1' || str[*i] != '|'))
	{
		cmd_tmp = cmd_cut;
		cmd_cut = ft_straddchar(cmd_tmp, str[*i]);
		free(cmd_tmp);
		*i = *i + 1;
	}
	return (cmd_cut);
}

