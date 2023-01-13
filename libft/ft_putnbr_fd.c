/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:03:20 by jgautier          #+#    #+#             */
/*   Updated: 2021/12/08 15:19:46 by jgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;

	if (n < 0)
	{
		write(fd, "-", 1);
		nb = (unsigned int)-n;
	}
	else
		nb = (unsigned int)n;
	if (nb < 10)
		ft_putchar_fd(48 + nb, fd);
	else
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putchar_fd(48 + nb % 10, fd);
		nb /= 10;
	}
}
