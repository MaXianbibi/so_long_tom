/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparadis <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:29:26 by tparadis          #+#    #+#             */
/*   Updated: 2022/11/11 19:29:33 by tparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	put_nbr_base(int base, long long num, int upper, int addr)
{
	char	c;
	int		i;

	i = 0;
	if (num < 0)
	{
		i += write(1, "-", 1);
		num *= -1;
	}
	if (addr)
		i += write(1, "0x", 2);
	if (num / base)
		i += put_nbr_base(base, num / base, upper, 0);
	c = BASE_16L[num % base];
	if (upper)
		c = BASE_16U[num % base];
	i += write(1, &c, 1);
	return (i);
}

static int	put_unbr_base(int base, unsigned long long num, int upper, int addr)
{
	char	c;
	int		i;

	i = 0;
	if (addr)
		i += write(1, "0x", 2);
	if (num / base)
		i += put_unbr_base(base, num / base, upper, 0);
	c = BASE_16L[num % base];
	if (upper)
		c = BASE_16U[num % base];
	i += write(1, &c, 1);
	return (i);
}

static void	print_flags(char c, va_list list, int *count)
{
	size_t		i;

	if (c == 'c')
	{
		c = va_arg(list, int);
		*count += (write(1, &c, 1));
	}
	else if (c == 'i' || c == 'd')
		*count += (put_nbr_base(10, va_arg(list, int), 0, 0));
	else if (c == 'x' || c == 'X')
		*count += (put_unbr_base(16, va_arg(list, unsigned int), c < 'x', 0));
	else if (c == 'p')
		*count += (put_unbr_base(16, va_arg(list, size_t), 0, 1));
	else if (c == 's')
	{
		i = va_arg(list, size_t);
		if (!i)
			*count += (write(1, "(null)", 6));
		while (i && *(char *)i)
			*count += write(1, ((char *)i++), 1);
	}
	else if (c == 'u')
		*count += (put_unbr_base(10, va_arg(list, unsigned int), 0, 0));
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	list;
	int		count;

	i = 0;
	va_start(list, str);
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '%' && ++i)
				count += write(1, "%", 1);
			else
				print_flags(str[++i], list, &count);
		}
		else
			count += write(1, &str[i], 1);
		i++;
	}
	va_end(list);
	return (count);
}
