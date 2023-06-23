/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparadis <tparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:30:03 by tparadis          #+#    #+#             */
/*   Updated: 2022/10/25 15:57:38 by tparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void	*ptr, int value, size_t num)
{
	size_t	i;

	i = -1;
	while (++i < num)
		((unsigned char *) ptr)[i] = (unsigned char) value;
	return (ptr);
}
