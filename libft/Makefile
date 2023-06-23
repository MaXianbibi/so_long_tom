# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tparadis <tparadis@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 15:10:32 by tparadis          #+#    #+#              #
#    Updated: 2023/05/27 20:06:04 by tparadis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS  = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
		ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c \
		ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
		ft_tolower.c ft_toupper.c ft_substr.c ft_strjoin.c ft_strtrim.c \
		ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c printf/ft_printf.c getnextline/get_next_line.c getnextline/get_next_line_utils.c ft_freesplit.c \
		memory_manager/mm_alloc.c memory_manager/mm_core.c memory_manager/mm_exit.c memory_manager/mm_node_manager.c memory_manager/mm_utils.c

SRCSB = ft_lstadd_front.c ft_lstclear.c ft_lstmap.c ft_lstlast.c ft_lstsize.c \
		ft_lstnew.c ft_lstadd_back.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c \

OBJSB = ${SRCSB:.c=.o}

OBJS   = ${SRCS:.c=.o}

NAME   = libft.a

CC     = gcc

CFLAGS = -Wall -Wextra -Werror

all    : ${NAME}

${NAME}: ${OBJS} ${OBJSB}
				@ar -rcs  ${NAME} ${OBJS} ${OBJSB}

clean  :  
				@rm -f ${OBJS} ${OBJSB}

fclean : clean
				@rm -f ${NAME}

re     : fclean all

bonus : ${OBJSB}
				@ar -rcs  ${NAME} ${OBJSB}
