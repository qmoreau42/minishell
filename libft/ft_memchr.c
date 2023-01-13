/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:27:30 by jgautier          #+#    #+#             */
/*   Updated: 2021/12/12 17:07:39 by jgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	uc;

	i = 0;
	uc = (unsigned char)c;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == uc)
		{
			str = (void *)s + i;
			return (str);
		}
		i++;
	}
	return (NULL);
}
