/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parrsing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gautier <gautier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 00:43:15 by gautier           #+#    #+#             */
/*   Updated: 2022/11/22 00:58:08 by gautier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"

t_tok   *parsing(char *str)
{
    char    *str_desact;
    t_tok   *token;

	str_desact = quote_secur(str);
    if (!str_desact)
        return (NULL);//free str
    token = token_izer(str, str_desact);
	free(str_desact);
    // if (!token)
    //     return (NULL);//free token
	init_token(token);
	if (!token_split_and_varenv(token))
		return (NULL);//free token
	return (token);
}

int	token_split_and_varenv(t_tok *token)
{
	while (token)
	{
		token->content = import_varsenv(token->content);
		if (!token->content)
			return (0);//free token
		token->cmd = ft_split_cmd(token->content);
		if (!token->cmd)
			return (0);//free token
        path_cmd(token);
		token = token->next;
	}
	return (1);
}