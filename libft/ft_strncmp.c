/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparadis <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 23:08:45 by tparadis          #+#    #+#             */
/*   Updated: 2022/10/26 16:53:17 by tparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t num)
{
	size_t	i;

	i = 0;
	if (!num)
		return (0);
	while ((unsigned char) str1[i] == (unsigned char)str2[i]
		&& str1[i] && str2[i] && i < num - 1)
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
