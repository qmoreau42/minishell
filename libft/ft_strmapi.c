/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:50:20 by jgautier          #+#    #+#             */
/*   Updated: 2021/12/13 12:36:46 by jgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*s_tmp;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
		i++;
	s_tmp = malloc(sizeof(*s_tmp) * (i + 1));
	if (!s_tmp)
		return (NULL);
	s_tmp[i] = 0;
	i = 0;
	while (s[i])
	{
		s_tmp[i] = (*f)((unsigned int)i, s[i]);
		i++;
	}
	return (s_tmp);
}
