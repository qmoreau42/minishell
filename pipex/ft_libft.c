/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgautier <jgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 14:22:28 by jgautier          #+#    #+#             */
/*   Updated: 2022/05/30 17:08:21 by jgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return ;
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	len = i;
	i = 0;
	while (s2[i])
	{
		str[i + len] = s2[i];
		i++;
	}
	str[i + len] = 0;
	return (str);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
