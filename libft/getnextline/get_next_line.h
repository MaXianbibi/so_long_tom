/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparadis <tparadis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 20:21:20 by tparadis          #+#    #+#             */
/*   Updated: 2023/05/26 19:22:25 by tparadis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include "../memory_manager/memory_manager.h"
# define BUFFER_SIZE 0x1000

char	*get_next_line(t_memory_manager *i, int fd);
size_t	gnl_strlen(char *s);
size_t	gnl_strlcpy(char *dst, const char *src, size_t size);
char	*gnl_strjoin(t_memory_manager *inst, const char *s1, const char *s2);
char	*gnl_strdupn(t_memory_manager *inst, char *s, size_t sz);
char	*gnl_realloc(t_memory_manager *inst, char *current, char *buf);

#endif
