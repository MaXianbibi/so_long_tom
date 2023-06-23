/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparadis <tparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 23:41:15 by tparadis          #+#    #+#             */
/*   Updated: 2022/10/25 16:02:03 by tparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	ft_rputnbr_fd(unsigned int n, int fd)
{
	char	c;

	if (n / 10)
		ft_rputnbr_fd(n / 10, fd);
	c = (n % 10) + 48;
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	n2;

	n2 = n;
	if (n < 0)
	{
		n2 = n * -1;
		write(fd, "-", 1);
	}
	ft_rputnbr_fd(n2, fd);
}
