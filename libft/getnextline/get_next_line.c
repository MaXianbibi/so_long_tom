/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparadis <tparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:55:30 by tparadis          #+#    #+#             */
/*   Updated: 2023/05/26 19:21:50 by tparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_string(t_memory_manager *j, char **original, ssize_t retval)
{
	char	*ret;
	char	*temp;
	ssize_t	i;

	i = 0;
	ret = NULL;
	temp = NULL;
	if (retval != -1 && *original && (*original)[0])
	{
		while ((*original)[i] && (*original)[i] != '\n')
			i++;
		if ((*original)[i])
			temp = gnl_strdupn(j, *original + i + 1, gnl_strlen(*original) - i);
		ret = gnl_strdupn(j, *original, i + 2);
		mm_free(j, *original);
		*original = temp;
	}
	else if (*original)
	{
		mm_free(j, *original);
		*original = NULL;
	}
	return (ret);
}

char	*get_next_line(t_memory_manager *j, int fd)
{
	static char	*arr[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	ssize_t		retval;
	int			i;

	i = 0;
	retval = read(fd, buf, BUFFER_SIZE);
	while (retval && retval != -1)
	{
		buf[retval] = 0;
		arr[fd] = gnl_realloc(j, arr[fd], buf);
		while ((arr[fd])[i] && (arr[fd])[i] != '\n')
			i++;
		if ((arr[fd])[i])
			break ;
		else
			retval = read(fd, buf, BUFFER_SIZE);
	}
	return (read_string(j, &arr[fd], retval));
}
