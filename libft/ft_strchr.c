/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparadis <tparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 22:09:37 by tparadis          #+#    #+#             */
/*   Updated: 2022/10/25 16:04:20 by tparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int				i;
	unsigned char	check;

	i = 0;
	check = c;
	while (str[i])
	{
		if (str[i] == check)
			return (((char *)str) + i);
		i++;
	}
	if (str[i] == check)
		return (((char *)str) + i);
	return (NULL);
}
