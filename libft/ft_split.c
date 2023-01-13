/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:18:36 by jgautier          #+#    #+#             */
/*   Updated: 2021/12/14 12:26:10 by jgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	compteur(char const *s, char c, int mode, int i)
{
	int	j;
	int	cpt;

	cpt = 0;
	j = 0;
	if (!mode)
		j = i;
	while (s[j])
	{
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j] != 0)
		{
			if ((mode && j == 0) || (mode && s[j - 1] == c))
				cpt++;
			else if (!mode)
				cpt++;
			j++;
		}
		if (!mode)
			return (cpt);
	}
	return (cpt);
}

static void	*free_malloc(char **tab, int j)
{
	while (j >= 0)
	{
		free(tab[j]);
		j--;
	}
	free(tab);
	return (NULL);
}

static char	**malloc_tabs(char **tab, char const *s, char c)
{
	int	i;
	int	j;
	int	cpt;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		cpt = compteur(s, c, 0, i);
		if (cpt)
		{
			tab[j] = malloc(sizeof(char) * (cpt + 1));
			i += cpt;
			if (!tab[j])
				return (free_malloc(tab, j));
			tab[j][cpt] = '\0';
		}
		j++;
	}
	return (tab);
}

static char	**ft_copy_split(char **tab, char const *s, char c)
{
	int		i;
	int		k;
	int		j;

	i = 0;
	k = 0;
	while (s[k])
	{
		j = 0;
		while (s[k] == c)
			k++;
		while (s[k] != c && s[k])
		{
			tab[i][j] = s[k];
			k++;
			j++;
		}
		i++;
	}
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		cpt;

	if (!s)
		return (NULL);
	cpt = compteur(s, c, 1, 0);
	tab = (char **)malloc(sizeof(*tab) * (cpt + 1));
	if (!(tab))
		return (NULL);
	tab[cpt] = NULL;
	tab = malloc_tabs(tab, s, c);
	if (!(tab))
		return (NULL);
	tab = ft_copy_split(tab, s, c);
	return (tab);
}
