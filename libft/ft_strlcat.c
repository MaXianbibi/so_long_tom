/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparadis <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:53:25 by tparadis          #+#    #+#             */
/*   Updated: 2022/10/25 16:05:47 by tparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	index;

	i = 0;
	index = 0;
	while (dest[i] != '\0' && i < size)
		i++;
	while ((src[index]) && ((index + i + 1) < size))
	{
		dest[i + index] = src[index];
		index++;
	}
	if (i != size)
		dest[i + index] = 0;
	return (i + ft_strlen(src));
}
