/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparadis <tparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:36:14 by tparadis          #+#    #+#             */
/*   Updated: 2022/10/26 16:50:32 by tparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	get_length(long long int n)
{
	unsigned long long int	max;
	int						i;

	max = 1;
	i = 0;
	if (!n)
		return (1);
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n / max)
	{
		max *= 10;
		i++;
	}
	return (i);
}

static void	fill(char *buf, long long int n, int index)
{
	if (n / 10)
	{
		fill(buf, n / 10, index - 1);
	}
	buf[index] = (n % 10) + 48;
}

char	*ft_itoa(int n)
{
	long long int	o;
	int				i;
	char			*ret;
	int				index;

	i = get_length(n);
	o = n;
	index = 0;
	ret = malloc(i + 1);
	if (!ret)
		return (NULL);
	ret[i] = 0;
	if (n < 0)
	{
		ret[0] = '-';
		o = n;
		o *= -1;
		index++;
	}
	i--;
	fill(ret, o, i);
	return (ret);
}
