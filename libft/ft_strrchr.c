/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:41:15 by jgautier          #+#    #+#             */
/*   Updated: 2021/12/13 14:49:20 by jgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	uc;

	i = 0;
	uc = (unsigned char)c;
	while (s[i])
		i++;
	if (s[i] == uc)
		return ((char *)(s + i));
	while (i >= 0)
	{
		if (s[i] == uc)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}
