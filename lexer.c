/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gautier <gautier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:30:45 by gautier           #+#    #+#             */
/*   Updated: 2022/11/21 22:08:34 by gautier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minish.h"

char    *quote_secur(char *str)
{
    int     i;
    char    *secu;
    char    flag;

    i = 0;
    flag = 0;
    secu = malloc(sizeof(char *) * (ft_strlen(str) + 1));
    if (!secu)
        return (NULL);
    while (str[i])
    {
        if (!flag)
            secu[i] = '0';
        if (flag)
            secu[i] = '1';
        if (flag && (str[i] == flag || str[i] == flag))
            flag = 0;
        else if (!flag && (str[i] == '"' || str[i] == '\047'))
            flag = str[i];
        if (!flag)
            secu[i] = '0';
        i++;
    }
    secu[i] = 0;
    return (secu);
}

