/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:16:08 by jgautier          #+#    #+#             */
/*   Updated: 2021/12/08 15:58:08 by jgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;
	char	*str_tmp;

	str_tmp = (char *)str;
	i = 0;
	if (to_find[0] == '\0')
		return ((char *)str_tmp);
	while (str[i] && i < n)
	{
		j = 0;
		while (str_tmp[i + j] == to_find[j] && i + j < n)
		{
			if (to_find[j + 1] == '\0')
				return ((char *)(str_tmp + i));
			j++;
		}
		i++;
	}
	return (0);
}
