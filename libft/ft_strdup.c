/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparadis <tparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:57:43 by tparadis          #+#    #+#             */
/*   Updated: 2022/10/22 17:10:20 by tparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	strsz;
	char	*buf;

	strsz = ft_strlen(str);
	buf = malloc(strsz + 1);
	if (!buf)
		return (0);
	ft_strlcpy(buf, str, strsz + 1);
	return (buf);
}
