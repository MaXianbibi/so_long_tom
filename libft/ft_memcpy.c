/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparadis <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:00:55 by tparadis          #+#    #+#             */
/*   Updated: 2022/10/23 21:22:38 by tparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t num)
{
	size_t	i;

	i = 0;
	if (!destination && !source)
		return (NULL);
	while (i < num)
	{
		((unsigned char *) destination)[i] = ((unsigned char *) source)[i];
		i++;
	}
	return (destination);
}
