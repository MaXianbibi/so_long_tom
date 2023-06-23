/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparadis <tparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:06:54 by tparadis          #+#    #+#             */
/*   Updated: 2022/10/26 17:15:23 by tparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	sz;

	sz = ft_strlen(s);
	if (sz < len)
		len = sz;
	ret = malloc(len + 1);
	if (!ret)
		return (NULL);
	if (start > ft_strlen(s))
		start = ft_strlen(s);
	ft_strlcpy(ret, s + start, len + 1);
	return (ret);
}
