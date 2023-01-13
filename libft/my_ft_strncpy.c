/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_ft_strncpy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gautier <gautier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:22:13 by gautier           #+#    #+#             */
/*   Updated: 2022/11/09 18:36:26 by gautier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *my_ft_strncpy(char *dest, char *src, int n)
{
    int i;
    int len;

    i = 0;
    if (n > ft_strlen(src))
        len = ft_strlen(src);
    else
        len = n;
    dest = malloc(sizeof(char) * (len + 1));
    while (src[i] && i < n)
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = 0;
    return (dest);
}
