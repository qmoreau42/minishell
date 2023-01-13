/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gautier <gautier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:03:10 by gautier           #+#    #+#             */
/*   Updated: 2022/11/21 21:43:40 by gautier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"

int	tok_lstadd_back(t_tok **alst, t_tok *new)
{
	t_tok	*tmp;

	if (!new)
		return (1);//pas ca mais free toute la str
	tmp = tok_lstlast(*alst);
	if (tmp)
		tmp->next = new;
	else
		*alst = new;
	return (0);
}

t_tok	*tok_lstlast(t_tok *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

t_tok	*tok_lstnew(char *content)
{
	t_tok	*element;

	element = malloc(sizeof(*element));
	if (!element)
		return (NULL);
	element->content = content;
	element->next = NULL;
	return (element);
}

int	tok_lstsize(t_tok *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	tok_lstclear(t_tok *lst)
{
	t_tok	*tmp;

	if (!lst)
		return ;
	while (lst)
	{
		tmp = lst->next;
		free(lst->content);
		free(lst);
		lst = tmp;
	}
}
