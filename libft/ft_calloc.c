/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparadis <tparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:42:57 by tparadis          #+#    #+#             */
/*   Updated: 2022/10/26 16:48:03 by tparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*buf;

	if (!num || !size)
		return (ft_calloc(1, 1));
	if (SIZE_MAX / num < size)
		return (NULL);
	buf = malloc(num * size);
	if (!buf)
		return (buf);
	ft_bzero(buf, size * num);
	return (buf);
}
