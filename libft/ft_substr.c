/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:17:21 by jgautier          #+#    #+#             */
/*   Updated: 2021/12/15 14:06:02 by jgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	len_malloc(char const *s, unsigned int start, size_t len)
{
	int	tmp;

	tmp = (int)len;
	if (tmp < 0)
		return (0);
	if ((int)ft_strlen(s) - (int)start < tmp)
		tmp = (int)ft_strlen(s) - (int)start;
	if (tmp < 0)
		tmp = 0;
	return ((size_t)tmp);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	len = len_malloc(s, start, len);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}
