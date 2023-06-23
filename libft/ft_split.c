/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparadis <tparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:31:37 by tparadis          #+#    #+#             */
/*   Updated: 2022/11/16 20:42:49 by tparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_buf_size(char const *str, char c)
{
	size_t	i;
	size_t	last;
	size_t	result;

	i = 0;
	last = 0;
	result = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			if (i - last > 1 || (!last && i))
				result++;
			last = i;
		}
		i++;
	}
	if (i && last != i - 1)
		result++;
	return (result + 1);
}

static char	*copy_string(const char *s, char c)
{
	char	*next;
	size_t	len;

	next = ft_strchr(s, c);
	if (!next)
		return (ft_strdup(s));
	len = next - s;
	return (ft_substr(s, 0, len));
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**ret;
	int		j;
	int		last;

	if (!s)
		return (NULL);
	ret = malloc(sizeof(char *) * (get_buf_size(s, c)));
	i = 0;
	j = 0;
	last = 0;
	if (!ret)
		return (NULL);
	while (s[i])
	{
		if (((i - last == 0 && !last) || (i - last == 1 && last)
				|| (i - last == 1 && s[last] == c)) && s[i] != c)
			ret[j++] = copy_string(&s[i], c);
		if (s[i] == c)
			last = i;
		i++;
	}
	ret[j] = NULL;
	return (ret);
}
