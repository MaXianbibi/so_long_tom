/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparadis <tparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:43:48 by tparadis          #+#    #+#             */
/*   Updated: 2022/10/30 19:07:39 by tparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t num)
{
	size_t	i;

	i = num - 1;
	if (!destination && !source)
		return (NULL);
	if (source > destination)
	{
		ft_memcpy(destination, source, num);
		return (destination);
	}
	while (i != -1ull)
	{
		((unsigned char *)destination)[i] = ((unsigned char *) source)[i];
		i--;
	}
	return (destination);
}
