/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 10:14:58 by jgautier          #+#    #+#             */
/*   Updated: 2021/12/14 11:31:38 by jgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static t_list	*ft_lstmap2(t_list *lst, void *(*f)(void *),
			void (del)(void *), t_list *newlst)
{
	t_list	*newelem;

	newelem = ft_lstnew(f(lst->content));
	if (!newelem)
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	newlst = newelem;
	lst = lst->next;
	while (lst)
	{
		newelem = ft_lstnew(f(lst->content));
		if (!newelem)
		{
			ft_lstclear(&newlst, del);
			ft_lstclear(&lst, del);
			break ;
		}
		lst = lst->next;
		ft_lstadd_back(&newlst, newelem);
	}
	return (newlst);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;

	if (!f || !lst)
		return (NULL);
	newlst = NULL;
	newlst = ft_lstmap2(lst, f, del, newlst);
	return (newlst);
}
