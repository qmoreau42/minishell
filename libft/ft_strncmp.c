/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:01:45 by jgautier          #+#    #+#             */
/*   Updated: 2021/12/14 11:32:00 by jgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_b;
	unsigned char	*s2_b;

	s1_b = (unsigned char *)s1;
	s2_b = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (s1_b[i] == s2_b[i] && s1_b[i] != 0 && s2_b[i] != 0 && i < n - 1)
		i++;
	return (s1_b[i] - s2_b[i]);
}
