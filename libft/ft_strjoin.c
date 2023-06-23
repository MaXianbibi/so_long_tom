/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparadis <tparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:46:16 by tparadis          #+#    #+#             */
/*   Updated: 2022/10/25 16:04:41 by tparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	sz1;
	size_t	sz2;
	char	*ret;

	if (!s1 || !s2)
		return (NULL);
	sz1 = ft_strlen(s1);
	sz2 = ft_strlen(s2);
	ret = malloc(sizeof(char) * (sz2 + sz1 + 1));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s1, sz1 + 1);
	ft_strlcpy(ret + sz1, s2, sz2 + 1);
	return (ret);
}
